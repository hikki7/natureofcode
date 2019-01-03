#pragma once

#include "ofMain.h"
#include "Path.hpp"
#include "Vehicle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    Path *path;
    vector<Path> pathes;
    Vehicle* v;
};
