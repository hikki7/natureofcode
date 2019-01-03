#pragma once

#include "ofMain.h"
#include "Pendulim.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
    
    Pendulim* p;
		
};
