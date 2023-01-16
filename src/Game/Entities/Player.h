#pragma once

#include "Animation.h"
#include "EntityManager.h"
#include "DSPowerup.h"
#include "CherryPowerup.h"
#include "StrawberryPowerup.h"
#include "RandomPowerup.h"

enum MOVING {
	MUP,
	MDOWN,
	MLEFT,
	MRIGHT,
};
class Player: public Entity{

    private:
        int spawnX, spawnY;
        unsigned int health=3;
        int score=0;
        int count=0;
        bool canMoveUp, canMoveDown, canMoveRight, canMoveLeft;
        int speed = 4;
        int pixels = 0;
        bool walking = false;
        bool pause = false;
        bool invicible = false;
        MOVING moving;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        ofSoundPlayer chomp;
        ofSoundPlayer eaten;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;
        Powerup *currentPowerup;
	    DSPowerup *dsPowerup;
        CherryPowerup *cherryPowerup;
        StrawberryPowerup *strawberryPowerup;
        RandomPowerup *randomPowerup;
        

    public:
        Player(int, int, int , int, EntityManager*);
        ~Player();
        int getHealth();
        int getScore();
        int getXCoor();
        int getYCoor();
        EntityManager* getEntMan();
        FACING getFacing();
        bool getPause(); 
        void setPause();
        void setHealth(int);
        void setScore(int);
        void setXCoor(int);
        void setYCoor(int);
        void setFacing(FACING facing);
        void loadSprite(string file);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void checkCollisions();
        void checkPowerup();
        void die();
};