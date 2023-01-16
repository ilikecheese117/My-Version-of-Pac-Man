#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 
class GameOverState : public State {
private:
	ofImage img1;
	Button *startButton;
	Button *quitButton;
	Animation* anim;
	int score = 0;
	
public:
	GameOverState();
	~GameOverState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void setScore(int sc);
};
