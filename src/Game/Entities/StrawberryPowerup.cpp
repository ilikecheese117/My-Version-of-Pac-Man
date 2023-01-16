#include "StrawberryPowerup.h"

StrawberryPowerup::StrawberryPowerup(){
    setPowerupState(false);
}

void StrawberryPowerup::tick() {
    if(getPowerupState()) {
            setPowerupState(false);
            setCurrentPowerup("");
        }
    }


void StrawberryPowerup::activate() {
    setCurrentPowerup("Invincible");
    setPowerupState(true);
}