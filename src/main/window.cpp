#include "../../include/main/window.hpp"
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
Window::Window(std::string title, int width, int height) : title_(title), width_(width), height_(height), window_(nullptr){}

/*
    Title: Window setWindow function
    Description: sets the reference to the window.
*/
void Window::setWindow(SDL_Window * window){
	window_ = window;
}

/*
    Title: getRawWindow accessor function
    Description: Returns the raw window pointer
*/
SDL_Window * Window::getWindow(){
    return window_;
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

