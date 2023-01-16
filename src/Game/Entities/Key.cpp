#include "Key.h"

Key::Key(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 603, 49, 11, 16);
}