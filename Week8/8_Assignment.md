## Week8 Assignment

> Read a microcontroller data sheet
>
> program your board to do something, with as many different programming languages. 
>      and programming environments as possible

### Round1: make your own ISP
The FabISP is an in-system programmer for AVR microcontrollers, designed for production within a FabLab. It allows you to program the microcontrollers on other boards you make.

[FabISP: Programming tutorial](http://archive.fabacademy.org/archives/2016/doc/programming_FabISP.html)

Steps on OSX 

- [Download and Install Crosspack AVR](http://www.obdev.at/products/crosspack/index.html)
- Get Make (via XCode)
- Download the firmware [FabISP Firmware for MacOS 10.8.2](http://www.as220.org/fabacademy/downloads/fabISP_mac.0.8.2_firmware.zip)
- unzip and cd into the firmware directory
- Open the Makefile with TextEditor
- change avrisp2 to usbtiny

	Go to the line that says: 

	```
#AVRDUDE = avrdude -c usbtiny -p $(DEVICE) # edit this line for your programmer
AVRDUDE = avrdude -c avrisp2 -P usb -p $(DEVICE) # edit this line for your programmer
	```

	- If using the USBtiny programmer or another FabISP, remove the "#" in front of the line with "usbtiny" in it. Add a "#" to beginning the line with the "avrisp2" in it to comment it out. Save the Makefile
- cd firmware directory, ``make clean``
	+ the result should be ``rm -f main.hex main.lst main.obj main.cof main.list main.map main.eep.hex main.elf *.o usbdrv/*.o main.s usbdrv/oddebug.s usbdrv/usbdrv.s``
	
	when ``make hex``, error occured
	
	```
kidults-NMB:fabISP_mac.0.8.2_firmware kidult$ make hex
avr-gcc -Wall -Os -DF_CPU=20000000	 -Iusbdrv -I. -DDEBUG_LEVEL=0 -mmcu=attiny44 -c usbdrv/usbdrv.c -o usbdrv/usbdrv.o
make: avr-gcc: No such file or directory
make: *** [usbdrv/usbdrv.o] Error 1
	```
	Then I plugin my FabISP, it showed:
	
	![](http://7xjpra.com1.z0.glb.clouddn.com/FabISPMakeHex.png)

- Next, need to set the fuses so the board will use the external clock (crystal) by typing: ``make fuse``
	
	It seemed that something went wrong:
	
	```
	avrdude -c usbtiny -p attiny44  -U hfuse:w:0xDF:m -U lfuse:w:0xFF:m
	avrdude: Error: Could not find USBtiny device (0x1781/0xc9f)
	avrdude done.  Thank you.
	make: *** [fuse] Error 1
	```
	I couldn't figure out why. It seemed like a gcc complling problem or my board didn't work.

### Round2: Using a USBtinyISP

Then I tried to use a USBtinyISP.

First, download [hello.ftdi.44.echo.c](http://academy.cba.mit.edu/classes/embedded_programming/hello.ftdi.44.echo.c), [hello.ftdi.44.echo.c.make](http://academy.cba.mit.edu/classes/embedded_programming/hello.ftdi.44.echo.c.make)

Then connect my board with USBtinyISP:

![](http://7xjpra.com1.z0.glb.clouddn.com/usbtinyisp.jpeg)

Enter into the download folder, use command: ``make -f hello.ftdi.44.echo.c.make``

![](http://7xjpra.com1.z0.glb.clouddn.com/ISPmakefile.png)



Then ``sudo make -f hello.ftdi.44.echo.c.make program-usbtiny-fuses``

It didn't work:

```
avr-objcopy -O ihex hello.ftdi.44.echo.out hello.ftdi.44.echo.c.hex;\
	avr-size --mcu=attiny44 --format=avr hello.ftdi.44.echo.out
AVR Memory Usage
----------------
Device: attiny44

Program:     758 bytes (18.5% Full)
(.text + .data + .bootloader)

Data:         64 bytes (25.0% Full)
(.data + .bss + .noinit)


avrdude -p t44 -P usb -c usbtiny -U lfuse:w:0x5E:m

avrdude: initialization failed, rc=-1
         Double check connections and try again, or use -F to override
         this check.


avrdude done.  Thank you.

make: *** [program-usbtiny-fuses] Error 1
```

I checked [this tutorial](http://archive.fabacademy.org/archives/2016/doc/fuses.html) and tried to understand fues.

> What are the fuses?
> 
> There are 3 bytes of permanent storage in the chip called 'fuse low byte', 'fuse high byte' and 'fuse extended byte'. These bytes are called fuses and can be reprogrammed as many times as you want and determines the behaviour of the chip. To do that, their value is not erased when the chip is powered off or reprogrammed.
> 
> Each microchip has its own definition for the values that must have the fuses. 

I googled the error message and find [this fab note](http://fab.cba.mit.edu/classes/863.12/people/laia.mogassoldevila/projects/p6.html), it recommended  install [FTDI chip drivers](http://www.ftdichip.com/Drivers/VCP.htm). But error still occur after installing FTDI driver.

Something went wrong with my board. I should make a new board after our lab reopen next week...

### update 

I make a new board and fuse again:

![](http://7xjpra.com1.z0.glb.clouddn.com/boardfuseok.png)

Next step

``make -f hello.ftdi.44.echo.c.make program-usbtiny``

![](http://7xjpra.com1.z0.glb.clouddn.com/boardfusemake.png)

Now I can burn program into the board. Download [term.py](http://academy.cba.mit.edu/classes/input_devices/python/term.py)

``python term.py /dev/ttyUSB0 115200``, didn't work:

```
Traceback (most recent call last):
  File "term.py", line 89, in <module>
    ser = serial.Serial(port,speed)
  File "/Library/Python/2.7/site-packages/serial/serialutil.py", line 180, in __init__
    self.open()
  File "/Library/Python/2.7/site-packages/serial/serialposix.py", line 294, in open
    raise SerialException(msg.errno, "could not open port %s: %s" % (self._port, msg))
serial.serialutil.SerialException: [Errno 2] could not open port /dev/ttyUSB0: [Errno 2] No such file or directory: '/dev/ttyUSB0'
```

Then my classmate told me to try Arduino.

1. Add board

	open Arduino preference, Additional Boards Manager URLs:

	> https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json

	![](http://7xjpra.com1.z0.glb.clouddn.com/arduinoAddBoard.png)

2. Settings

	Set board:"ATtiny", Processor:"ATtiny44", Clock:"20 MHz", Port:"USB"

	![](http://7xjpra.com1.z0.glb.clouddn.com/arduinosetting.png)

3. Program

	Load the Blink example, change pin No. from 13 to 7:

	![](http://7xjpra.com1.z0.glb.clouddn.com/arduinochangepin.png)

4. Burn Bootloader
5. It worked!

	![](http://7xjpra.com1.z0.glb.clouddn.com/boardsucceed.jpeg)


Ref:

- [Programming an ATtiny w/ Arduino 1.6 (or 1.0)](http://highlowtech.org/?p=1695)
- [Use an Arduino as a FTDI Programmer](http://www.instructables.com/id/Arduino-Examples-2-Use-an-Arduino-as-a-FTDI-Progr/)
- [classmate's note1](http://fabacademy.org/archives/2015/eu/students/koch.juliette/week7.html)
- [classmate's note2](http://fabacademy.org/archives/2015/eu/students/aloy_ciller.mariona/p/module-seven.html)
- [classmate's note3](http://fabacademy.org/archives/2015/eu/students/escario_mendez.alejandro/embedded_programming.html)
- [classmate's note4](http://archive.fabacademy.org/archives/2016/fablabshenzhen/students/408/Web/#p=week_08__embedded_programming)



---

	
### Other attempts

#### Try to use Arduino as ISP

Tutorial: [Arduino board as ATtiny programmer](http://highlowtech.org/?p=1706)

Installing ATtiny support in Arduino

- Open the preferences dialog in the Arduino software.
- Find the “Additional Boards Manager URLs” field near the bottom of the dialog.
	![](http://highlowtech.org/wp-content/uploads/2011/10/additional-boards-manager-urls-blank.png)
- Paste the following URL into the field (use a comma to separate it from any URLs you’ve already added):
	''https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json''
- Click the OK button to save your updated preferences.
- Open the boards manager in the “Tools > Board” menu.
- Scroll to the bottom of the list; you should see an entry for “ATtiny”.
	![](http://highlowtech.org/wp-content/uploads/2011/10/boards-manager.png)
- Install
- Close the boards manager. You should now see an entry for ATtiny in the “Tools > Board” menu.


把 USBtinyISP 通过 usb 连接到 new MacBook，指示灯不亮。开始了折腾之旅。。。

连接到 MacBook pro，指示灯亮，但是上传不了程序

查到一个[说明文档](https://learn.adafruit.com/downloads/pdf/usbtinyisp.pdf) ，发现电脑上没有安装 [avrdude](http://savannah.nongnu.org/projects/avrdude/), 但还是不知道该怎么装。

突然间看到 new MacBook 电量低，想起会不会是因为电量不足所以识别不了 USBtinyISP？ 插上插头。。。果然