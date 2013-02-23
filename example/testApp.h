#pragma once

#include "ofMain.h"
#include "ofxEllipseSolver.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void mouseMoved( int x, int y );
		void mousePressed( int x, int y, int button );

		ofxEllipseSolver solver;
		vector<ofVec2f> pts;
		bool ok;
};
