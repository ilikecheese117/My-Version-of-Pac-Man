#include "RandomPowerup.h"

RandomPowerup::RandomPowerup(){
    setPowerupState(false);
}

void RandomPowerup::tick() {
    if(getPowerupState()) {
            setPowerupState(false);
            setCurrentPowerup("");
        }
    }


void RandomPowerup::activate() {
    setCurrentPowerup("Points");
    setPowerupState(true);
}

int RandomPowerup::randomScore(){
    return ofRandom(100, 900);
}