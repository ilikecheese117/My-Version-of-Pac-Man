#include "Galboss.h"

Galboss::Galboss(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 569, 50, 15, 15);
}