---
title: Final project - Mini SoundBot
date: 2016-01-29 11:35:19
---

# Final project - Mini SoundBot

![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DVideoTitle1.jpg)

### Idea

In the very beginning, I planned to make a [Theremin](https://en.wikipedia.org/wiki/Theremin). It's an early electronic musical instrument controlled without physical contact by the thereminist.


![](http://cnet1.cbsistatic.com/hub/i/r/2013/11/02/a0d46b02-6de8-11e3-913e-14feb5ca9861/resize/570xauto/d9feb99e1358983a3e909096ea0aca72/01_UM_Project___Odd_Harmonics___LR.jpg)

But I was stucked by the osillators and complicated circut. 

![](http://farm4.staticflickr.com/3739/9533739769_8714d81f89.jpg)

![](http://7xjpra.com1.z0.glb.clouddn.com/opentheremin_place_v2_web.png)

So I simplified it to a signal-note converter -- I call it SoundBot.

If you wave or move hands in front of the Soundbot, it’ll convert the distance between your hand and the sensor into music notes. You can play a song with your hand but without touching anything. It's like touchless instrument.

![](http://7xjpra.com1.z0.glb.clouddn.com/projectsketch.jpeg)

### Plan
Like everyweek, I felt time presure. To use my spare time wisely, I made a project schedule to help myself concentrate on key tasks:

Task| Schedule | Outcome
--- | --- | ---
Study theremin principls | 6.9-6.11 | understanding the basic principle
Coding | 6.12-6.18 | Program works ok with arduino
Design schematic in eagle | 6.12 | PCB design
Design board in eagle | 6.13 | PCB design
Buy components | 6.15 | Taobao order
Design housing parts | 6.13-6.15 | Fusion 360 design file
Mill the borad | 6.18 | Circuit board
Soldering | 6.18 | Circuit board
Test input & output part | 6.19 | All parts work properly
Making housing parts | 6.18-6.19 | Laser cut & 3D print parts
Assemble | 6.19 | Wind up everything together
Test | 6.20-6.21 | Final test and prepare for presentation

### Process

#### 1. Project blueprint

**Input** : I use an Ultrasonic Ranging Module HC-SR04 which detects the distance.

![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DHC-SR04.jpeg)

**Output**: At first, I've tried to use speaker like this, but it sounds a little wierd. 

![](http://7xjpra.com1.z0.glb.clouddn.com/tryspeaker.jpeg)

So I decided to use macbook as output device, my program can synthesize signal into piano-like notes:

![](http://7xjpra.com1.z0.glb.clouddn.com/SoundBotPrinciple.png)

#### 2. Coding

To use my laptop as an output, I find an open source C++ toolkit for creative coding which named [openFrameworks](http://openframeworks.cc/). It helps me simplify audio processing work.

![](http://openframeworks.cc/assets/images/of-logo.svg)

[OpenFrameworks download](http://openframeworks.cc/download/) and [setup guide for xcode](http://openframeworks.cc/setup/xcode)

And I use one of openFrameworks addon - [micknoise/Maximilian: C++ Audio and Music DSP Library](https://github.com/micknoise/Maximilian). It is an audio synthesis and signal processing library written in C++. Via it's help, my program converts the sensor signals into music notes:

![](http://7xjpra.com1.z0.glb.clouddn.com/Piano%20key%20frequencies.jpg)

![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DCoding1.png)

You can [downloan my code here](https://app.box.com/s/2u0u5edkp2lq25wybits4h9py3ofc27c).

Before making the board myself, I used Arduino for test:

![](http://7xjpra.com1.z0.glb.clouddn.com/fabfinalroute.jpg)

Hello world test:

https://youtu.be/4Pd2nPjEf1U

#### 3. Design PCB

Since the converting job is mostly done by the program, my circuit board could be relatively simple.

![](http://7xjpra.com1.z0.glb.clouddn.com/fabfinal-sch.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/fabfinal-brd.png)

You can [downloan my eagle file here](https://app.box.com/s/xgrrxwjk7gm3kme4f4hb4g5zpao65ebf).

#### 4. Make the board

I use RSM-20 to mill the board as usual and solder the components.

![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DMillTheBoard.jpg)

make the board by ``sudo make -f hello.HC-SR04.make program-usbtiny``


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

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1466488357.jpeg)


#### 5. Housing

The sonar sensor looks quite like a robot eye, so I can make a Wall-E housing for it. I design in Fusion 360 and it's fun.

![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DHousingDesign5.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/fabfinalfusion360.png)

Then export to dxf file and inport in Coraldraw, send to GCC Laser Pro. I use speed 2.7 and power 100:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1466488363.jpeg)

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1466488360.jpeg)

Assembly

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1466488383.jpeg)

Also some 3D pringting parts.

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467437187.jpeg)

You can [downloan my design and cut file here](https://app.box.com/s/4j8cctfn2omfg8200gs7zsmwcjqbr7f5).


### Test

Everything seems ready. Time for testing!

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1466488388.jpeg)

[Test video for UI when playing](https://youtu.be/j0c7WXlgJfw)


![](http://7xjpra.com1.z0.glb.clouddn.com/%5BFabFinal%5DVideoTitle1.jpg)

I found a bit hard to find the right note when I move my hand back and forth. There's still refinement to be made in my program.



And here's my final project presentation:

Slide:

![](http://7xjpra.com1.z0.glb.clouddn.com/presentation.png)

Video:

[Mini SoundBot - Youtube](https://youtu.be/PgKtiaQ3u-M)

[Mini SoundBot - Vimeo](https://vimeo.com/171525141)

## References


Block diagram of theremin. Volume control in blue, pitch control in yellow and audio output in red.

![](https://upload.wikimedia.org/wikipedia/commons/c/cb/Block_diagram_Theremin.png)

- [Theremin - Wikipedia, the free encyclopedia](https://en.wikipedia.org/wiki/Theremin)
- [Build your own real theremin](http://www.gaudi.ch/OpenTheremin/)
- [Theremin ](http://www.strangeapparatus.com/Theremin.html)
- [How to Build & Play a Theremin](http://www.ehow.com/videos-on_5309_build-play-theremin.html)
- [How to Make a Theremin](http://www.wikihow.com/Make-a-Theremin)
- [Multimedia applications of the system Theremino](http://www.theremino.com/en/blog/multimedia)
- [FINALLY, A MODERN THEREMIN](http://hackaday.com/2016/01/24/finally-a-modern-theremin/)
- [Open.Theremin.UNO Housing](http://www.gaudi.ch/OpenTheremin/index.php?option=com_content&view=article&id=99&Itemid=94)
- [Ultrasonic Theremin - All](http://www.instructables.com/id/Ultrasonic-Theremin/)
- [openFrameworks](http://openframeworks.cc/)
- [micknoise/Maximilian: C++ Audio and Music DSP Library](https://github.com/micknoise/Maximilian)