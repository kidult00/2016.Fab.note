
## Week6 Assignment

> Redraw the echo hello-world board
> 
> * add (at least) a button and LED (with current-limiting resistor)
> * check the design rules, and make it
> * extra credit: simulate its operation

Since I have zero experience of circuitboard design, so I followed [this assignment note](http://fabacademy.org/archives/2014/students/figueiredo.tiago/assignments/week6.html) of fab 2014 to do my work.

### 1. Import lib
Eagle provides enormous library of components, but for the purpose of this assignment, it will be better and easier to work with [the library](http://archive.fabacademy.org/archives/2016/doc/electronics/fab.lbr) already provided by the academy.

After opening Eagle, on the top toolbar there is a button "Use library", click it and select the libraries you've downloaded a while ago.

![](http://7xjpra.com1.z0.glb.clouddn.com/01eagleUseLib.png)

### 2. Add components
The next step is to add components into the schematic canvas. The first component you are going to place is microcontroller ATtiny44. Choose ATTINY44-SSU from the FAB library and click ok to place it on your schematics.

![](http://7xjpra.com1.z0.glb.clouddn.com/001lib.png)

After placing one component you can press "esc" and go back to "add panel". Add other components: 

![](http://7xjpra.com1.z0.glb.clouddn.com/002eagleComponents.png)

### 3. Sketch the schematic
After adding all the components, it's time for some wiring, naming and labeling. You'll use these commands:

![](http://7xjpra.com1.z0.glb.clouddn.com/03eageltool.png)

You should label all the pins right. And the net should not overlap the pin. It's easy to mess up. So doblecheck everything. Here is my schematic:

![](http://7xjpra.com1.z0.glb.clouddn.com/003eagleScheme.png)


### 4. Generate board

Click "Generate/Switch to board" button next to the lib button. 

![](http://7xjpra.com1.z0.glb.clouddn.com/01eagleUseLib.png)

It'll take you to board view. All the commponents are ready to re-arrange.

![](http://7xjpra.com1.z0.glb.clouddn.com/004eaglesendtoboard.png)

Use move and rotate commands to arrange the board. You might need to adjust grid setting for finer position control.

![](http://7xjpra.com1.z0.glb.clouddn.com/005eagelgrid.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/006ealgearrange.png)

All components seem to be at the right place. Use "Ratsnest" command to clear some connetions.

![](http://7xjpra.com1.z0.glb.clouddn.com/007eagleRatsnest.png)

Then I tried Autorouter, but the result was not desirable。

![](http://7xjpra.com1.z0.glb.clouddn.com/008eagleautoroute.png)

### 5. Route manually

Follow the yellow traces, I route the board manually. These's a tip: you can right click to change line modes when you come to a 90 degree turning point.

After finishing routing, you can hide layers except "top" , then you can see the nice traces of your board:

![](http://7xjpra.com1.z0.glb.clouddn.com/010eageldone-1.png)

[Downlong my eagle files](https://app.box.com/s/aaymx4rv9zuroshc6rktvhyweq8mw65i)

### 6. Export

Export your image as a PNG selecting only the top layer of your board. You'll only get the traces of it. Don't forget to check the Monochrome checkbox.

![](http://7xjpra.com1.z0.glb.clouddn.com/011eagelexport.png)

Next, export "Dimension" layer for the board.

![](http://7xjpra.com1.z0.glb.clouddn.com/012eagelallprint-1.png)


### 7. Milling

It's time for milling. Upload eagle export to fab modules. I set the dpi to 1500 px and the route result seems ok.

![](http://7xjpra.com1.z0.glb.clouddn.com/013fabmodels.png)

The traces, not bad.

![](http://7xjpra.com1.z0.glb.clouddn.com/014echomilling.jpeg)

And the finish board:

![](http://7xjpra.com1.z0.glb.clouddn.com/015echoboarddone.jpeg)

### 8. Assembly
Now, the finally step, assembling.

Picking out all the components can be quite a painstaking job. I draw a sketch to assure everything is ready.

![](http://7xjpra.com1.z0.glb.clouddn.com/016echocomponents.jpeg)

I like doing soldering, although I still have some trouble with those tiny components :)

![](http://7xjpra.com1.z0.glb.clouddn.com/017echosolderingdone.jpeg)

![](http://7xjpra.com1.z0.glb.clouddn.com/018myechoboard.jpeg)

## More materials
- [JeremyBlum's eagle tutorials](http://www.jeremyblum.com/category/eagle-tutorials/)
- [EAGLE官方教程视频](http://www.geek-workshop.com/thread-670-1-1.html)