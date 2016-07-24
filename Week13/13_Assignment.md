## Week13 Assignment

> add an output device to a microcontroller board you've designed and program it to do something

This week we learn about output components. I made a board with attiny45 as microcontroller and a led.

### Board design

The schematic:

![](http://7xjpra.com1.z0.glb.clouddn.com/week13-eagle-sch.png)

The board:

![](http://7xjpra.com1.z0.glb.clouddn.com/week13-eagle-brd.png)

Check with ERC and DRC. I set 16mil for clearance to avoid milling problem

![](http://7xjpra.com1.z0.glb.clouddn.com/setDRCclearance.png)

Then export the board to monochrome png file (I use 800 dpi resolution) for milling:

![](http://7xjpra.com1.z0.glb.clouddn.com/output-trace.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/output-outline.png)

You can [download the eagle sch & brd & png files here](http://archive.fabacademy.org/archives/2016/fablabshenzhen/students/417/uploads/Week13-OutputEagleFiles.zip).

### Make the board

I use Roland SMR-20 to mill my board.

In fabmodules, I set the input png dpi to 1500 and calculate the milling path:

![](http://7xjpra.com1.z0.glb.clouddn.com/week13fabmodule.png)

1/64 endmill for traces and 1/32 endmill for interior:

![](http://7xjpra.com1.z0.glb.clouddn.com/week13milledboard.jpeg)

Soldering the components:

![](http://7xjpra.com1.z0.glb.clouddn.com/week13soderedboard.jpeg)

Then make the board:

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

### Programming

I use Arduino to program the board to do something.

Don't forget to set board type and choose the right processor. And pay attention to the clock setting. Attiny45 uses 8 MHz internal clock.

![](http://7xjpra.com1.z0.glb.clouddn.com/arduinosetting8m.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/week13-Arduino.png)

Below is my code and you can [download them here](http://archive.fabacademy.org/archives/2016/fablabshenzhen/students/417/uploads/Week13-MyRGB.ino).

``` 
int led1 = 1;           // the PWM pin the LED is attached to
int led2 = 2;
int led3 = 0;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 1,2,3 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 1,2,3:
  analogWrite(led1, brightness);
  analogWrite(led2, brightness);
  analogWrite(led3, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

```
Then Burn Bootloader and upload the program to my board.

The LED on the board fades:

![](http://7xjpra.com1.z0.glb.clouddn.com/week13final.png)

[Video](https://youtu.be/Comn24MekQg)

