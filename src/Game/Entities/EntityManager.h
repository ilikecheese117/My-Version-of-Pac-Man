#pragma once

#include "BoundBlock.h"
#include "Apple.h"
#include "Bell.h"
#include "Galboss.h"
#include "Key.h"
#include "Melon.h"
#include "Orange.h"

class EntityManager {

public:
	~EntityManager();
	std::vector<int> goodXCoor;
	std::vector<int> goodYCoor;
	std::vector<Entity*> entities;
	std::vector<Entity*> fruits;
	void createRandFruits();
	void setFruitMap(bool);
    bool getFruitMap();
	std::vector<BoundBlock*> boundBlocks;
	std::vector<Entity*> ghosts;
	void tick();
	void render();
	void setKillable(bool);
	bool getKillable();
	int getAmountDots();
	int getGhostsSize();

private:
	bool killable = false;
	int killableCounter;
	bool inMap = false;
	ofImage pacmanSpriteSheet;
	Apple* apple;
    Bell* bell;
    Galboss* galboss;
    Key* key;
    Melon* melon;
    Orange* orange;
};