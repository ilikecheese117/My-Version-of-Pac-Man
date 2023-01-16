#include "DSPowerup.h"

DSPowerup::DSPowerup() {
    setPowerupState(false);
}

void DSPowerup::tick() {
    if(getPowerupState()) {
        timer--;
        if(timer == 0) { 
            setPowerupState(false);
            setCurrentPowerup("");
        }
    }
}

void DSPowerup::activate() {
    setCurrentPowerup("Double");
    setPowerupState(true);
    timer = 10*ofGetFrameRate();
}