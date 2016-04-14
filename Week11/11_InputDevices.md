# 4.13 Week11 Note

This week is about [Input Devices](http://academy.cba.mit.edu/classes/input_devices/).

## inputs
- DDR, PORT, PINS
- comparator 比测仪
- A/D

## communication
- [pySerial](https://github.com/pyserial/pyserial): Python与串口通信
	+ [miniterm](http://pyserial.readthedocs.org/en/latest/tools.html#module-serial.tools.miniterm): pySerial 的操作终端
	+ 实例文件[rx.py](http://academy.cba.mit.edu/classes/input_devices/python/rx.py), [term.py](http://academy.cba.mit.edu/classes/input_devices/python/term.py)
- [serialport](https://www.npmjs.com/package/serialport): talk with js
- [chrome.serial](https://developer.chrome.com/apps/serial)
- [WebUSB API](https://wicg.github.io/webusb/)
- bit timing: crucial parameter, xxx bits/sec
- clocks (10% RC, 1% RC calibrated, .5% resonator, 50 ppm crystal)

## switch
button 

![](http://media.digikey.com/Photos/Omron%20Elect%20Photos/B3SN-3112_sml.jpg)
   
slide

![](http://media.digikey.com/photos/CK%20Comp%20Photos/AYZ0102AGRL_sml.jpg)

[test a button](http://academy.cba.mit.edu/classes/input_devices/button/hello.button.45.mp4)

![](http://academy.cba.mit.edu/classes/input_devices/button/hello.button.45.jpg)

## motion
pyroelectric 热释电红外PIR运动传感器探测器模块

Measure thermal radiation of your body. Detect activity and changes.

[test motion module video](http://academy.cba.mit.edu/classes/input_devices/motion/hello.HC-SR501.mp4)

![](http://academy.cba.mit.edu/classes/input_devices/motion/hello.HC-SR501.jpg)

## distance
sonar 声纳

Ultrasonic Module HC-SR04 Distance Sensor

![](http://academy.cba.mit.edu/classes/input_devices/sonar/hello.HC-SR04.jpg)

[test video](http://academy.cba.mit.edu/classes/input_devices/sonar/hello.HC-SR04.mp4)

## magnetic field
Hall effect:霍尔效应是指当固体导体放置在一个磁场内，且有电流通过时，导体内的电荷载子受到洛伦兹力而偏向一边，继而产生电压（霍尔电压）的现像。电压所引致的电场力会平衡洛伦兹力。

![](http://media.digikey.com/Renders/Allegro%20Microsystems%20Renders/SOT-23-3_sml.jpg)

[test video](http://academy.cba.mit.edu/classes/input_devices/mag/hello.mag.45.js.mp4)


## temperature

NTC : resistence goes up with temperature. higer temperature, less sensitive
![](http://media.digikey.com/Renders/Amphenol%20Renders/NHQ1206_sml.jpg)
   
RTD thermistors: lower temperature, more sensitive （NTC table）

![](http://media.digikey.com/Renders/Vishay%20Beyschlag%20Renders/MFU%201206%20(3216%20metric\)_sml.jpg)

[test video](http://academy.cba.mit.edu/classes/input_devices/temp/hello.temp.45.mp4)

## light
phototransistor 光电晶体管

![](http://academy.cba.mit.edu/classes/input_devices/light/hello.light.45.jpg)

[test video](http://academy.cba.mit.edu/classes/input_devices/light/hello.light.45.mp4)

## acceleration, orientation, rotation

3D accelerometer I2C

![](http://media.digikey.com/Renders/~~Pkg.Case%20or%20Series/14-LGA%20PKG_sml.jpg)

![](http://academy.cba.mit.edu/classes/input_devices/accel/hello.ADXL343.jpg)

[test video](http://academy.cba.mit.edu/classes/input_devices/accel/hello.ADXL343.mp4)

## sound
MEMS,  Microphones  >  Knowles SPU0414HR5H-SB-7
   
![](http://media.digikey.com/Photos/Knowles%20Acoustics%20Photos/SPU0414HR5H-SB_sml.jpg)

[test video](http://academy.cba.mit.edu/classes/input_devices/mic/hello.SPU0414HR5H.mp4)

## step response
resistance, capacitance, inductance, position, pressure, proximity, tilt, acceleration, humidity,

project: [touchpad](http://fab.cba.mit.edu/classes/863.10/people/matt.blackshaw/week8.html), [multitouch](http://fab.cba.mit.edu/classes/863.11/people/matthew.keeter/multitouch/index.html), ...
   
loading ([test video](http://academy.cba.mit.edu/classes/input_devices/step/hello.load.45.mp4))

transmit-receive ([test video](http://academy.cba.mit.edu/classes/input_devices/step/hello.txrx.45.mp4))

   dielectric spectroscopy measurement

## vibration
piezo

![](http://www.jameco.com/Jameco/Products/ProdImag/1956784.jpg)

## force
[force sensing resistor 力敏电阻](http://www.interlinkelectronics.com/standard-products.php)

![](http://www.interlinkelectronics.com/assets/images/FSR400_short.jpg)

[strain gauge 应变仪](http://www.omega.com/guides/straingages.html)

![](http://www.omega.com/Pressure/images/SGD_LINEAR1-AXIS_s.jpg)

[load cell 称重传感器](http://www.omega.com/prodinfo/loadcells.html)

![](http://www.omega.com/Pressure/images/LCGD_s.jpg)

## image
[module](http://www.amazon.com/sunkee-OV7670-640X480-Compatible-Interface/dp/B00AZWVZKW)

![](http://ecx.images-amazon.com/images/I/71MO-CLyIAL._SL1200_.jpg)

[cameras](https://www.google.com/search?channel=fs&q=webcam&ie=utf-8&oe=utf-8#channel=fs&q=webcam&tbm=shop&tbs=cat:312,vw:l,p_ord:p),[boards](https://www.google.com/search?channel=fs&q=embedded+linux+board&ie=utf-8&oe=utf-8#channel=fs&q=embedded+linux+board&tbm=shop)

[OpenCV](http://opencv.org/): a lib for video processing

[libuvc: a cross-platform library for USB video devices](https://int80k.com/libuvc/doc/)

[WebRTC](https://developer.mozilla.org/en-US/docs/Web/API/WebRTC_API):WebRTC (Web Real-Time Communications) is a technology which enables Web applications and sites to capture and optionally stream audio and/or video media, as well as to exchange arbitrary data between browsers without requiring an intermediary.

you can use js to do image processing like this :[video.html](http://academy.cba.mit.edu/classes/input_devices/video.html)



## more material
- [The Physics of Information Technology](http://www.cambridge.org/us/academic/subjects/physics/general-and-classical-physics/physics-information-technology?format=PB&isbn=9780521210225)
- [Basics of Measuring the Dielectric
Properties of Materials](http://academy.cba.mit.edu/classes/input_devices/meas.pdf)
- [Measure the Difference](http://academy.cba.mit.edu/classes/input_devices/DS.pdf)


