# 5.11 Week15 Note

This week is about [Networking and Communications
](http://academy.cba.mit.edu/classes/networking_communications/index.html).


purposes: location, parallelism, modularity, interference

## serial

asynchronous 异步

- [RS-232, RS-422, RS-485](http://www.maxim-ic.com/app-notes/index.mvp/id/723)
- [video](http://academy.cba.mit.edu/classes/networking_communications/bus/bus.mp4)


[I2C](http://www.nxp.com/documents/user_manual/UM10204.pdf)

- TWI
- USI
- software
- [library](http://arduino.cc/en/reference/wire)

SPI [library](http://arduino.cc/en/Reference/SPI)

[USB](http://www.usb.org/)

- [AVR](http://www.atmel.com/Images/doc8360.pdf), [LUFA](http://www.fourwalledcubicle.com/LUFA.php)
- [STM32](http://www.st.com/st-web-ui/static/active/en/resource/technical/document/user_manual/CD00158241.pdf)
- [V-USB](http://www.obdev.at/products/vusb/index.html)

## OSI layers

* 7: application (HTTP)
* 6: presentation (SSL)
* 5: session (RPC)
* 4: transport (TCP, UDP)
* 3: network (IP)
* 2: data link (MAC)
* 1: physical (PHY) 

## physical media

- capacity: bandwidth * log_2 (signal/noise)
- wired

      single-ended, differential, powerline
      open collector, open drain
      transmission (pass) gate, tri-state
      transmission line
      waveguide
      TIA RS232, 422, 485
      802.3 ethernet
         chip module
      SONET optical fiber
- wireless

	+ [FCC](http://www.fcc.gov/), [Part 15](http://www.ecfr.gov/cgi-bin/text-idx?c=ecfr&sid=896fdfef3883114171de384cf10702ce&rgn=div5&view=text&node=47:1.0.1.1.16&idno=47), [ISM](http://www.fcc.gov/Bureaus/OPP/working_papers/oppwp38chart.pdf)
	+ [802.11](http://www.ieee802.org/11/), [Wi-Fi](http://www.wi-fi.org/)
	+ [Wi-Fi](http://www.wi-fi.org/), [ZigBee](http://www.zigbee.org/)
	+ [6LoWPAN](http://www.ietf.org/dyn/wg/charter/6lowpan-charter.html)
	+ [Bluetooth](http://www.bluetooth.com/)
	+ optical: [transmitter](http://www.atmel.com/Images/doc2534.pdf), [receiver](http://www.atmel.com/Images/doc1473.pdf)
	

## [modulation](http://www.crcpress.com/product/isbn/9780849309670)

- PCM: Pulse-Code Modulation 脉冲编码调制
- PPM: Pulse-Position Modulation
- OOK: On-Off Keying 通断键控
- FSK: Frequency-Shift Keying 频移键控
- BPSK: Binary Phase-Shift Keying 二进制相移键控
- QAM: Quadrature Amplitude Modulation 求积分振幅变调
- OFDM: Orthogonal Frequency-Division Multiplexing 正交频分多路
- FHSS: Frequency-Hopping Spread Spectrum 跳频扩频
- DSSS: Direct-Sequence Spread Spectrum 直接序列扩频
- UWB:  Ultra-WideBand 超宽带

## [channel sharing](http://authors.phptr.com/tanenbaumcn4/)
* ALOHA
* Master-Slave
* Token Ring
* TDMA: Time-Division Multiple Access
* FDMA: Frequency-Divsion Multiple Access
* CSMA: Carrier-Sense Multiple Access
      
  - CD: Collision Detection
  - CA: Collision Avoidance
  - 1-persistent: transmit when clear
  - nonpersistent: random backoff
  - p-persistent: probability to transmit
  
* CDMA: Code-Division Multiple Access
* MIMO: Multiple-Input Multiple-Output
* PDMA": Physical-Division Multiple Access
