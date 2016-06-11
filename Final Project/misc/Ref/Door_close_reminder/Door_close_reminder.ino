
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <tables/sin2048_int8.h> // sine table for oscillator

#define CONTROL_RATE 64
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

    int Trig_pin;
    int Echo_pin;
void setup(){
  Serial.begin(9600);
  startMozzi(CONTROL_RATE);
  aSin.setFreq(440);
    Ultrasonic(11,12);
}


void updateControl(){
 int s=takeSounding();
 aSin.setFreq(s);

}

int updateAudio(){
  return aSin.next();
}


void loop(){
  audioHook();  
}

int takeSounding()
{
     digitalWrite(Trig_pin, LOW);
     delayMicroseconds(2);
     digitalWrite(Trig_pin, HIGH);
     delayMicroseconds(10);
     digitalWrite(Trig_pin, LOW);
     int duration = pulseIn(Echo_pin,HIGH,3000);
     if(duration >3000) duration=3000;
  //   Serial.println(duration);
    int i=map(duration,174,3000,0,14);  //5---52CM
     Serial.println(i);
     switch(i)
     {
        case 0:duration=0;break;
        case 1: duration=262;break;  //DO
        case 2: duration=294;break;  //RE
        case 3: duration=330;break;  //ME
        case 4: duration=349;break;  //FA
        case 5: duration=392;break;  //SO
        case 6: duration=440;break;  //LA
        case 7: duration=494;break;  //SI
        case 8: duration=523;break;  //DO
        case 9: duration=578;break;  //RE
        case 10: duration=659;break; //ME
        case 11: duration=698;break;  //FA
        case 12: duration=784;break;
        case 13: duration=880;break;
        case 14: duration=988;break;
     }
     return duration;
}
void Ultrasonic(int TP, int EP)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
}
