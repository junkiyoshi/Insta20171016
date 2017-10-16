#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() { }

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	float radius = 50;
	float x, y;
	float rainbow_height = 30;
	ofColor color;

	for (int i = 0; i < 7; i++) {

		ofRotateZ(ofGetFrameNum() * 2);

		color.setHsb(216 - i * 35, 255, 255);
		ofSetColor(color);

		int deg_max = ofMap(ofNoise((ofGetFrameNum() + i) * 0.025), 0, 1, -180, 360 + 180);
		if (deg_max < 0) { deg_max = 0; }

		ofBeginShape();
		for (int deg = 0; deg <= deg_max; deg += 1) {
			x = radius * cos(deg * DEG_TO_RAD);
			y = radius * sin(deg * DEG_TO_RAD);
			ofVertex(ofVec3f(x, y, 0));
		}
		for (int deg = deg_max; deg >= 0; deg -= 1) {
			x = (radius + rainbow_height) * cos(deg * DEG_TO_RAD);
			y = (radius + rainbow_height) * sin(deg * DEG_TO_RAD);
			ofVertex(ofVec3f(x, y, 0));
		}
		ofEndShape();

		radius += rainbow_height + 5;
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}