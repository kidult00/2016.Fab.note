# 2.17 Week4 Note

[electronics production](http://academy.cba.mit.edu/classes/electronics_production/index.html)

## Circuitboard
Circuits program circuits. Circuitboard you load a program to another board.

PCB(Printed Circuit Board) fabrication

No use etching(蚀刻), but machining, which is good for prototyping and is not good for volume production.

Use 1/64 for the surface of the board, and 1/32 for cutting through (make edges).

The sequence：

- fixturing 装夹，紧固（用双面胶）
- underlay (衬底)
- orientation
- zeroing (针头刚好接触板面)
- set-screws (固定螺丝)
- lifetime
- deburring (去毛刺)
- cleaning

check [this tutorial in detail](http://fab.cba.mit.edu/content/processes/PCB/modela2.html), or [a Video Walkthrough](http://www.youtube.com/watch?v=XdamEhs2RIk&list=PL-xEsC0ZUCUM42QNHaOOdoOwYg0j251dU&index=1)

PCB materials: [FR1（made from natural fiber）](http://www.globallaminates.com/) for rigid, [Kapton](http://www2.dupont.com/Kapton/en_US/) / [#1 epoxy film(环氧胶膜)](http://multimedia.3m.com/mws/media/37468O/3m-epoxy-film-electrical-tape-1.pdf) / [#1126 copper tape(铜箔胶带)](http://multimedia.3m.com/mws/media/104361O/tape-1126-copper-foil-with-conductive-adhesive.pdf) for flex (use vinyl cutter).

Design rules: width/spacing (15, 5 mils)

Components: through-hole(穿孔), surface-mount(表面贴装), chip-scale(封装). ATTINY44

Assembly: solder焊锡, make joints shiny and smooth

CAM: use [fab modules](http://fabmodules.org/) to make the PCB