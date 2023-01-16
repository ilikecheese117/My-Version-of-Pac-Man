#include "CherryPowerup.h"

CherryPowerup::CherryPowerup(){
    setPowerupState(false);
}

void CherryPowerup::tick() {
    if(getPowerupState()) {
            setPowerupState(false);
            setCurrentPowerup("");
    }
}

void CherryPowerup::activate() {
    setCurrentPowerup("Random");
    setPowerupState(true);
}