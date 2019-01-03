#pragma once

#include "ofMain.h"
#include "Mover.hpp"
#include "Attractor.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
    
    static const int num=10;
    Mover* mover[num];
    Attractor* a;
		
};
