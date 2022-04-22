# This top-level micropython.cmake is responsible for listing
# the individual modules we want to include.
# Paths are absolute, and ${CMAKE_CURRENT_LIST_DIR} can be
# used to prefix subdirectories.

# pimoroni stuff: uncomment if necess
include(${CMAKE_CURRENT_LIST_DIR}/../../pimoroni-pico/micropython/modules/micropython.cmake)

# Add the C++ module(s)
#include(${CMAKE_CURRENT_LIST_DIR}/usermodule/micropython.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/pico-utils/micropython.cmake)


