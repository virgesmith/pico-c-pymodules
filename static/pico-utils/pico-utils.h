#pragma once

#ifdef __cplusplus
extern "C" {
#else
#include "py/runtime.h" // for bool
#endif

const unsigned char* id();

void onboard_led(bool onoff);

#ifdef __cplusplus
}
#endif
