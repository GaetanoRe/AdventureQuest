#include "../main/window.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <memory>
#include <stdexcept>
#pragma once

class Renderer{
    private:
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_{nullptr, SDL_DestroyRenderer};
        std::weak_ptr<Window> windowRef_;
    
    public:
        Renderer(std::shared_ptr<Window> window);
        void update();
        SDL_Renderer * getRawRenderer();
        void setWindow(std::shared_ptr<Window> window);

};