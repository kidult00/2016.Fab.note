## Week15 Assignment

> design and build a wired &/or wireless network connecting at least two processors

In this week we learned about connecting different boards together to do something. 

### Board Design

I make two boards. One as bridge:

![](http://7xjpra.com1.z0.glb.clouddn.com/fabWeek15bridge.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/fabweek15-bridge-brd.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/bridge-trace.png)

One as node:
 
![](http://7xjpra.com1.z0.glb.clouddn.com/fabWeek15node.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/fabweek15-node-brd.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/node-trace.png)

You can [download my eagle board design and milling files here]().


### Make the board

I use Roland SMR-20 to mill my board.

In fabmodules, I set the input png dpi to 1500 and calculate the milling path. 1/64 endmill for traces and 1/32 endmill for interior.

![](http://7xjpra.com1.z0.glb.clouddn.com/week15milling.jpeg)

Soldering the components:

![](http://7xjpra.com1.z0.glb.clouddn.com/week15soldering.jpeg)

Then make the boards:

``make -f hello.bus.45.make``

``sudo make -f hello.bus.45.make program-usbtiny``


```
avr-objcopy -O ihex hello.bus.45.out hello.bus.45.c.hex;\
	avr-size --mcu=attiny45 --format=avr hello.bus.45.out
AVR Memory Usage
----------------
Device: attiny45

Program:     768 bytes (18.8% Full)
(.text + .data + .bootloader)

Data:          4 bytes (1.6% Full)
(.data + .bss + .noinit)


avrdude -p t45 -P usb -c usbtiny -U flash:w:hello.bus.45.c.hex

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.01s

avrdude: Device signature = 0x1e9206
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file "hello.bus.45.c.hex"
avrdude: input file hello.bus.45.c.hex auto detected as Intel Hex
avrdude: writing flash (768 bytes):

Writing | ################################################## | 100% 1.07s

avrdude: 768 bytes of flash written
avrdude: verifying flash memory against hello.bus.45.c.hex:
avrdude: load data flash data from input file hello.bus.45.c.hex:
avrdude: input file hello.bus.45.c.hex auto detected as Intel Hex
avrdude: input file hello.bus.45.c.hex contains 768 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 1.48s

avrdude: verifying ...
avrdude: 768 bytes of flash verified

avrdude: safemode: Fuses OK (H:FF, E:DF, L:62)

avrdude done.  Thank you.
```

### Program

I ran term.py in terminal:

``python term.py /dev/tty.usbserial-A400gwhT 9600``

You can [download the code here](https://app.box.com/s/5wzbvgpsmuqsy420a5zp691ez4cy8nce).

And the led on the boards turn on according to the keyboard signals:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1465569383.jpeg)

[Video](https://youtu.be/t6y-v9ZCXDY)