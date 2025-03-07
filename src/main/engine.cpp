#include "../include/engine.hpp"
#include "../include/window.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <memory>
#include <stdexcept>
#include <string>

/*
    Title: Engine defualt constructor
    Description: initializes the values that will be passed through each
    component of the engine and preps it for the main game loop
*/
Engine::Engine(): done_(false){
    window_ = std::make_unique<Window>("Hello SDL3", 600, 300);
}

/*
    Title: initialize function
    Description: initializes all components being utilized with the values passed through
*/
void Engine::initialize(){
    window_.get()->initialize();
}

/*
    Title: update function
    Description: updates every component while waiting for events.
*/
void Engine::update(){
    // The current SDL Event being called
    SDL_Event event;

        // Wait for an event to be passed
        while(SDL_PollEvent(&event)){

            // If the user quits (pressed the x) then stop the whole engine
            if(event.type == SDL_EVENT_QUIT){
                stop();
            }
        }
}

/*
    Title: stop private function
    Description: Stops the update loop
*/
void Engine::stop(){
    done_ = true;
}

/*
    Title: isDone function
    Description: passes the status of the engine to the main method
*/
bool Engine::isDone(){
    return done_;
}