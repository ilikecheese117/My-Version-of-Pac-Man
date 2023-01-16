#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "Cherry.h"
#include "Strawberry.h"
#include "Orange.h"
#include "Apple.h"
#include "Bell.h"
#include "Galboss.h"
#include "Key.h"
#include "Melon.h"


Player::Player(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height){
    spawnX = x;
    spawnY = y;
    eaten.load("music/eaten.wav");
    chomp.load("music/pacman_chomp.wav");
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);

    this->em = em;

    moving = MLEFT;

    dsPowerup = new DSPowerup();
    cherryPowerup = new CherryPowerup();
    currentPowerup = nullptr;
    
}

void Player::loadSprite(string file){
    sprite.load(file);
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);
    
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);


    this->em = em;

    moving = MLEFT;

    dsPowerup = new DSPowerup();
    cherryPowerup = new CherryPowerup();
    strawberryPowerup = new StrawberryPowerup();
    randomPowerup = new RandomPowerup();
    currentPowerup = nullptr;
    
}

void Player::tick(){

    checkCollisions();
    checkPowerup();

    if (moving == MUP && canMoveUp) 
        facing = UP;
    else if (moving == MDOWN && canMoveDown) 
        facing = DOWN;
    else if (moving == MLEFT && canMoveLeft) 
        facing = LEFT;
    else if (moving == MRIGHT && canMoveRight)
        facing = RIGHT;

    if(facing == UP && canMoveUp){
        y-= speed;
        walkUp->tick();
        if(strawberryPowerup->getPowerupState()) { pixels++; }
    }else if(facing == DOWN && canMoveDown){
        y+=speed;
        walkDown->tick();
        if(strawberryPowerup->getPowerupState()) { pixels++; }
    }else if(facing == LEFT && canMoveLeft){
        x-=speed;
        walkLeft->tick();
        if(strawberryPowerup->getPowerupState()) { pixels++; }
    }else if(facing == RIGHT && canMoveRight){
        x+=speed;
        walkRight->tick();
        if(strawberryPowerup->getPowerupState()) { pixels++; }
    }
}

void Player::render(){
    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds());

    if(!invicible) {
        if(facing == UP)
            walkUp->getCurrentFrame().draw(x, y, width, height);
        else if(facing == DOWN)
            walkDown->getCurrentFrame().draw(x, y, width, height);
        else if(facing == LEFT)
            walkLeft->getCurrentFrame().draw(x, y, width, height);
        else if(facing == RIGHT)
            walkRight->getCurrentFrame().draw(x, y, width, height);
    }
    
    ofSetColor(256, 0, 0);
    ofDrawBitmapString("Health: ", ofGetWidth()/2 + 100, 50);

    for(unsigned int i=0; i<health; i++){
        ofDrawCircle(ofGetWidth()/2 + 25*i +200, 50, 10);
    }
    ofDrawBitmapString("Score:"  + to_string(score), ofGetWidth()/2-200, 50);
}

void Player::keyPressed(int key){
    switch(key){
        case 'w':
        case 'W':
        case OF_KEY_UP:
            moving = MUP;
            break;
        case 's':
        case 'S':
        case OF_KEY_DOWN:
            moving = MDOWN;
            break;
        case 'a':
        case 'A':
        case OF_KEY_LEFT:
            moving = MLEFT;;
            break;
        case 'd':
        case 'D':
        case OF_KEY_RIGHT:
            moving = MRIGHT;;
            break;
        case 'n':
        case 'N':
            die();
            break;
        case 'm':
        case 'M':
            if(health < 3){
                health++;}
            break;
        case 'y':
        case 'Y':
            em -> entities = {};
            break;
        case 'p':
        case 'P':
            pause = true;
            break;
        case ' ':
            currentPowerup = dsPowerup;
            currentPowerup->activate();
            break;
    }
}

void Player::keyReleased(int key){
    if(key == 'w' || key == 'W' || key == OF_KEY_UP || key =='s' || key == 'S' || key == OF_KEY_DOWN || key == 'a' || key == 'A' || key == OF_KEY_LEFT || key == 'd' || key == 'D' || key == OF_KEY_RIGHT){
        walking = false;
    }
}
void Player::mousePressed(int x, int y, int button){

}

int Player::getHealth(){ return health; }
int Player::getScore(){ return score; }
int Player::getXCoor(){ return x; }
int Player::getYCoor(){ return y; }
bool Player::getPause(){ return pause; }
EntityManager* Player::getEntMan(){return em; }
FACING Player::getFacing(){ return facing; }

void Player::setHealth(int h){ health = h; }
void Player::setFacing(FACING facing){ this->facing = facing; }
void Player::setScore(int h){ score = h; }
void Player::setXCoor(int x){ this->x = x; }
void Player::setYCoor(int y){ this->y = y; }
void Player::setPause(){ pause = !pause; }


