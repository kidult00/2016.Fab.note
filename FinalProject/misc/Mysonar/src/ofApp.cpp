#include "ofApp.h"

//int for storing the byte data from Arduino.
int byteData;
//--------------------------------------------------------------
void ofApp::setup(){
    //General setup of look of window.
    ofBackground(0);
    //myfont.loadFont("verdana.ttf", 64);
    ofSetColor(255);
    
    //serial port setup. using COM3 for Windows port.
    //Also using baud rate 9600, same in Arduino sketch.
    
    sampleRate = 44100;
    bufferSize = 512;
    
    for( int i = 0; i < n.size(); i ++) {
        
        keys.emplace_back( new Key(n[i]));
    }
    
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
    
    serial.setup("/dev/cu.usbmodem1421", 9600);
    
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
            msg = "The current note is: " + ofToString(byteData/2);
            
            //myfont.drawString("hi", 100, 100);
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //drawing the string version pf byteData on oF window.
    ofDrawBitmapString(msg, 50, 100);
    
    //printing byteData into console.
    cout << byteData << endl;
    
    if(byteData >= 1 && byteData <= 2 ){
        keys[0]->on();
    }else{
        keys[0]->off();
    }
    if(byteData >= 3 && byteData <= 4){
        keys[1]->on();
    }else{
        keys[1]->off();
    }
    if(byteData >= 5 && byteData <= 6){
        keys[2]->on();
    }else{
        keys[2]->off();
    }
    if(byteData >= 7 && byteData <= 8){
        keys[3]->on();
    }else{
        keys[3]->off();
    }
    if(byteData >= 9 && byteData <= 10){
        keys[4]->on();
    }else{
        keys[4]->off();
    }
    if(byteData >= 11 && byteData <= 12){
        keys[5]->on();
    }else{
        keys[5]->off();
    }
    if(byteData >= 13 && byteData <= 14){
        keys[6]->on();
    }else{
        keys[6]->off();
    }
    if(byteData >= 15 && byteData <= 16){
        keys[7]->on();
    }else{
        keys[7]->off();
    }
}

void ofApp::audioOut( float * output, int bufferSize, int nChannels){
    
    //    for ( int i = 0; i < bufferSize; i ++) {
    //
    //        freq = byteData * 100;
    //
    //        wave = osc.sinewave(freq);
    //
    //        output[i * nChannels] = wave ;
    //        output[ i * nChannels + 1] = wave;
    //
    //    }
    for(int i = 0; i < bufferSize; i ++) {
        
        for(int j = 0; j < n.size(); j ++) {
            
            notes += keys[j]->play() / n.size();
        }
        
        myMix.stereo(notes, outputs, 0.5);
        
        output[i * nChannels] = outputs[0];
        output[i * nChannels + 1] = outputs[1];
        
    }
    
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
