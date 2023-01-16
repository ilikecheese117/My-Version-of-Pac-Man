#include "EntityManager.h"
#include "Ghost.h"
void EntityManager::tick(){
    pacmanSpriteSheet.load("images/Background.png");
    if(killable){
        killableCounter--;
        if (killableCounter == 0){
            killable = false;
            for(Entity* entity : ghosts){
                Ghost* ghost = dynamic_cast<Ghost*>(entity); 
                ghost->setKillable(false);
            }
        }
    }
    
    for(unsigned int i=0;i<entities.size();i++){
        if(!entities[i]->remove){
            entities[i]->tick();

        }else{
            Entity* entityPointer = entities[i];
            entities.erase(entities.begin() + i--);
            delete entityPointer;

        }
    }

    for(BoundBlock* BoundBlock: boundBlocks){
        BoundBlock->tick();
    }
    for(unsigned int i=0;i<ghosts.size();i++){
        if(!ghosts[i]->remove){
            ghosts[i]->tick();

        }else{
            Ghost* ghostPtr = dynamic_cast<Ghost*>(ghosts[i]);
            ghosts.erase(ghosts.begin() + i--);
            delete ghostPtr;
        }
    }

}

void EntityManager::render(){
    for(Entity* entity: entities){
        entity->render();
    }
    for(BoundBlock* BoundBlock: boundBlocks){
        BoundBlock->render();
    }
    for(Entity* ghost: ghosts){
        ghost->render();
    }
}

void EntityManager::setKillable(bool k){
    killable = true;
    killableCounter=10*ofGetFrameRate();
    for(Entity* entity:ghosts){
        Ghost* ghost = dynamic_cast<Ghost*>(entity); 
        ghost->setKillable(true);
    }
}

bool EntityManager::getKillable(){
    return killable;
}

int EntityManager::getGhostsSize(){
    return ghosts.size();
}

EntityManager::~EntityManager(){
    for(Entity* e: boundBlocks) delete dynamic_cast<BoundBlock*>(e);

    for(Entity* e: ghosts) delete dynamic_cast<Ghost*>(e);

    for(Entity* e: entities) delete e;
    
    boundBlocks.clear();
    ghosts.clear();
    entities.clear();
}

int EntityManager::getAmountDots(){
    return entities.size();
}
bool EntityManager::getFruitMap(){
	return inMap;
}
void EntityManager::setFruitMap(bool f){
	inMap = f;
}
void EntityManager::createRandFruits(){
	int randNum = ofRandom(0, goodXCoor.size());
    int x = goodXCoor[randNum];
    int y = goodYCoor[randNum];
	orange = new Orange(x,y,16,16,pacmanSpriteSheet);
	fruits.push_back(orange);
	apple = new Apple(x,y,16,16,pacmanSpriteSheet);
	fruits.push_back(apple);
	galboss = new Galboss(x,y,15,15,pacmanSpriteSheet);
	fruits.push_back(galboss);
	bell = new Bell(x,y,16,17,pacmanSpriteSheet);
	fruits.push_back(bell);
	melon = new Melon(x,y,15,18,pacmanSpriteSheet);
	fruits.push_back(melon);
	key = new Key(x,y,11,17,pacmanSpriteSheet);
	fruits.push_back(key);
}