void Player::checkPowerup() {
    if (currentPowerup != nullptr) {
		if(currentPowerup->getCurrentPowerup() == "Double") {
			if(currentPowerup->getPowerupState()) { speed = 8; }
		}if(currentPowerup->getCurrentPowerup() == "Random") {
            if(currentPowerup->getPowerupState()) {
                int randNum = ofRandom(0, em->goodXCoor.size());
                x = em->goodXCoor[randNum];
                y = em->goodYCoor[randNum];
            }
        }if(currentPowerup->getCurrentPowerup() == "Invincible") {
            if(currentPowerup->getPowerupState()) {
                invicible = true;
            }
        }if(currentPowerup->getCurrentPowerup() == "Points") {
            if(currentPowerup->getPowerupState()) {
                score += randomPowerup->randomScore();
                randomPowerup->tick();
            }
        }if(!dsPowerup->getPowerupState()){ 
            speed = 4;
        }if(strawberryPowerup->getPowerupState()){ 
            if(pixels == 30){
                invicible = false; 
                strawberryPowerup->tick();
                pixels = 0;
            }
        }
        dsPowerup->tick();
        cherryPowerup->tick();
	}
}

void Player::checkCollisions(){
    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;
    
    for(BoundBlock* boundBlock: em->boundBlocks){
        if(this->getBounds(x, y-speed).intersects(boundBlock->getBounds()))
            canMoveUp = false;
        if(this->getBounds(x, y+speed).intersects(boundBlock->getBounds()))
            canMoveDown = false;
        if(this->getBounds(x-speed, y).intersects(boundBlock->getBounds()))
            canMoveLeft = false;
        if(this->getBounds(x+speed, y).intersects(boundBlock->getBounds()))
            canMoveRight = false;
    }
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity) || dynamic_cast<BigDot*>(entity) || dynamic_cast<Cherry*>(entity) || dynamic_cast<Strawberry*>(entity) || dynamic_cast<Orange*>(entity) || dynamic_cast<Apple*>(entity) || dynamic_cast<Melon*>(entity) || dynamic_cast<Key*>(entity) || dynamic_cast<Galboss*>(entity) || dynamic_cast<Bell*>(entity)){
                entity->remove = true;
                score += 10;
                count += 1;
                if(count % 3 == 0){
                    chomp.play();
                }
            }
            if(dynamic_cast<BigDot*>(entity)){
                score +=40;
                count+=1;
                em->setKillable(true);
                if(count % 3 == 0){
                    chomp.play();
                }
            }
            if(dynamic_cast<Cherry*>(entity)){
                eaten.play();
                score +=90;
                currentPowerup = cherryPowerup;
                currentPowerup->activate();
            }
            if(dynamic_cast<Strawberry*>(entity)){
                score += 290;
                currentPowerup = strawberryPowerup;
                currentPowerup->activate();
            }
            if(dynamic_cast<Orange*>(entity)){
                score += 290;
                currentPowerup = randomPowerup;
                currentPowerup->activate();
                em->setFruitMap(false);
                em->fruits.clear();
            }
            if(dynamic_cast<Apple*>(entity)){
                score += 290;
                currentPowerup = randomPowerup;
                currentPowerup->activate();
                em->setFruitMap(false);
                em->fruits.clear();
            }
            if(dynamic_cast<Melon*>(entity)){
                score += 290;
                currentPowerup = randomPowerup;
                currentPowerup->activate();
                em->setFruitMap(false);
                em->fruits.clear();
            }
            if(dynamic_cast<Key*>(entity)){
                score += 290;
                currentPowerup = randomPowerup;
                currentPowerup->activate();
                em->setFruitMap(false);
                em->fruits.clear();
            }
            if(dynamic_cast<Galboss*>(entity)){
                score += 290;
                currentPowerup = randomPowerup;
                currentPowerup->activate();
                em->setFruitMap(false);
                em->fruits.clear();
            }
            if(dynamic_cast<Bell*>(entity)){
                score += 290;
                currentPowerup = randomPowerup;
                currentPowerup->activate();
                em->setFruitMap(false);
                em->fruits.clear();
            }
        }
    }
    for(Entity* entity:em->ghosts){
        if(collides(entity)){
            Ghost* ghost = dynamic_cast<Ghost*>(entity);
            if(ghost->getKillable()){
                eaten.play();
                ghost->remove = true;}
            else if(!strawberryPowerup->getPowerupState()){
                die();
            }
        }
    }

    
}



void Player::die(){
    health--;
    x = spawnX;
    y = spawnY;

}

Player::~Player(){
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
}