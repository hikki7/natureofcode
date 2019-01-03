#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    float dir;
    float radius;
    float angle;
    ofVec2f location;
		
};
