## Week7 Assignment

This week's assigment is 

> make something big

I tried to make a simply CNC guitar.

Making a guitar is quite a complex work. I checked out a bunch of tutorials or videos:

[Make a Guitar with CNC](http://www.instructables.com/id/Make-a-Guitar-with-CNC/)


### Design

I decided to use Fusion 360 for 3D modeling. There're some [detail discussions](https://forums.autodesk.com/t5/design-validate-document/beginner-question-arch-top-guitar-model/td-p/5564290/highlight/true) in Autodesk user forum. [Inventables forum](https://discuss.inventables.com/search?q=guitar) also included some design and making tutorials. I found this video can be a nice starting guide for using Fusion 360 to creat a guitar body shape:

[Modeling a Guitar in Fusion 360 with T-Splines - YouTube](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=2&ved=0ahUKEwjI37zejM7LAhVX7mMKHVxBBNcQtwIIHzAB&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DMNZQMK_aw7M&usg=AFQjCNHqD4eORnK1A38sbemxJJhblGVc1g&sig2=34K72vsxx0u2BJKIvg5J-w&bvm=bv.117218890,d.cGc)

![](http://7xjpra.com1.z0.glb.clouddn.com/fusionguitartutor.png)

Then I started to draw my guitar based on these guides.

The body:

![](http://7xjpra.com1.z0.glb.clouddn.com/cncguitarbody1_shrink.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/cncguitarbody2_shrink.png)

The neck:

![](http://7xjpra.com1.z0.glb.clouddn.com/cncguitarneckbody1.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/cncguitarneckbody2.png)

I'll do these two main parts first.

Then we should make some setup for CAM.

Go to the CAM workspace in Fusion360. Select the component, click 「SETUP」 tool, and change the 「Model orientation」 to Z & X:

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-selectz.png)

Then select the body face to set Z axis:

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-selectzface.png)

Then choose the stock starting point by clicking the 「Stock box point」 and choose the up corner point:

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-selectstartpoint.png)

Next, change the size of the stock.

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-stocksetup.png)

Now we can generate the path for cam. Select 2D-Face

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-2dface.png)

Select 50mm face mill

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-2dAdaptive.png)

Then select 2D-Adaptive Clearing, select 80mm flat endmill and select the edge of extrusion

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-2dAdaptiveSelect.png)

Now we get the adaptive clearing path:

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-2dAdaptiveCalc.png)

Then select 2D-Countour and choose 60mm flat endmill, and the same edge as we do in 2D-Adaptive Clearing

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-contour_shrink.png)

It seemed a little complex, so I tried 3D Adaptive. But still many collisions.

![](http://7xjpra.com1.z0.glb.clouddn.com/cam-3dAdaptive_shrink.png)

### Make
The Shopbot isn't ready in our lab. So I'll update making notes later.

### Update 2016-07-03

Our shopbot is still out of work. So I change my plan to make a simple music stand.

![](http://7xjpra.com1.z0.glb.clouddn.com/fabweek7standdesign.png)

The key is to set paramatric thickness so that I can change the design easily according to the material I would use.

You can [download the cut files here](https://app.box.com/s/pp7zyjh4s12amztcp4fj12vlpy2gagar).

First, I do some test using laser cutter:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467164820.jpeg)

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467164822.jpeg)

Then I go to the industrial zone near SZOIL called Jindi Industrial Zone to get the CNC for our assignment. Below is a CNC machine SW1325:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467542883.jpeg)

Put my components all in a file:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467542887.jpeg)

I use 9mm medium density fiberboard（MDF）

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467542888.jpeg)

Endmill diameter: 4.00				
Endmill blade height: 30.00

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467542895.jpeg)

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467542894.jpeg)

Set the original point and the speed(5000 millimeter/min)

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467542905.jpeg)
 
Calculate the cutting path:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467542908.jpeg)

[video](https://youtu.be/yE0kisxhJcI)

### Assembly

Four parts shelf:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467543068.jpeg)

The base:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467543077.jpeg)

The stand:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467543083.jpeg)

Fits well with Flex's vinyl  :P

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1467543086.jpeg)
 
### Reference

- [RICKENBACKER GUITAR FACTORY TOUR ](http://www.notcot.com/archives/2009/09/rickenbacker-gu.php)
- [Beginner question, arch top guitar model](https://forums.autodesk.com/t5/design-validate-document/beginner-question-arch-top-guitar-model/td-p/5564290/highlight/true)
- [Highline Guitars](https://www.youtube.com/user/trideciple)
- [STEM-Guitar-Guitarbuilding](http://www.guitarbuilding.org/)
- [Fusion 360 CAM tutorial](http://www.autodesk.com/products/fusion-360/learn-training-tutorials?mktvar002=662996&utm_id=662996)