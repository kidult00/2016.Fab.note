## Week16 Assignment

> write an application that interfaces with an input &/or output device that you made, comparing as many tool options as possible

I tried to turn my light board into an application.

![](http://7xjpra.com1.z0.glb.clouddn.com/week11mylightboard.jpeg)

First, I write a simple program which enable my light sensor talk to the serial port.

```
#include "SoftwareSerial.h"
 
const int analogInPin =  A3;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot
 
const int Rx = 2; // this is physical pin 7
const int Tx = 7; // this is physical pin 6
SoftwareSerial mySerial(Rx, Tx);
 
void setup() {
  pinMode(Rx, INPUT);
  pinMode(Tx, OUTPUT);
  mySerial.begin(9600); // send serial data at 9600 bits/sec
}

void loop(){
  sensorValue = analogRead(analogInPin);
  mySerial.println(sensorValue);
  delay(500);
}
```

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1465544599.jpeg)

The light sensor works fine. 

[Video](https://youtu.be/IOLJht_QtZU)

Then I write some code to tell whether it's dark in processing:

![](http://7xjpra.com1.z0.glb.clouddn.com/WeChat_1465547042.jpeg)

The code:

```
import processing.serial.*;
Serial myPort;
int lf = 10;
 
void setup(){
  size(300,300);
  myPort = new Serial(this,"/dev/tty.usbserial-A400gwhT",9600);
  textAlign(CENTER, CENTER);
  fill(255);
  textSize(20);
}
 
void draw(){
  while(myPort.available() > 0){
    String str = myPort.readStringUntil(lf);

    if(str!=null){
      int value = Integer.parseInt(trim(str));
 
       if (value >900) {
        print("it's dark ");
        println(value);
        background(0,0,0);
        text("-_- It's dark! ",150,120);
        text(value,150,200);
       } 
       else{
        print("it's getting light ");
        println(value);
        background(204,153,0);
        text(":P It's getting light ",150,120);
        text(value,150,200);
       }
    }
  }
}
```

[Video](https://youtu.be/O1mLcUZq9NM)