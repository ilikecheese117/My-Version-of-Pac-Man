#pragma once

#include "Powerup.h"

class DSPowerup : public Powerup {
    private:
        int timer;
    
    public:
        DSPowerup();
        void activate();
        void tick();
};