#pragma once

#include "ofMain.h"
#include "particleSystem.hpp"
#include "repeller.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    particleSystem* psys;
    repeller* rp;
		
};
