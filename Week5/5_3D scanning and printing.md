# 2.24 Week5 Note

[3D Scanning and Printing](http://academy.cba.mit.edu/classes/scanning_printing/index.html)

## 3D Printing

3D printing isn't new. [Chuck Hull](http://www.3dsystems.com/30-years-innovation) invented 3D printing back to 1980s.



### constraints

materials: ABS(丙烯腈—丁二烯—苯乙烯,ABS塑料), HIPS, acrylic, PLA(easier to print)

resolution: pay attention to minimal wall and edge thickness and sharpness. clearance, tolerance

time: should spend hours

cost: depend on the machine and materials. [3D Printing Materials](http://www.shapeways.com/materials) documented materials for 3D printing.

supports


      
### processes   

- stereolithography(立体平版印刷)
	
	SLA，Direct Metal Printing (DMP)
	
- [selective laser sintering(SLS)](http://www.3dsystems.com/3d-printers/production/overview)
- [fused-deposition molding(FDM 熔融沉积成型)](http://www.stratasys.com/3d-printers), [extrusion(挤出/喷出)](http://web.media.mit.edu/~neri/MATTER.MEDIA/Publications/Additive%20Manufacturing%20of%20Optically%20Transparent%20Glass.pdf), [contour crafting](http://www.contourcrafting.org/)
- [ink-jet binder(喷墨粘结剂)](http://www.3dsystems.com/3d-printers/personal/overview)
- [ProJet](http://www.3dsystems.com/3d-printers/professional/overview), [PolyJet](http://www.stratasys.com/3d-printers/design-series/objet260-connex3). Full color printing, very high resolution.
- [cut sheets](http://www.mcortechnologies.com/)
- [CLIP](http://carbon3d.com/), [TED talk about this](https://www.ted.com/talks/joe_desimone_what_if_3d_printing_was_25x_faster)
- [two photon(光子)](http://www.nanoscribe.de/en/applications/micro-rapid-prototyping/)

### machine

Every year MAKE magazine make [a 3D printer list](http://makezine.com/2015/11/04/digital-fabrication-shootout-winners/).

### file formats

- STL （binary, triangle）Dump but simple. It doesn't include units info, you have to tell the printer the unit of your file. 
- [OBJ](http://usa.autodesk.com/alias/), [3ds](http://usa.autodesk.com/3ds-max/) by 3D MAX
- [VRML, X3D](http://www.web3d.org/x3d-vrml-most-widely-used-3d-formats)

stay away form DXF ...

### software

```
   123D
   SketchUp
   Fusion 360
   SolidWorks
   Rhino Grasshopper
   Blender
   FreeCAD
   OpenSCAD
   Antimony
   VTK
   MeshLab netfabb meshmixer
   Geomagic
   ReplicatorG Skeinforge Slic3r Cura
```

## 3D Scanning

point cloud, triangulation, watertight, texture

[A Simple Guide To Understanding 3D Scanning Technologies](http://lmi3d.com/sites/default/files/EBOOK_A_Simple_Guide_To_3D.pdf)

The most commonly used technologies fall into three categories: 

- Displacement: Displacement devices use a single point laser beam
projection to measure the height, thickness, or position of
an object. 
- Profile: Line Profile devices typically use a projected laser line
to create a cross section profile for measuring aspects
of an object’s contour. Moving an object under the laser
line creates many profiles that can be combined into a
complete 3D shape.
- Snapshot (aka, Scanner): Snapshot devices use structured light (non-laser) and
stereo-vision to generate full 3D volume data. Because
Snapshot technology captures so much 3D data at one
time, objects need to remain stationary during the
scanning process.

## more materials

- Stratasys's course [Introduction to 3D Printing: From Design to Fabrication](http://www.stratasys.com/industries/education/educators/curriculum/downloads). 
- [Additively is the 3D printing platform for professionals](https://www.additively.com/en/)
- [A guide to 3D scanner technology](http://www.rapidform.com/3d-scanners/)