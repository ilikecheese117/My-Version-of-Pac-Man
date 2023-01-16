#include "ChooseCharacterState.h"

ChooseCharacterState::ChooseCharacterState(){
    mr = new Button(ofGetWidth()/2, (ofGetHeight()/2)+40,  80, 50, "  Mr. Pac-Man");
    ms = new Button(ofGetWidth()/2, (ofGetHeight()/2)+80,  80, 50, "  Mrs. Pac-Man");
	back = new Button(ofGetWidth()/2, (ofGetHeight()/2)+120,  60, 50, "  Go back");
	createCharacter("images/pacman.png");
}

void ChooseCharacterState::createCharacter(string selection){
	curr_sel.load(selection);
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(curr_sel, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    anim = new Animation(10, rightAnimframes);
}
void ChooseCharacterState::tick() {
	mr->tick();
    ms->tick();
	back->tick();
	anim->tick();
	if(selection != 0 && mr->isOnTop(ofGetMouseX(), ofGetMouseY())){
		selection = 0;
		createCharacter("images/pacman.png");

	}

	if(selection != 1 && ms->isOnTop(ofGetMouseX(), ofGetMouseY())){
		selection = 1;
		createCharacter("images/mspacman.png");
		
	}

	if(mr->wasPressed()){
		setPlayerModel("images/pacman.png");
		setNextState("Menu");
		setFinished(true);
		setChange(true);

	}
    if(ms->wasPressed()){
		setPlayerModel("images/mspacman.png");
		setNextState("Menu");
		setFinished(true);
		setChange(true);

	}
	if(back->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}

void ChooseCharacterState::render() {
	ofDrawBitmapString("Choose Your Character!", (ofGetWidth()/2)-20, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
	mr->render();
    ms->render();
	back->render();


}

void ChooseCharacterState::keyPressed(int key){
	
}

void ChooseCharacterState::mousePressed(int x, int y, int button){
	mr->mousePressed(x, y);
    ms->mousePressed(x, y);
	back->mousePressed(x, y);
}

void ChooseCharacterState::reset(){
	setFinished(false);
	setChange(false);
	setNextState("");
	mr->reset();
    ms->reset();
	back->reset();
}

ChooseCharacterState::~ChooseCharacterState(){
	delete mr; 
    delete ms;
	delete back;
	delete anim;
}