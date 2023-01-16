#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class MenuState : public State {
private:
	ofImage img1;
	ofSoundPlayer funMusic;
	Button *startButton;
	Button *chooseButton;
	Button *bugButton;
	Button *chooseMButton;
	Animation* anim;

public:
	MenuState();
	~MenuState();
	void createCharacter(string selection);
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
