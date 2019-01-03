#pragma once

#include "ofMain.h"
#include "Mover.hpp"
#include "Attractor.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    static const int num=20;
    Mover* mover[num];
    Attractor* attract;
    
};
