#include "../include/rendering/renderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdexcept>
#include <iostream>

Renderer::Renderer(std::shared_ptr<Window> window) : windowRef_(window){
    if(auto windowShared = windowRef_.lock()){
        renderer_.reset(SDL_CreateRenderer(windowShared->getRawWindow(),NULL));
        if (!renderer_) {
            std::cerr << "SDL failed to create Renderer " << SDL_GetError() << std::endl;
            throw std::runtime_error("Cannot initialize the renderer");
        }
    }
    else{
        std::cerr << "The window reference was null ";
        throw std::runtime_error("Window reference is null, cannot be instantiated");
    }
}

void Renderer::update(){
    if(auto windowShared = windowRef_.lock()){
        if(renderer_){
            
        }
    }
}

SDL_Renderer * Renderer::getRawRenderer(){
    return renderer_.get();
}

void Renderer::setWindow(std::shared_ptr<Window> window){
    windowRef_ = window;
}



