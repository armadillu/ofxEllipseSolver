#include "testApp.h"


void testApp::setup(){

	ofEnableAlphaBlending();
	ofBackground(22);
	mousePressed(0,0,0);
}


void testApp::update(){
	ok = solver.solveElipse(pts[0], pts[1], pts[2], pts[3], pts[4]);
}

void testApp::mousePressed( int x, int y, int button ){
	pts.clear();
	for(int i = 0; i < 5; i++){
		int rx = 200;
		int ry = 200;
		pts.push_back( ofVec2f( ofRandom(-rx, rx), ofRandom(-ry, ry)) );
	}
}

void testApp::mouseMoved( int x, int y ){
	pts[0].x = x - ofGetWidth()/2;
	pts[0].y = y - ofGetHeight()/2;
};

void testApp::draw(){

	if (ok){

		ofMesh m1;
		m1.setMode(OF_PRIMITIVE_POINTS);

		float step = M_PI * 0.01;

		for(float angle = 0; angle < 2 * M_PI; angle+= step){
			m1.addVertex( solver.getEllipseVertexAt(angle) );
		}

		ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

		ofSetColor(255, 128);
		for(int i = 0; i < pts.size(); i++){
			ofCircle( pts[i], 4);
		}

		ofSetColor(0, 255, 0);
		m1.draw();
	}

	ofSetupScreen();
	ofDrawBitmapString("IsEllipse: " + ofToString(solver.getIsEllipse()) , 20, 20);
}
