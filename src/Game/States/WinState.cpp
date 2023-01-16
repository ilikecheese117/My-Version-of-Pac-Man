#include "WinState.h"
#include "Ghost.h"

WinState::WinState(){
    next = new Button(ofGetWidth()/2, ofGetHeight()/2, 80, 50, " Next level!");
    cont = new Button(ofGetWidth()/2, (ofGetHeight()/2)+40, 80, 50, " Continue Playing!"); 
    quit = new Button(ofGetWidth()/2, (ofGetHeight()/2)+80, 50, 50, " Quit");
    winPose.load("images/pacman.png");
    ofImage temp;
    vector<ofImage> rightFrames;
    for(int i=0; i<3; i++){
        temp.cropFrom(winPose, i*16, 0, 16, 16);
        rightFrames.push_back(temp);
    }
    anima = new Animation(10, rightFrames);
}

void WinState::tick(){
    next->tick();
    cont -> tick();
    quit->tick();
    anima -> tick();
    if(next->wasPressed()){
		setNextState("Game");
		setFinished(true);
        setNextLevel(true);

    }
    if(cont->wasPressed()){
		setNextState("Game");
		setFinished(true);

    }
    if(quit->wasPressed()){
        setNextState("Menu");
        setFinished(true);

    }
}

void WinState::render(){
    ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anima->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
    next->render();
	cont->render();
    quit->render();
}

void WinState::setScore(int sc){
    score = sc;
}

void WinState::reset(){
    setFinished(false);
    setNextLevel(false);
	setNextState("");
    next->reset();
	cont->reset();
    quit->reset();
}

void WinState::mousePressed(int x, int y, int button){
    next->mousePressed(x, y);
	cont->mousePressed(x, y);
    quit->mousePressed(x, y);
}

void WinState::keyPressed(int key){

}

WinState::~WinState(){
    delete next;
	delete cont;
    delete quit;
	delete anima;
}