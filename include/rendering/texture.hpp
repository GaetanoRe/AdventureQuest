#include "renderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <memory>
#include <stdexcept>
#include <string>
#pragma once

class Texture{
    private:
        std::weak_ptr<Renderer> rendererRef_;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture_{nullptr, SDL_DestroyTexture};
        int width_;
        int height_;

    public:
        Texture(const std::string &filepath, std::shared_ptr<Renderer> renderer);
        SDL_Texture * getRawTexture();
        int getWidth() const;
        int getHeight() const;

};