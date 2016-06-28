
# Week4 Assignment

> Make an in-circuit programmer

I followed [Andy's work](http://fab.cba.mit.edu/content/projects/fabispkey/index.html) to do this assigment.

Shouldn't miss this [Video Walkthrough](http://www.youtube.com/watch?v=XdamEhs2RIk&list=PL-xEsC0ZUCUM42QNHaOOdoOwYg0j251dU&index=1) and this [tutorial](http://fab.cba.mit.edu/content/processes/PCB/modela2.html) before starting fabrication, especially for beginners. It explains how to mill circuits on the modela in nice details.

## Cut the board for circuits

In our lab we use this guy: Roland SRM20

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456715597.jpeg)

1/64 bit end mill for traces and 1/32 bit end mill for board edges are ready.

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713553.jpeg)

We use FR1 which is a paper based copper plate to mill on.

### 1. fixation

Fix the FR1 on the base board with double sided tape:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713554.jpeg)

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713555.jpeg)

### 2. install endmill
Place endmill (1/64 for tracks first) into the hole, then use hexagonal screw to tighten it (clockwise).

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713556.jpeg)

### 3. position and zeroing

Open VPanel for SRM20, move X/Y to the ideal place. Then move z down to the board surface. When getting close to the zero point, loose the endmill until it just touch the board, then tighten it again.

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713557.jpeg)

### 4. mill

Choose the traces file and send to SRM20. Just wait until milling is done.

Once the traces are ok, replace endmill with 1/32. Move to origin x/y and z position. Then choose the outline file and send to SRM20.

If everything goes well, you should get something like this:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713581.jpeg)

### 5. clean up

Do some clean up:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713589.jpeg)

### trial and error

In my early experiments, I got wierd result: some parts of the board were ok but some traces were too shallow.

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713558.jpeg)

I couldn't figure out why until my classmate reminded me the endmill problem : I didn't tighten it enough! After milling for a while, it could move backwards.

So I tightened the endmill and solved the "half-milled" problem.

## Soldering

Next challenge: soldering!

Thanks to my classmate, they've prepared all the components before hand.
![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456730329.jpeg)

All the elements are so tiny that I was wondering if I can handle all of them...

I started from the biggest one: ATTINNY44

Place it to the right place, then press down one pin use welding torch with one hand, and let solder wire approach to the torch with the other hand. After solder melting down, put away wire first, then the torch. In a few seconds, the solder become shiny and smooth.

My first soldering component, not bad XD
![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713618.jpeg)

Keep trying:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713621.jpeg)

Final board:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1456713625.jpeg)

## Programming

