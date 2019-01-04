#pragma once

#include "ofMain.h"
#include "vehicle.hpp"
#include "Path.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		
		
    vehicle* v;
    Path* path;
};
