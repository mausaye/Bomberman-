//
// Created by Tammy Lin on 5/9/22.
//

#ifndef BOMBERMAN2_0_ENTITY_H
#define BOMBERMAN2_0_ENTITY_H


#include <string>
#include <SDL_surface.h>

class Entity {
public:

    // Animated sprite
    Entity(char *img, int numFrames, int columns, int rows, int speed, int x, int y);

    // Still sprite
    Entity(char *img, int x, int y);

    virtual void update();

    virtual void draw(SDL_Surface &bitmapSurface);

private:
    SDL_Surface *image;
    SDL_Rect position;
    int x;
    int y;
    int speed;
    int frames;


};


#endif //BOMBERMAN2_0_ENTITY_H
