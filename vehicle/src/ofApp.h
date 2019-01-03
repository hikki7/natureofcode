#pragma once

#include "ofMain.h"
#include "vehicle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofVec2f mouse;
    float radius;
    vehicle* v;
    
};
