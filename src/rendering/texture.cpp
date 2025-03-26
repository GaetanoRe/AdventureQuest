#include "../../include/rendering/texture.hpp"
#include "../../include/rendering/renderer.hpp"
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdexcept>
#include <iostream>

Texture::Texture(const std::string &filename, std::shared_ptr<Renderer> renderer): rendererRef_(renderer){
    SDL_Surface * surface = IMG_Load(filename.c_str());
    if(surface == nullptr){
        std::cerr << "IMG load error " << std::endl;
        return;
    }

    if(auto rendererShared = rendererRef_.lock()){
        texture_.reset(SDL_CreateTextureFromSurface(rendererShared->getRenderer(), surface));
    }

    width_ = surface->w;
    height_ = surface->h;
}

SDL_Texture * Texture::getRawTexture(){
    return texture_.get();
}

int Texture::getWidth() const{
    return width_;
}

int Texture::getHeight() const{
    return height_;
}



