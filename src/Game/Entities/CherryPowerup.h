#pragma once

#include "Powerup.h"

class CherryPowerup:public Powerup {   
    public:
        CherryPowerup();
        void activate();
        void tick();
};