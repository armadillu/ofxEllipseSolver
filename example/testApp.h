#pragma once

#include "ofMain.h"
#include "ofxEllipseSolver.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		

		ofxEllipseSolver solver;
};
