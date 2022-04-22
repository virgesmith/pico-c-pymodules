

#include "pico-utils.h"
#include "py/runtime.h"


// entry point does type conversions and calls C++ implementation
mp_obj_t id_py()
{
    return mp_obj_new_bytes(id(), 8);
}

mp_obj_t board_led_py(mp_obj_t onoff_obj)
{
    bool onoff = mp_obj_is_true(onoff_obj);
    onboard_led(onoff);
    return mp_const_none;
}


// Define a Python reference to the function we'll make available.
// See example.cpp for the definition.
STATIC MP_DEFINE_CONST_FUN_OBJ_0(id_py_obj, id_py);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(board_led_py_obj, board_led_py);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).
STATIC const mp_rom_map_elem_t pico_usermod_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_pico) },
    { MP_ROM_QSTR(MP_QSTR_id), MP_ROM_PTR(&id_py_obj) },
    { MP_ROM_QSTR(MP_QSTR_board_led), MP_ROM_PTR(&board_led_py_obj) },
};
STATIC MP_DEFINE_CONST_DICT(pico_module_globals, pico_usermod_globals_table);

// Define module object.
const mp_obj_module_t pico_user_cppmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&pico_module_globals
};

// Register the module to make it available in Python.
// Note: the "1" in the third argument means this module is always enabled.
// This "1" can be optionally replaced with a macro like MODULE_CPPEXAMPLE_ENABLED
// which can then be used to conditionally enable this module.
MP_REGISTER_MODULE(MP_QSTR_pico, pico_user_cppmodule, 1);
