#pragma once 

#include "State.h"
#include "Animation.h"
#include "Button.h"

class WinState: public State {
    private:
	    ofImage winPose;
        Button *next;
	    Button *cont;
        Button *quit;
	    Animation* anima;
        int score = 0;

    public:
        WinState();
        ~WinState();
        void setScore(int sc);
        void tick();
        void render();
        void reset();
        void mousePressed(int x, int y, int button);
        void keyPressed(int key);
};          