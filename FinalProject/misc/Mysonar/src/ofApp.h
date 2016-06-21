#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "keyClass.h"

class ofApp : public ofBaseApp{
    
public:
    //Standard oF functions.
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void audioOut( float * output, int bufferSize, int nChannels);
    
    int bufferSize, sampleRate;
    double notes;
    double outputs[ 2 ];
    
    vector<double> n {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88, 523.25 };
    
    vector<unique_ptr<Key>> keys;
    
    maxiMix myMix;
    
        maxiOsc osc;
        double freq, wave;
    //
    //    int bufferSize, sampleRate;
    //
    //Custom variables for on screen string and font.
    string msg;
    ofTrueTypeFont myfont;
    
    //New serial object.
    ofSerial serial;
    
};
