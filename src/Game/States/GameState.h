#pragma once

#include "State.h"
#include "Player.h"
#include "MapBuilder.h"

class GameState: public State{
	private:
		ofImage mapImage;
		ofSoundPlayer siren;
		ofSoundPlayer power;
		ofSoundPlayer returning;
		Map* map;
		int finalScore=0;
	
	public: 
        GameState();
		~GameState();
		void rebuild();
		void reset();
		void tick();
		void render();
		void createPlayArea(string select);
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		Map* getMap();
		int getFinalScore();
};