
//initialising library.
#include <NewPing.h>

// Arduino pin assigned to trigger pin on the ultrasonic sensor.
#define TRIGGER_PIN  12  
// Arduino pin assigned to echo pin on the ultrasonic sensor.
#define ECHO_PIN     11  
// Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define MAX_DISTANCE 500 

//int for reading the distance in cm into.
int dist;

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  
  // ( setting ping distance in cm to dist variable (0 = outside set distance range).
  dist = sonar.ping_cm();

  // Wait 50ms between pings (about 20 pings/sec).
  delay(50);

  //here the dist variable is being written in bytes so that is can be read in oF as an int.                       
  Serial.write(dist); 

}
