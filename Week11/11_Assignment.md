## Week11 Assignment

> measure something: add a sensor to a microcontroller board that you have designed and read it

In my assignment, I use Attiny45. It's necessary to figure out the pin number before board design:

![](http://7xjpra.com1.z0.glb.clouddn.com/attiny45.jpg)

### Design the board

The schematic:

![](http://7xjpra.com1.z0.glb.clouddn.com/week11-eagle-sch.png)

The board:

![](http://7xjpra.com1.z0.glb.clouddn.com/week11-eagle-brd.png)

Check with ERC and DRC. I set 16mil for clearance to avoid milling problem

![](http://7xjpra.com1.z0.glb.clouddn.com/setDRCclearance.png)

Then export the board to monochrome png file (I use 800 dpi resolution) for milling:

![](http://7xjpra.com1.z0.glb.clouddn.com/input-trace.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/input-outline.png)

You can [download the eagle sch & brd & png files here](http://archive.fabacademy.org/archives/2016/fablabshenzhen/students/417/uploads/Week15EagleFiles.zip).

### Make the board


I use Roland SMR-20 to mill my board.

In fabmodules, I set the input png dpi to 1500 and calculate the milling path:

![](http://7xjpra.com1.z0.glb.clouddn.com/week11-fabmodule.png)

1/64 endmill for traces and 1/32 endmill for interior.

After soldering:

![](http://7xjpra.com1.z0.glb.clouddn.com/wee11-board.jpeg)

### Program

I use Arduino to program the board to do something.

Don't forget to set board type and choose the right processor. And pay attention to the clock setting. Attiny45 uses 8 MHz internal clock.

![](http://7xjpra.com1.z0.glb.clouddn.com/arduinosetting8m.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/week11-arduino.png)

Below is my code and you can [download them here](http://archive.fabacademy.org/archives/2016/fablabshenzhen/students/417/uploads/Week11-code-myinput.ino).


```

  // set pin numbers:
const int buttonPin = 3;     // the number of the pushbutton pin
const int ledPin =  4;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
```

In this case, the phototransitor works as a button. It turns the LED on and off:

![](http://7xjpra.com1.z0.glb.clouddn.com/week11-on.jpeg)

![](http://7xjpra.com1.z0.glb.clouddn.com/week11-off.jpeg)

### A light board

I made a board with a light sensor:

![](http://7xjpra.com1.z0.glb.clouddn.com/hello.light.45.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/week11mylightboard.jpeg)

Then download [hello.light.45.c](http://academy.cba.mit.edu/classes/input_devices/light/hello.light.45.c) and [makefile](http://academy.cba.mit.edu/classes/input_devices/light/hello.light.45.make). cd into the folder in terminal, run make command: ``make -f hello.light.45.make``


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

Next command: ``sudo make -f hello.light.45.make program-usbtiny`` to make the board.

Then download [hello.light.45.py](http://academy.cba.mit.edu/classes/input_devices/light/hello.light.45.py).

Connet my board with USB to TTL and run:

``python hello.light.45.py /dev/ttyUSB0``

It responds:

```
Traceback (most recent call last):
  File "hello.light.45.py", line 62, in <module>
    ser = serial.Serial(port,9600)
  File "/Library/Python/2.7/site-packages/serial/serialutil.py", line 180, in __init__
    self.open()
  File "/Library/Python/2.7/site-packages/serial/serialposix.py", line 294, in open
    raise SerialException(msg.errno, "could not open port %s: %s" % (self._port, msg))
serial.serialutil.SerialException: [Errno 2] could not open port /dev/ttyUSB0: [Errno 2] No such file or directory: '/dev/ttyUSB0'
```

I google this problem: [Failed to open port /dev/ttyUSB0 - ROS Answers: Open Source Q&A Forum](http://answers.ros.org/question/41275/failed-to-open-port-devttyusb0/)

My classmate told me that maybe because I didn't have FTDI drive. 

I use this command to check my port ``ls /dev/tty*``. There's no /dev/tty.usbserial-A400gwhT exist.

So I tried install [D2XX Direct Drivers](http://www.ftdichip.com/Drivers/D2XX.htm) and [Virtual COM Port Drivers](http://www.ftdichip.com/Drivers/VCP.htm). Still didn't work.

Then I google this article [How to Install FTDI Drivers - learn.sparkfun.com](https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers/all#mac) and reinstall the drive. After restarting the computer, I plug FTDI2USB device,  /dev/tty.usbserial-A400gwhT appeared in the list.

Next, I tried to open py file with this command:

``python hello.light.45.py /dev/tty.usbserial-A400gwhT 9600``

Still got something wrong:

``command line: hello.light.45.py serial_port``

I looked into the python program, and figured out to change the len(sys.argv) from 2 to 3:

```
if (len(sys.argv) != 3):
   print "command line: hello.light.45.py serial_port"
   sys.exit()
port = sys.argv[1]
```
Problem fixed:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1464706293.jpeg)

[Video](https://youtu.be/GiuYhmkRabA)

### A switch board

I also made a board with a button:

![](http://7xjpra.com1.z0.glb.clouddn.com/hello.button.45.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/week11myswitchboard.jpeg)

Download [hello.button.45.c](http://academy.cba.mit.edu/classes/input_devices/button/hello.button.45.c) and [makefile](http://academy.cba.mit.edu/classes/input_devices/button/hello.button.45.make). cd into the folder in terminal, run command: ``make -f hello.button.45.make`` and ``sudo make -f hello.button.45.make program-usbtiny``. All going well.

Connect my board to TTL2USB:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1464706284.jpeg)

Next, I run ``python term.py /dev/ttyUSB0``

It responds:

``command line: term.py serial_port speed``

I forgot to change my port name to :

``python term.py /dev/tty.usbserial-A400gwhT 9600``

And the result came out:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1464706285.jpeg)

[Video](https://youtu.be/WI6ty3sx18U)

### A temperature board

I continued to make a board with a temperature sensor:

![](http://7xjpra.com1.z0.glb.clouddn.com/hello.temp.45.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/week11mytempboard.jpeg)

Download [hello.temp.45.c](http://academy.cba.mit.edu/classes/input_devices/temp/hello.temp.45.c) and [makefile](http://academy.cba.mit.edu/classes/input_devices/temp/hello.temp.45.make). Used make command to make the board.

Then run the program: ``python hello.temp.45.py /dev/tty.usbserial-A400gwhT 9600``

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1464706291.jpeg)