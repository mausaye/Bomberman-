//
// Created by Tammy Lin on 5/9/22.
//

#ifndef BOMBERMAN2_0_GRAPHICSENGINE_H
#define BOMBERMAN2_0_GRAPHICSENGINE_H


#include <vector>
#include "../core/Entity.h"

namespace GraphicsEngine {

    void draw();

    void update();

    void addEntity(Entity* newEntity);

    void init(SDL_Surface &surface);

    std::vector<Entity*> entities;
    SDL_Surface surface;
};


#endif //BOMBERMAN2_0_GRAPHICSENGINE_H
