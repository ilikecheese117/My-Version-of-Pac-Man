#include "MenuState.h"

MenuState::MenuState(){
	startButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "Start");
	chooseButton = new Button(ofGetWidth()/2-32, (ofGetHeight()/2)+60, 80, 50, "Choose character");
	chooseMButton = new Button(ofGetWidth()/2-32, (ofGetHeight()/2)+120, 60, 50, "Choose Level");
	bugButton = new Button(ofGetWidth()/2-32, (ofGetHeight()/2)+160, 150, 80, "Bonus!!");
	createCharacter(getPlayerModel());
}

void MenuState::createCharacter(string selection){
	img1.load(selection);
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    anim = new Animation(10, rightAnimframes);
}

void MenuState::tick() { 
	startButton->tick();
	chooseButton->tick();
	chooseMButton->tick();
	bugButton->tick();
	anim->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
	if(chooseButton->wasPressed()){
		setNextState("Choose");
		setFinished(true);

	}
	if(chooseMButton->wasPressed()){
		setNextState("ChooseM");
		setFinished(true);

	}
	if(bugButton->wasPressed()){
		funMusic.load("music/important_file.wav");
		funMusic.setMultiPlay(false);
		funMusic.play(); 
		while(funMusic.isPlaying()){}; //PS don't even bother trying to close the program :D
	}
}

void MenuState::render() {
	string title = "Pacman Project";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2-50, ofGetHeight()/2-100, 100, 100);
	startButton->render();
	chooseButton->render();
	chooseMButton->render();
	bugButton->render();


}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
	chooseButton->mousePressed(x, y);
	chooseMButton->mousePressed(x, y);
	bugButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
	chooseButton->reset();
	chooseMButton->reset();
	bugButton->reset();
}

MenuState::~MenuState(){
	delete startButton;
	delete chooseButton;
	delete chooseMButton;
	delete bugButton;
	delete anim;
}