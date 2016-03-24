## Week8 Assignment

> Read a microcontroller data sheet
>
> program your board to do something, with as many different programming languages. 
>      and programming environments as possible

### make your own ISP
[FabISP: Programming tutorial](http://archive.fabacademy.org/archives/2016/doc/programming_FabISP.html)

On OSX 

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

	- If using the USBtiny programmer or another FabISP
	- Remove the "#" in front of the line with "usbtiny" in it
	- Add a "#" to beginning the line with the "avrisp2" in it to comment it out.
	- save the Makefile
- cd firmware directory, ``make clean``
	+ the result should be
	``rm -f main.hex main.lst main.obj main.cof main.list main.map main.eep.hex main.elf *.o usbdrv/*.o main.s usbdrv/oddebug.s usbdrv/usbdrv.s``
	
	stuck in ``make hex``
	
	```
kidults-NMB:fabISP_mac.0.8.2_firmware kidult$ make hex
avr-gcc -Wall -Os -DF_CPU=20000000	 -Iusbdrv -I. -DDEBUG_LEVEL=0 -mmcu=attiny44 -c usbdrv/usbdrv.c -o usbdrv/usbdrv.o
make: avr-gcc: No such file or directory
make: *** [usbdrv/usbdrv.o] Error 1
	```
是不是因为没有连上板子？

### 尝试用 arduino 当做 ISP
then check [Arduino board as ATtiny programmer](http://highlowtech.org/?p=1706)

then check [Use an Arduino as a FTDI Programmer](http://www.instructables.com/id/Arduino-Examples-2-Use-an-Arduino-as-a-FTDI-Progr/)


- [classmate's note1](http://fabacademy.org/archives/2015/eu/students/koch.juliette/week7.html)
- [classmate's note2](http://fabacademy.org/archives/2015/eu/students/aloy_ciller.mariona/p/module-seven.html)
- [classmate's note3](http://fabacademy.org/archives/2015/eu/students/escario_mendez.alejandro/embedded_programming.html)


[hello.ftdi.44.echo.c](http://academy.cba.mit.edu/classes/embedded_programming/hello.ftdi.44.echo.c)