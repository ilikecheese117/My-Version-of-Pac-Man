#include "Bell.h"

Bell::Bell(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 585, 49, 16, 17);
}