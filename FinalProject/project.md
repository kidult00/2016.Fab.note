---
title: Final project - Mini SoundBot
date: 2016-01-29 11:35:19
---

![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DVideoTitle1.jpg)

### Idea

Wave or move hands in front of the Soundbot, it’ll convert the distance into music notes.

![](http://7xjpra.com1.z0.glb.clouddn.com/projectsketch.jpeg)



### Input

Ultrasonic Ranging Module HC - SR04

![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DHC-SR04.jpeg)

### Output

I've tried to use speaker like this, but it sounds a little wierd. 

So I decided to use macbook as output device,
my program can synthesize signal into piano-like notes:

![](http://7xjpra.com1.z0.glb.clouddn.com/SoundBotPrinciple.png)

### Make the board

![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DMillTheBoard.jpg)

``sudo make -f hello.HC-SR04.make program-usbtiny``

```
avr-objcopy -O ihex hello.HC-SR04.out hello.HC-SR04.c.hex;\
	avr-size --mcu=attiny45 --format=avr hello.HC-SR04.out
AVR Memory Usage
----------------
Device: attiny45

Program:     526 bytes (12.8% Full)
(.text + .data + .bootloader)

Data:          2 bytes (0.8% Full)
(.data + .bss + .noinit)


avrdude -p t45 -P usb -c usbtiny -U flash:w:hello.HC-SR04.c.hex

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e9206
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file "hello.HC-SR04.c.hex"
avrdude: input file hello.HC-SR04.c.hex auto detected as Intel Hex
avrdude: writing flash (526 bytes):

Writing | ################################################## | 100% 0.92s

avrdude: 526 bytes of flash written
avrdude: verifying flash memory against hello.HC-SR04.c.hex:
avrdude: load data flash data from input file hello.HC-SR04.c.hex:
avrdude: input file hello.HC-SR04.c.hex auto detected as Intel Hex
avrdude: input file hello.HC-SR04.c.hex contains 526 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 1.11s

avrdude: verifying ...
avrdude: 526 bytes of flash verified

avrdude: safemode: Fuses OK (H:FF, E:DF, L:62)

avrdude done.  Thank you.
```

### Programming

OpenFrameworks

[OpenFrameworks download](http://openframeworks.cc/download/)

[setup guide for xcode](http://openframeworks.cc/setup/xcode)

[micknoise/Maximilian: C++ Audio and Music DSP Library](https://github.com/micknoise/Maximilian)

![](http://7xjpra.com1.z0.glb.clouddn.com/Piano%20key%20frequencies.jpg)


### Housing

Design

![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DHousingDesign5.png)

Fusion360 → dxf → Coraldraw → GCC Laser Pro

Laser cut

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1466488360.jpeg)

Assembly

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1466488383.jpeg)

### Test

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1466488388.jpeg)

## Ref

![](http://www.carolinaeyck.com/media/portraits/CarolinaPlaying1211.jpg?t=1453258367)

Hope that will be fun!

![](http://cnet1.cbsistatic.com/hub/i/r/2013/11/02/a0d46b02-6de8-11e3-913e-14feb5ca9861/resize/570xauto/d9feb99e1358983a3e909096ea0aca72/01_UM_Project___Odd_Harmonics___LR.jpg)

I'm interested in making a [Theremin](https://en.wikipedia.org/wiki/Theremin). It's an early electronic musical instrument controlled without physical contact by the thereminist


Principle

利用两个感应人体与大地的分布电容的LC 振荡器工作单元分别产生震荡的频率与大小变化而工作.

![](http://farm4.staticflickr.com/3739/9533739769_8714d81f89.jpg)

Here's block diagram of a theremin. Volume control in blue, pitch control in yellow and audio output in red.

![](https://upload.wikimedia.org/wikipedia/commons/c/cb/Block_diagram_Theremin.png)