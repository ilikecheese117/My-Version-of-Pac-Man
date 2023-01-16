#pragma once

#include "Powerup.h"

class StrawberryPowerup:public Powerup {   
    public:
        StrawberryPowerup();
        void activate();
        void tick();
};