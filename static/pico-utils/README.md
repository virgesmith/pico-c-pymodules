# pico module

rp2040/pico device-specific functionality.

- `id` returns the device's unique 8-byte id

```py
>>> import pico
>>> id=pico.id()
>>> id
b'\xe6`D0CNZ+'
>>> import binascii
>>> binascii.hexlify(id)
b'e6604430434e5a2b'
>>> int.from_bytes(id, 0)
16600343200565975595
```

- `board_led` switches the on-board LED on/off

```
>>> import pico
>>> pico.board_led(True)
>>> pico.board_led(False)
```