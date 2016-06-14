
# include<MozziGuts.h>
# include<Oscil.h>
# include<tables/sin2048_int8.h>

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

#define CONTROL_RATE 64

int trigPin = 11;
int echoPin = 12;

void setup() {
  // put your setup code here, to run once:
  startMozzi(CONTROL_RATE);
  aSin.setFreq(440u);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void updateControl(){
  float s = takeSounding();
  aSin.setFreq(s);  
}

int updateAudio(){
  return aSin.next();  
}

void loop() {
  // put your main code here, to run repeatedly:
  audioHook();
}

float takeSounding(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  int duration = pulseIn(echoPin, HIGH, 1000);
  if(duration > 1000) duration = 1000;
  return (float)duration / 2.0 ;
}
}

