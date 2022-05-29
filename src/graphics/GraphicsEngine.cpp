//
// Created by Tammy Lin on 5/9/22.
//

#include "GraphicsEngine.h"
namespace GraphicsEngine {

    void GraphicsEngine::init(SDL_Surface &global_surface) {
        GraphicsEngine::surface = global_surface;

    }

    void GraphicsEngine::draw(){
        for(int i = 0; i < entities.size(); i++){
            entities[i] -> draw(GraphicsEngine::surface);
        }
    }

    void GraphicsEngine::update(){
        for(int i = 0; i < entities.size(); i++){
            entities[i] -> update();
        }

    }

    void GraphicsEngine::addEntity(Entity* newEntity){
        entities.push_back(newEntity);
    }

}