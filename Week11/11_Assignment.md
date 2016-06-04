## Week11 Assignment

> measure something: add a sensor to a microcontroller board that you have designed and read it

In my assignment, I use Attiny45:

![](http://archive.fabacademy.org/archives/2016/fablabshenzhen/students/408/Web/images/week13__output_devices/u49.jpg)


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

Next command: ``sudo make -f hello.light.45.make program-usbtiny``

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

Video

{% youtube GiuYhmkRabA %}

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

Video

{% youtube WI6ty3sx18U %}

### A temperature board

I continued to make a board with a temperature sensor:

![](http://7xjpra.com1.z0.glb.clouddn.com/hello.temp.45.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/week11mytempboard.jpeg)

Download [hello.temp.45.c](http://academy.cba.mit.edu/classes/input_devices/temp/hello.temp.45.c) and [makefile](http://academy.cba.mit.edu/classes/input_devices/temp/hello.temp.45.make). Used make command to make the board.

Then run the program: ``python hello.temp.45.py /dev/tty.usbserial-A400gwhT 9600``

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1464706291.jpeg)