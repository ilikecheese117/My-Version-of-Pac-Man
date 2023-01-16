#pragma once

#include "Powerup.h"
#include "Entity.h"

class RandomPowerup:public Powerup {   
    public:
        RandomPowerup();
        void activate();
        void tick();
        int randomScore();
};