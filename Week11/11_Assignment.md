## Week11 Assignment

> measure something: add a sensor to a microcontroller board that you have designed and read it

### A light board

![](http://7xjpra.com1.z0.glb.clouddn.com/hello.light.45.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/week11mylightboard.jpeg)

Then download [hello.light.45.c](http://academy.cba.mit.edu/classes/input_devices/light/hello.light.45.c) and [makefile](http://academy.cba.mit.edu/classes/input_devices/light/hello.light.45.make). cd into the folder in terminal, give it this command: ``make -f hello.light.45.make``


it responds

```

avr-gcc -mmcu=attiny45 -Wall -Os -DF_CPU=8000000 -I./ -o hello.button.45.out hello.button.45.c
avr-objcopy -O ihex hello.button.45.out hello.button.45.c.hex;\
	avr-size --mcu=attiny45 --format=avr hello.button.45.out
AVR Memory Usage
----------------
Device: attiny45

Program:     364 bytes (8.9% Full)
(.text + .data + .bootloader)

Data:          0 bytes (0.0% Full)
(.data + .bss + .noinit)
```
Next command ``sudo make -f hello.light.45.make program-usbtiny``

It responds:

```
avr-objcopy -O ihex hello.light.45.out hello.light.45.c.hex;\
	avr-size --mcu=attiny45 --format=avr hello.light.45.out
AVR Memory Usage
----------------
Device: attiny45

Program:     502 bytes (12.3% Full)
(.text + .data + .bootloader)

Data:          1 bytes (0.4% Full)
(.data + .bss + .noinit)


avrdude -p t45 -P usb -c usbtiny -U flash:w:hello.light.45.c.hex

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e9206
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file "hello.light.45.c.hex"
avrdude: input file hello.light.45.c.hex auto detected as Intel Hex
avrdude: writing flash (502 bytes):

Writing | ################################################## | 100% 0.74s

avrdude: 502 bytes of flash written
avrdude: verifying flash memory against hello.light.45.c.hex:
avrdude: load data flash data from input file hello.light.45.c.hex:
avrdude: input file hello.light.45.c.hex auto detected as Intel Hex
avrdude: input file hello.light.45.c.hex contains 502 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.94s

avrdude: verifying ...
avrdude: 502 bytes of flash verified
```
Then download [hello.light.45.py](http://academy.cba.mit.edu/classes/input_devices/light/hello.light.45.py).

Connet my board with USB to TTl

### A switch board

![](http://7xjpra.com1.z0.glb.clouddn.com/hello.button.45.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/week11myswitchboard.jpeg)

Then download [hello.button.45.c](http://academy.cba.mit.edu/classes/input_devices/button/hello.button.45.c) and [makefile](http://academy.cba.mit.edu/classes/input_devices/button/hello.button.45.make). cd into the folder in terminal, give it this command: ``make -f hello.button.45.make``


it responds

```

avr-gcc -mmcu=attiny45 -Wall -Os -DF_CPU=8000000 -I./ -o hello.button.45.out hello.button.45.c
avr-objcopy -O ihex hello.button.45.out hello.button.45.c.hex;\
	avr-size --mcu=attiny45 --format=avr hello.button.45.out
AVR Memory Usage
----------------
Device: attiny45

Program:     364 bytes (8.9% Full)
(.text + .data + .bootloader)

Data:          0 bytes (0.0% Full)
(.data + .bss + .noinit)
```
Next command ``sudo make -f hello.button.45.make program-usbtiny``

``avrdude: initialization failed``, something wrong with my board.


### A temperature board

I made a board with a temperature sensor:

![](http://7xjpra.com1.z0.glb.clouddn.com/hello.temp.45.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/week11mytempboard.jpeg)

Then download [hello.temp.45.c](http://academy.cba.mit.edu/classes/input_devices/temp/hello.temp.45.c) and [makefile](http://academy.cba.mit.edu/classes/input_devices/temp/hello.temp.45.make). cd into the folder in terminal, give it this command: ``make -f hello.temp.45.make``

it responds

```
avr-gcc -mmcu=attiny45 -Wall -Os -DF_CPU=8000000 -I./ -o hello.temp.45.out hello.temp.45.c
avr-objcopy -O ihex hello.temp.45.out hello.temp.45.c.hex;\
	avr-size --mcu=attiny45 --format=avr hello.temp.45.out
AVR Memory Usage
----------------
Device: attiny45

Program:     504 bytes (12.3% Full)
(.text + .data + .bootloader)

Data:          1 bytes (0.4% Full)
(.data + .bss + .noinit)

```

Next command ``sudo make -f hello.temp.45.make program-usbtiny``

``avrdude: initialization failed``, something wrong with my board.