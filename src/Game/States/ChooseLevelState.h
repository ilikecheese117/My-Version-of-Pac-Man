#pragma once

#include "State.h"
#include "Button.h"

class ChooseLevelState: public State {
    private:
	int selection = 0;
	bool change = false;
	State*  state;
	ofImage curr_sel;
	Button *mp4;
	Button *mp3;
    Button *mp2;
    Button *mp1;
	Button *leaveState;

	public:
		ChooseLevelState();
		~ChooseLevelState();
		void createMapImage(string selection);
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void reset();
};