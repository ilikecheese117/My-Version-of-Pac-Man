#include "Orange.h"

Orange::Orange(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 521, 49, 16, 16);
}