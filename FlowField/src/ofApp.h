#pragma once

#include "ofMain.h"
#include "FlowField.hpp"
#include "Vehicle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void mousePressed(int x, int y, int button);
    
    static const int num=10000;
    
    FlowField* ff;
    Vehicle* vehicle[num];
		
};
