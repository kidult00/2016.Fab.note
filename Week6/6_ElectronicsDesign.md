# 3.2 Week6 Note

[Electronics Design](http://academy.cba.mit.edu/classes/electronics_design/index.html)


## Component

- wire: ribbon cable
- switch: button
- resistor(电阻): I=V/R
	![](http://media.digikey.com/Renders/Yageo%20Renders/CRSM%20PT1206_sml.jpg)
- capacitor(电容): C = Q/V, I = C dV/dt
	+ unpolarized 无极，voltage can go either direction
	![](http://media.digikey.com/Renders/TDK%20Renders/X7R-1206_sml.jpg)
	+ polarized 有极，voltage can only go one direction
	![](http://media.digikey.com/photos/NessCap%20Photos/ESHSR-0010C0-002R7_sml.jpg)
- crystal(tell time), resonator(晶体谐振器)

	![](http://media.digikey.com/photos/NDK%20Photos/NX5032GA%20SERIES_sml.jpg) 
	![](http://media.digikey.com/Photos/ECS%20Photos/CR23.7%20SERIES_sml.jpg)

- inductor(电感): V = L dI/dt, used as filters that prevent signals changing quickly.

	![](http://media.digikey.com/photos/Panasonic%20Photos/ELL-CTV%20SERIES_sml.jpg)
	
- diode(二极管): current from anode(正极) to cathode(负极)
  PN,Schottky,Zener,(what's the difference?)
  LED

![](http://oimagea5.ydstatic.com/image?url=http://swordrock.files.wordpress.com/2010/08/diode.jpg&product=PICDICT)
![](http://media.digikey.com/Renders/STMicro%20Renders/497;%20SOD123;%20;%202_sml.jpg)
![](http://media.digikey.com/photos/Lite%20On%20Photos/LTST-C150AKT,LTST-C150CKT,LTST-C150EKT,LTST-C150GKT,LTST-C150YKT_sml.jpg)

- transistor(晶体管)
	+ bipolar(双极的, always use current): collector(集电极), emitter(发射器), base current gain()
	+ mosfet(金属氧化物半导体场效应晶体管): source, drain, gate resistance
	![](http://media.digikey.com/Renders/~~Pkg.Case%20or%20Series/SOT-23-3%20PKG_sml.jpg)

- regulator(调节器)
- op-amp(运算放大器)
	
	![](http://media.digikey.com/Renders/~~Pkg.Case%20or%20Series/TSOT-23-5_sml.jpg)
	
- microcontroller(微控制器)
	
	![](http://media.digikey.com/Renders/~~Pkg.Case%20or%20Series/14-SOIC_sml.jpg)
	
	AVR

- [sensors](http://academy.cba.mit.edu/classes/input_devices/index.html)(传感器)
- [actuators](http://academy.cba.mit.edu/classes/output_devices/index.html)(驱动器)

## Circuits

Kirchoff's laws: sum current at node, voltage around loop = 0

>power: P = I^2 R = I V

Steps: schematic entry(电路图输入), component placement, (auto)routing, simulation, fabrication

Tools：

```
 123D Circuits, Virtual Breadboard, Fritzing
 Eagle 
 DesignSpark, MultiSIM, BLUE
 KiCad(*), gEDA
 Altium, Circuit Maker, PCBWorks(*)
 OrCAD, Cadence, Synopsys, Mentor, Tanner, Magic
 Gnucap, Qucs, Oregano, Multisim (simulation tools)
 Verilog VHDL (programming)
```

[Fab Modules tutorial](http://kokompe.cba.mit.edu/index.html)

## more materials

- [The Physics of Information Technology](http://fab.cba.mit.edu/classes/MAS.862/). 
- [The Art of Electronics](http://users.physics.harvard.edu/~horowitz/aoe/)
- [基尔霍夫定律](http://baike.baidu.com/subview/131449/15794082.htm)
- [基尔霍夫定律youtube](https://www.youtube.com/watch?v=YKzJJyJO198)