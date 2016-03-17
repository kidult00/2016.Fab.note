# 3.16 Week8 Note

This week is about [Embedded Programming](http://academy.cba.mit.edu/classes/embedded_programming/index.html).

## Microprocessor / Microcontroller

- memory: registers, SRAM, DRAM, EEPROM, FLASH, fuse
- peripherals: A/D, comparator, D/A, timer/counter/PWM, USART, USB
- word size: 8, 16, 32, 64
- families: [8051](http://www.faqs.org/faqs/microcontroller-faq/8051/), [PIC](http://www.microchip.com/pagehandler/en-us/products/picmicrocontrollers), [MSP](http://www.ti.com/lsds/ti/microcontroller/16-bit_msp430/overview.page), [AVR ](http://www.atmel.com/products/microcontrollers/avr/default.aspx)(what we going to use), [ARM](http://www.arm.com/)  [STM32](http://www.st.com/web/en/catalog/mmc/FM141/SC1169)  [mbed](https://www.mbed.com/en/), [PSoC](http://www.cypress.com/psoc/?source=CY-ENG-HEADER)  [xCORE](http://www.xmos.com/en/products)  [Propeller](http://www.parallax.com/microcontrollers/propeller)
- vendors: [Octopart](http://octopart.com/), [Digi-Key](http://www.digikey.com/), [Mouser](http://www.mouser.com/), [Newark](http://www.newark.com/), [Farnell](http://www.farnell.com/), [SparkFun](http://www.sparkfun.com/), [Adafruit](https://www.adafruit.com/)
- clocks
	+ types:
      - RC (10%, 1% calibrated 校准)
      - ceramic 陶瓷 (0.5%)
      - quartz (50 ppm)
   	+ PLL
   	+ instruction cycles
   	+ overclocking

## Development
- in-system development (load a program into the processor)
	+ ISP (header, pads, clip) the program talk to the programmer 
   	+ bootloader: [Arduino](http://arduino.cc/en/Main/Bootloader), [DFU](http://www.atmel.com/images/doc8457.pdf), [Micronucleus](https://github.com/micronucleus/micronucleus)
   	+ JTAG, PDI
   	+ ICE
- programmers
	+ ISP
      - [FabISP](http://academy.cba.mit.edu/classes/electronics_production/index.html)
      - [avrdude](http://www.nongnu.org/avrdude/)
   	+ JTAG, PDI
      - [Atmel-ICE](http://www.digikey.com/product-detail/en/ATATMEL-ICE-BASIC/ATATMEL-ICE-BASIC-ND)
- assembly language 汇编语言: [hex file](http://fab.cba.mit.edu/about/fab/hello/ftdi/hello.ftdi.44.echo.hex), [instruction set, opcodes](http://academy.cba.mit.edu/classes/embedded_programming/doc0856.pdf), [mnemonics, directives, expressions](http://academy.cba.mit.edu/classes/embedded_programming/doc1022.pdf), [avr-as](http://www.nongnu.org/avr-libc/user-manual/overview.html), [gavrasm](http://www.avr-asm-tutorial.net/gavrasm/index_en.html)
- C (arduino underlying language): need a Compiler（编译器）to turn C language into hex codes.
	+ AVR is designed with [GCC(the GNU Compiler Collection)](http://gcc.gnu.org/) in mind. [AVR Libc](http://www.nongnu.org/avr-libc/user-manual/index.html) are the bindings for C to talk to AVRs
	+ For OS X, use [CrossPack for AVR® Development](https://www.obdev.at/products/crosspack/index.html)
	+ In a word, we are going to **use UCC to compile C code to hex code for AVRs**.
- IDE
	+ write, complie, load
	+ [Atmel Studio](http://www.atmel.com/Microsite/atmel-studio/default.aspx), [Eclipse](http://www.eclipse.org/), [AVR](http://avr-eclipse.sourceforge.net/wiki/index.php/The_AVR_Eclipse_Plugin), [CodeBender](http://codebender.cc)
- Interpreters(but too slow): [Python](https://micropython.org/), [BASIC](http://code.google.com/p/dk-basic/), [FORTH](http://amforth.sourceforge.net/), [AVRSH](http://www.instructables.com/id/AVRSH-A-Command-Interpreter-Shell-for-ArduinoAVR/), Javascript([Espruino](http://www.espruino.com/), [Tessel](https://tessel.io/), [iop.io](http://iop.io/))

## Communication(主机通讯)
- access for the serial port like [pyserial](https://github.com/pyserial/pyserial)
- [FTDI](http://www.ftdichip.com/): offering a wide range of products including modules, cables, and integrated circuits for USB connectivity, super bridging MCUs and display systems.
	+ [cable](http://search.digikey.com/us/en/products/TTL-232R-5V/768-1028-ND/2003493)
	
		![](http://media.digikey.com/photos/FTDI%20(Future%20Tech%20Devices\)/TTL-232R-5V_sml.jpg)
	
	+ [libFTDI](http://www.intra2net.com/en/developer/libftdi/)

## Boards
- AVR
	+ [Atmel](http://www.digikey.com/product-detail/en/ATXMEGAE5-XPLD/ATXMEGAE5-XPLD-ND)
	
		![](http://media.digikey.com/Photos/Atmel%20Photos/ATXMEGAE5-XPLD.JPG)
	
	+ [Arduino](http://www.arduino.cc/)
	
		![](https://www.arduino.cc/new_home/assets/illu-arduino-UNO.png)
	
		- board + C libraries + IDE + bootloader + header
		- [hello.arduino.328P.cad](http://academy.cba.mit.edu/classes/embedded_programming/hello.arduino.328P.cad)
	+ XMEGA: newer family of AVR
		- [features](http://www.atmel.com/Images/doc7925.pdf)
		- toolchain: [CrossPack for OS X](https://www.obdev.at/products/crosspack/index.html)
- ARM
	- ARM is a processor architechture which dominate in cellphone
	- [STM32](http://www.st.com/web/en/catalog/mmc/FM141/SC1169)
	- [Rasberry Pi](http://www.raspberrypi.org/)
	
		![](https://www.raspberrypi.org/wp-content/uploads/2016/02/Pi_3_Model_B-01.png)
	
	- [BeagleBone](http://beagleboard.org/)
	- [PandaBoard](http://pandaboard.org/)
	- [Snappy](https://developer.ubuntu.com/en/snappy/)
- [PSoC](http://www.digikey.com/product-detail/en/CY8CKIT-049-42XX/428-3344-ND): a programable system on chip, windows only
	![](http://media.digikey.com/photos/Cypress%20Semi%20Photos/CY8CKIT-049-42XX.jpg)

## More materials
[data sheets](http://academy.cba.mit.edu/classes/embedded_programming/doc8183.pdf)

