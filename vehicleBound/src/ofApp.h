#pragma once

#include "ofMain.h"
#include "vehicle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    vehicle* v;

};
