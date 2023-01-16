#pragma once
#include "ofMain.h"

class Powerup {
    private:
        string currpowerup;
        bool powerupState;

    public:
        Powerup() {}
        virtual void activate() = 0;
        virtual void tick() = 0;

        void setCurrentPowerup(string currpowerup) { this->currpowerup = currpowerup; }
        string getCurrentPowerup(){ return currpowerup; }

        void setPowerupState(bool powerupState) { this->powerupState = powerupState; };
        bool getPowerupState() { return powerupState; }
};