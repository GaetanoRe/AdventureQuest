#include "../../include/rendering/renderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdexcept>
#include <iostream>

Renderer::Renderer() : renderer_(nullptr){}

void Renderer::setRenderer(SDL_Renderer * renderer){
    renderer_ = renderer;
}

SDL_Renderer * Renderer::getRenderer(){
    return renderer_;
}



