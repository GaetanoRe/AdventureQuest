#include <SDL3/SDL.h>
#include <memory>
#include <string>
#pragma once

class Window{
    private:
        SDL_Window * window_;
        int width_;
        int height_;
        std::string title_;
    
    public:
        Window(std::string title, int width_, int height_);
        void setWindow(SDL_Window * window);
        SDL_Window * getWindow();
        int getWidth();
        int getHeight();
        std::string getTitle();

};