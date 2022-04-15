# Custom C and C++ modules for micropython

## prerequisites

- Raspberry Pi Pico, C/C++ SDK and toolchain
- micropython source tree
- python enviroment with [requirements.txt](requirements.txt) installed

## dynamic

Compiles C into an mpy file that can be loaded dynamically (without recompiling micropython)

NB micropython dynruntime.mk has been altered as per here: https://forums.raspberrypi.com/viewtopic.php?f=146&t=310282&p=1856106#p1856106

`armv7m` arch now targets `cortex-m0plus` cpu (previously `cortex-m3`)

See `py/dynruntime.h`

In the dynamic subdir, just do

```sh
make
```

The resulting mpy binary file can be uploaded to a device running micropython (e.g. using `rshell`) and imported like any other module:

```txt
$ rshell
Connecting to /dev/ttyACM0 (buffer-size 512)...
Trying to connect to REPL  connected
Retrieving sysname ... rp2
Testing if sys.stdin.buffer exists ... Y
Retrieving root directories ... /echo.py/ /main.py/ /rainbow.py/ /thermometer.py/
Setting time ... Apr 15, 2022 20:37:17
Evaluating board_name ... pyboard
Retrieving time epoch ... Jan 01, 1970
Welcome to rshell. Use Control-D (or the exit command) to exit rshell.
/mnt/data/dev/rpi-pico/pico-c-pymodules/dynamic> cp string.mpy /pyboard
Copying '/mnt/data/dev/rpi-pico/pico-c-pymodules/dynamic/string.mpy' to '/pyboard/string.mpy' ...
/mnt/data/dev/rpi-pico/pico-c-pymodules/dynamic> repl
Entering REPL. Use Control-X to exit.
>
MicroPython v1.18-329-g9d7c168bf-dirty on 2022-04-15; Raspberry Pi Pico with RP2040
Type "help()" for more information.
>>>
>>> import string
>>> string.reverse("reverse")
'esrever'
>>>
```

## static

Requires recompilation of micropython. Supports C++. Based on micropython/examples/usercmodule.

From the micropython repo root (adjust path as necessary):

```sh
cd ports/rp2/
cmake -S . -B build-PICO -DPICO_BUILD_DOCS=0 -DUSER_C_MODULES=../../../pico-c-pymodules/static/micropython.cmake -DMICROPY_BOARD=PICO
cmake --build build-PICO -j
```

Copy the micropython image onto the device, e.g.

```sh
cp build-PICO/firmware.uf2 /media/$USER/RPI-RP2/
```

Then

```
$ rshell
Connecting to /dev/ttyACM0 (buffer-size 512)...
Trying to connect to REPL  connected
Retrieving sysname ... rp2
Testing if sys.stdin.buffer exists ... Y
Retrieving root directories ... /echo.py/ /main.py/ /rainbow.py/ /string.mpy/ /thermometer.py/
Setting time ... Apr 15, 2022 20:58:31
Evaluating board_name ... pyboard
Retrieving time epoch ... Jan 01, 1970
Welcome to rshell. Use Control-D (or the exit command) to exit rshell.
/mnt/data/dev/rpi-pico/pico-c-pymodules> repl
Entering REPL. Use Control-X to exit.
>
MicroPython v1.18-329-g9d7c168bf-dirty on 2022-04-15; Raspberry Pi Pico with RP2040
Type "help()" for more information.
>>> import usermodule
>>> usermodule.add(2, 2)
(4, 'usermodule_cpp')
>>>
```