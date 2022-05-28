//
// Created by Tammy Lin on 5/9/22.
//

#include "Entity.h"
Entity::Entity(char *img_path, int xPos, int yPos) {
    image = SDL_LoadBMP(img_path);

}
