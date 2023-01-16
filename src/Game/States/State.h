#pragma once

#include "ofMain.h"

class State {
	public:
		State() {}
		virtual void reset() = 0;
		virtual void tick() = 0;
		virtual void render() = 0;
		virtual void keyPressed(int key) = 0;
		virtual void mousePressed(int x, int y, int button) = 0;

		virtual void keyReleased(int key){}
		void mouseMoved(int x, int y){}
		void mouseDragged(int x, int y, int button){}
		void mouseReleased(int x, int y, int button){}
		void mouseEntered(int x, int y){}
		void mouseExited(int x, int y){}
		void windowResized(int w, int h){}
		void gotMessage(ofMessage msg){}
		void dragEvent(ofDragInfo dragInfo){}
		int getLvlSelect(){
			return lvl_select;
		}
		bool hasFinished(){
			return finished;
		}
		bool getChange(){
			return change;
		}
		bool getMapChange(){
			return changeMap;
		}
		string getNextMap(){
			return maps[lvl_select];
		}
		string getNextState(){
			return nextState;
		}
		string getPlayerModel(){
			return playerModel;
		}
		string getPlayMap(){
			return play_map;
		}
		void setFinished(bool finished){
			this->finished = finished;
		}
		void setChange(bool change){
			this->change = change;
		}
		void setMapChange(bool mapChange){
			changeMap = mapChange;
		}
		void setNextState(string nextState){
			this->nextState = nextState;
		}
		void setPlayerModel(string playerModel){ 
			this->playerModel = playerModel;
		}
		void setPlayMap(string map){
			play_map = map;
		}
		bool goToNextLevel(){
			return nextLevel;
			}
        void setNextLevel(bool nextLevel){
			this->nextLevel = nextLevel;
		}
		void setLvlSelect(int lvl_select){
			this->lvl_select = lvl_select;
		}

	private:
		string playerModel = "images/pacman.png";
		string play_map = "images/map1.png";
		std::vector<string> maps = {"images/map1.png", "images/map2.png", "images/map3.png", "images/map4.png"};
		string nextState;
		int lvl_select = 0;
		bool finished = false;
		bool change = false;
		bool changeMap = false;
		bool nextLevel = false;

};