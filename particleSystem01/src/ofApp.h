#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "particleSystem.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void mousePressed(int x, int y, int button);


		
    vector<particleSystem*> ps;
    ofVec2f gravity;
};
