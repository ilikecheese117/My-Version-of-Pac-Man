#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h"

class ChooseCharacterState : public State {
	private:
	int selection = 0;
	bool change = false;
	State*  state;
	ofImage curr_sel;
	Button *back;
	Button *mr;
	Button *ms;
	Animation* anim;

	public:
		ChooseCharacterState();
		~ChooseCharacterState();
		void createCharacter(string selection);
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void reset();
};