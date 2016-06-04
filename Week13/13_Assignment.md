## Week13 Assignment

> add an output device to a microcontroller board you've designed and program it to do something

I made a board with a led:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1465006924.jpeg)


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

Then use Arduino to program.

![](http://7xjpra.com1.z0.glb.clouddn.com/arduinosetting8m.png)

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

The led on the board fade:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1464706428.jpeg)

Video

{% youtube 5OG0FoqRrLI %}