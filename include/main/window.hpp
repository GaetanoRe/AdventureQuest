#include <SDL3/SDL.h>
#include <memory>
#include <string>
#pragma once

class Window{
    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_{nullptr, SDL_DestroyWindow};
        int width_;
        int height_;
        std::string title_;
    
    public:
        Window(std::string title, int width_, int height_);
        void initialize();
        SDL_Window * getRawWindow();
        int getWidth();
        int getHeight();
        std::string getTitle();

};