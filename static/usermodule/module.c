
#include "example.h"

#include "py/runtime.h"


// entry point does type conversions and calls C++ implementation
mp_obj_t add_py(mp_obj_t a_obj, mp_obj_t b_obj)
{
    int a = mp_obj_get_int(a_obj);
    int b = mp_obj_get_int(b_obj);
    int sum = add(a, b);
    // Prove we're being scanned for QSTRs.
    mp_obj_t tup[] = {mp_obj_new_int(sum), MP_ROM_QSTR(MP_QSTR_usermodule_cpp)};
    return mp_obj_new_tuple(2, tup);
}


// Define a Python reference to the function we'll make available.
// See example.cpp for the definition.
STATIC MP_DEFINE_CONST_FUN_OBJ_2(add_py_obj, add_py);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t usermodule_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_usermodule) },
    { MP_ROM_QSTR(MP_QSTR_add), MP_ROM_PTR(&add_py_obj) },
};
STATIC MP_DEFINE_CONST_DICT(usermodule_module_globals, usermodule_globals_table);

// Define module object.
const mp_obj_module_t usermodule_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&usermodule_module_globals,
};


// Register the module to make it available in Python.
// Note: the "1" in the third argument means this module is always enabled.
// This "1" can be optionally replaced with a macro like MODULE_CPPEXAMPLE_ENABLED
// which can then be used to conditionally enable this module.
MP_REGISTER_MODULE(MP_QSTR_usermodule, usermodule_user_cmodule, 1);
