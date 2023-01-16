#include "ChooseLevelState.h"


ChooseLevelState::ChooseLevelState(){
    mp4 = new Button(ofGetWidth()/2, (ofGetHeight()/2)+40,  80, 50, "  Map 4");
    mp3 = new Button(ofGetWidth()/2, (ofGetHeight()/2)+80,  80, 50, "  Map 3");
    mp2 = new Button(ofGetWidth()/2, (ofGetHeight()/2)+120,  80, 50, "  Map 2");
    mp1 = new Button(ofGetWidth()/2, (ofGetHeight()/2)+160,  80, 50, "  Map 1");
	leaveState = new Button(ofGetWidth()/2, (ofGetHeight()/2)+200,  80, 50, "  Go Back");
	createMapImage("images/map4.png");
}

void ChooseLevelState::createMapImage(string selection){
	curr_sel.load(selection);
}
void ChooseLevelState::tick() {
	mp4->tick();
    mp3->tick();
    mp2->tick();
    mp1->tick();
	leaveState->tick();
	if(selection != 0 && mp4->isOnTop(ofGetMouseX(), ofGetMouseY())){
		selection = 0;
		createMapImage("images/map4.png");

	}
    if(selection != 1 && mp3->isOnTop(ofGetMouseX(), ofGetMouseY())){
		selection = 1;
		createMapImage("images/map3.png");

	}
    if(selection != 2 && mp2->isOnTop(ofGetMouseX(), ofGetMouseY())){
		selection = 2;
		createMapImage("images/map2.png");

	}
    if(selection != 3 && mp1->isOnTop(ofGetMouseX(), ofGetMouseY())){
		selection = 3;
		createMapImage("images/map1.png");

	}
	if(mp4->wasPressed()){
		setPlayMap("images/map4.png");
		setNextState("Menu");
		setFinished(true);
		setMapChange(true);

	}
    if(mp3->wasPressed()){
		setPlayMap("images/map3.png");
		setNextState("Menu");
		setFinished(true);
		setMapChange(true);

	}
    if(mp2->wasPressed()){
		setPlayMap("images/map2.png");
		setNextState("Menu");
		setFinished(true);
		setMapChange(true);

	}
    if(mp1->wasPressed()){
		setPlayMap("images/map1.png");
		setNextState("Menu");
		setFinished(true);
		setMapChange(true);

	}
	if(leaveState->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}

void ChooseLevelState::render() {
	ofDrawBitmapString("Level Select", (ofGetWidth()/2)-20, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
    curr_sel.draw(ofGetWidth()/2, (ofGetHeight()/2)-80, 100, 100);
	mp4->render();
    mp3->render();
    mp2->render();
    mp1->render();
	leaveState->render();


}
void ChooseLevelState::keyPressed(int key){
	
}
void ChooseLevelState::mousePressed(int x, int y, int button){
	mp4->mousePressed(x, y);
    mp3->mousePressed(x, y);
    mp2->mousePressed(x, y);
    mp1->mousePressed(x, y);
	leaveState->mousePressed(x, y);
}

void ChooseLevelState::reset(){
	setFinished(false);
	setChange(false);
	setNextState("");
	mp4->reset();
    mp3->reset();
    mp2->reset();
    mp1->reset();
	leaveState->reset();
}

ChooseLevelState::~ChooseLevelState(){
	delete mp4; 
    delete mp3;
    delete mp2;
    delete mp1;
	delete leaveState;
}