#include "../include/window.hpp"
#include <SDL3/SDL.h>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
/*
    Title: Window Parameterized Constructor
    Description: Instantiates an object with details that will be activated later when the
    SDL window eventually gets initialized
*/
Window::Window(std::string title, int width, int height) : title_(title), width_(width), height_(height){}

/*
    Title: Window initialize function
    Description: initializes the SDL window with our information that we
    placed in the constructor
*/
void Window::initialize(){
    // Assign a window to the unique pointer with the given values
    window_.reset(SDL_CreateWindow(title_.c_str(), width_, height_, SDL_WINDOW_OPENGL));

    // If SDL fails to intitialize, throw a runtime error and output an error message
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        throw std::runtime_error("Could not initialize SDL video...");
    }

    // If the window is empty, then the window failed to initialize and we must throw a runtime error with 
    // a message
    if(window_.get() == NULL){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        throw std::runtime_error("Could Not initialize Window, Initialization failed");
    }
}

/*
    Title: getRawWindow accessor function
    Description: Returns the raw window pointer
*/
SDL_Window * Window::getRawWindow(){
    return window_.get();
}

/*
    Title: getWidth accessor method
    Description: Returns the width of the window
*/
int Window::getWidth(){
    return width_;
}


/*
    Title: getHeight accessor method
    Description: Returns the height of the window
*/
int Window::getHeight(){
    return height_;
}


/*
    Title: getTitle accessor method
    Description: Returns the title of the window
*/
std::string Window::getTitle(){
    return title_;
}

