#pragma once 

#include "State.h"
#include "Animation.h"
#include "Button.h"

class PauseState : public State {
    private:
        ofImage pausePose;
        Button *resume;
        Button *quit;
        Animation* wait;
        int score = 0;
        bool quitFromPause = false;

    public:
        PauseState();
        ~PauseState();
        bool getQuit();
        void setScore(int sc);
        void setQuit(bool quit);
        void tick();
        void render();
        void reset();
        void mousePressed(int x, int y, int button);
        void keyPressed(int key);
        
};