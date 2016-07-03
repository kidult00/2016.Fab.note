

## Week3 Assignment

> Design, make, and document a parametric press-fit construction kit.

Press-fit means reversable joints (like lego). The goal of the kit is to make something that more than one thing.

I try to design the parametric pattern by using Antimony.

### Practise with Antimony
[Antimony](http://www.mattkeeter.com/projects/antimony/3/) is a powerful "node-based" parametric CAD tool. If you have tried  Quartz composer or Origami, you'll get use to antimony in just a few minutes.


After installing, I checkout this [video tutorial](http://www.mattkeeter.com/projects/antimony/3/) by Matt Keeter and made my first piece:

![](http://7xjpra.com1.z0.glb.clouddn.com/antimonyprac.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/antimonytest.png)

(By the way, [fstl](http://www.mattkeeter.com/projects/fstl/) is a really great viewer for .stl files. )

Little tips:

You should use a mouse(by holding the right button) to orbit the view, which means the trackpad on a macbook is not enough.

### Design
[Tangram](https://en.wikipedia.org/wiki/Tangram) is an interesting puzzle game, like the Chinese version "lego". I played it in my childhood. So I'd like to make a tangram set with antimony and lasser cutter.

Creat a new file in antimony. By adding "2D" shape, we can creat all the shape we need in a tangram.

![](http://7xjpra.com1.z0.glb.clouddn.com/antimonys1.png)

“Difference” command helps to creat cardboard slot by subtracting a shape in another. 

![](http://7xjpra.com1.z0.glb.clouddn.com/antimonys2.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/antimonys4.png)

And "Translate" and "Rotate" modifies shapes' position.

![](http://7xjpra.com1.z0.glb.clouddn.com/antimonys3.png)

The reason of using antimony in this lesson, is to control small "units" in a parametric way. 
![](http://7xjpra.com1.z0.glb.clouddn.com/antimonys5.png)

You can [download my antimony file here](https://app.box.com/s/qfndi1fv6vhbyu6gr9rfzxfjnzxoj68o) , and the [tangram pdf](https://app.box.com/s/6cdjvc3lr6gsh1rz6gguic5m02iu451d) for cutting.


### Make

First I tried using laser cutter to draw "群主雕":

![](http://7xjpra.com1.z0.glb.clouddn.com/FullSizeRender%203_shrink.jpg)

Fabmodules is quite handy. Just select input format and the machine type, then select output material. Several parameters should be tested before hand.

When cutting thick and hard materials, power should be around 100% and speed 2%.

I tried speed 4% and power 90%, but still failed to cut though  cardboards we use in the lab.

![](http://7xjpra.com1.z0.glb.clouddn.com/IMG_9517_shrink.JPG)


In addition, the x,y positions are tricky, cos it is related to the dpi (if file format is png). Always do some tests before cutting.

Here's my tangram cardboard after cutting.

![](http://7xjpra.com1.z0.glb.clouddn.com/IMG_9524_shrink.JPG)

![](http://7xjpra.com1.z0.glb.clouddn.com/IMG_9525_shrink.JPG)

Tangram press-fit kit

![](http://7xjpra.com1.z0.glb.clouddn.com/IMG_9526_shrink.JPG)

Then I tried using acrylic to make a "3d minion".

1. upload svg file to fabmodules

	![](http://7xjpra.com1.z0.glb.clouddn.com/IMG_9535_shrink.JPG)

2. choose "cut acrylic", set units/in 50 ,power 90, speed 0.8, then do the position test

3. calculate cutting path

4. put acrylic board in the right place, the send path to the machine

5. press start button on the machine

![](http://7xjpra.com1.z0.glb.clouddn.com/IMG_9536_shrink.JPG)

Done after 18 mins!

Problem: machine can't cutting through some small parts, and some thin edges are burned out...

Now we got all parts for minion:

![](http://7xjpra.com1.z0.glb.clouddn.com/IMG_9537_shrink.JPG)

The last step is to glue all parts into a multi-layer minion:
![](http://7xjpra.com1.z0.glb.clouddn.com/FullSizeRender_shrink.jpg)

### Vinyl cut

I also try vinyl cut with GCC RXII60.

Import .svg into coraldraw and sent to the vinyl cutter. Set the print lind width to "hair".

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467543088.jpeg)

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467543093.jpeg)



