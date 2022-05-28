//
// Created by Tammy Lin on 5/9/22.
//

#ifndef BOMBERMAN2_0_CHARACTER_H
#define BOMBERMAN2_0_CHARACTER_H


#include "Entity.h"

class Character : public Entity {

    Character(char *img, int x, int y) : Entity(img, x, y){};

    void draw(SDL_Surface &bitmapSurface);
};


#endif //BOMBERMAN2_0_CHARACTER_H
