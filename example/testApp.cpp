#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(4);
	ofEnableAlphaBlending();
	ofBackground(22);
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	vector<ofVec2f> pts;
	for(int i = 0; i < 5; i++){
		int rx = 200;
		int ry = 200;
		pts.push_back( ofVec2f( ofRandom(-rx, rx), ofRandom(-ry, ry)) );
	}

//	pts.clear();
//	for(int i = 0; i < 5; i++){
//		int r = 200;
//		float ang = i;
//		pts.push_back( ofVec2f( ofRandom( 0.9, 1.1) * r * cos(ang) , ofRandom( 0.9, 1.1) * r * sin(ang) ) );
//	}


	bool ok = solver.solveElipse(pts[0], pts[1], pts[2], pts[3], pts[4]);


	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	if (ok){
		ofSetColor(255);
		ofNoFill();
		ofMesh m1;
		m1.setMode(OF_PRIMITIVE_POINTS);

		float step = M_PI * 0.01;
		for(float angle = 0; angle < 2 * M_PI; angle+= step){
			m1.addVertex( solver.getEllipseVertexAt(angle) );
		}

		ofFill();
		ofSetColor(255, 128);
		for(int i = 0; i < pts.size(); i++){
			ofCircle( pts[i], 4);
		}

		ofSetColor(0, 255, 0);
		m1.draw();
	}

	//ofSetupScreen();
	ofDrawBitmapString("getIsEllipse: " + ofToString(solver.getIsEllipse()) , 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}