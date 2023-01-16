#include "PauseState.h"

PauseState::PauseState(){
    resume = new Button((ofGetWidth()/2)-40, ofGetHeight()/2, 64, 50, " Resume"); 
    quit = new Button((ofGetWidth()/2)+40, ofGetHeight()/2, 64, 50, " Quit");
    pausePose.load("images/pacman.png");
    ofImage temp;
    vector<ofImage> rightFrames;
    for(int i=0; i<3; i++){
        temp.cropFrom(pausePose, i*16, 0, 16, 16);
        rightFrames.push_back(temp);
    }
    wait = new Animation(10, rightFrames);
}

void PauseState::render(){
    ofDrawBitmapString("Current Score: " + to_string(score), (ofGetWidth()/2)-40, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	wait->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
	resume->render();
    quit->render();
}

void PauseState::tick(){
    quit -> tick();
    resume -> tick();
    wait->tick();
    if(resume->wasPressed()){
        setNextState("Game");
	    setFinished(true);
    }
    if(quit->wasPressed()){
        setNextState("Menu");
        setFinished(true);
        setQuit(true);
    }
}

void PauseState::reset(){
    setFinished(false);
    setQuit(false);
	setNextState("");
	resume->reset();
    quit->reset();
}

void PauseState::setScore(int sc){
    score = sc;
}

void PauseState::mousePressed(int x, int y, int button){
    resume->mousePressed(x, y);
    quit->mousePressed(x, y);
}

void PauseState::keyPressed(int key){

}
void PauseState::setQuit(bool quit){
    quitFromPause = quit;
}
bool PauseState::getQuit(){
    return quitFromPause;
}
PauseState::~PauseState(){
    delete resume;
    delete wait; 
    delete quit;
}