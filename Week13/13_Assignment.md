## Week13 Assignment

> add an output device to a microcontroller board you've designed and program it to do something

``make -f hello.RGB.45.make``

``sudo make -f hello.RGB.45.make program-usbtiny``

```
avr-objcopy -O ihex hello.RGB.45.out hello.RGB.45.c.hex;\
	avr-size --mcu=attiny45 --format=avr hello.RGB.45.out
AVR Memory Usage
----------------
Device: attiny45

Program:     338 bytes (8.3% Full)
(.text + .data + .bootloader)

Data:          0 bytes (0.0% Full)
(.data + .bss + .noinit)


avrdude -p t45 -P usb -c usbtiny -U flash:w:hello.RGB.45.c.hex

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.01s

avrdude: Device signature = 0x1e9206
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file "hello.RGB.45.c.hex"
avrdude: input file hello.RGB.45.c.hex auto detected as Intel Hex
avrdude: writing flash (338 bytes):

Writing | ################################################## | 100% 0.49s

avrdude: 338 bytes of flash written
avrdude: verifying flash memory against hello.RGB.45.c.hex:
avrdude: load data flash data from input file hello.RGB.45.c.hex:
avrdude: input file hello.RGB.45.c.hex auto detected as Intel Hex
avrdude: input file hello.RGB.45.c.hex contains 338 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.72s

avrdude: verifying ...
avrdude: 338 bytes of flash verified

avrdude: safemode: Fuses OK (H:FF, E:DF, L:62)

avrdude done.  Thank you.
```