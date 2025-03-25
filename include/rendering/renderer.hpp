#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <memory>
#include <stdexcept>
#pragma once

class Renderer{
    private:
        SDL_Renderer * renderer_;
    
    public:
        Renderer();
        void setRenderer(SDL_Renderer * renderer);
        SDL_Renderer * getRenderer();

};