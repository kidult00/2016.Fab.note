#include "ofApp.h"
//int for storing the byte data from Arduino.
int byteData;
//--------------------------------------------------------------
void ofApp::setup(){
	//General setup of look of window.
	ofBackground(255);
	font.loadFont("verdana.ttf", 64);
	ofSetColor(0);

	//serial port setup. using COM3 for Windows port.
	//Also using baud rate 9600, same in Arduino sketch.
	serial.setup("COM3", 9600);
}

//--------------------------------------------------------------
void ofApp::update(){

	//Simple if statement to inform user if Arduino is sending serial messages. 
	if (serial.available() < 0) {
		msg = "Arduino Error";
	}
	else {
		//While statement looping through serial messages when serial is being provided.
		while (serial.available() > 0) {

			//byte data is being writen into byteData as int.
			byteData = serial.readByte();
			
			//byteData is converted into a string for drawing later.
			msg = "cm: " + ofToString(byteData);
		}

	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//drawing the string version pf byteData on oF window.
	font.drawString(msg, 50, 100);
	
	//printing byteData into console.
	cout << byteData << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
