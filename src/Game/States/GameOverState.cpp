#include "GameOverState.h"

GameOverState::GameOverState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Try Again?");
	quitButton = new Button(ofGetWidth()/2, (ofGetHeight()/2)+40, 64, 50, "Quit");
	img1.load("images/pacman.png");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);

}
void GameOverState::tick() {
	startButton->tick();
	quitButton->tick();
	anim->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
	if(quitButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);

	}
}

void GameOverState::render() {
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
	startButton->render();
	quitButton->render();


}

void GameOverState::keyPressed(int key){
	
}

void GameOverState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
	quitButton->mousePressed(x, y);
}

void GameOverState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
	quitButton->reset();
}

void GameOverState::setScore(int sc){
    score = sc;
}

GameOverState::~GameOverState(){
	delete startButton;
	delete quitButton;
	delete anim;
}