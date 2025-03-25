#include "../../include/main/engine.hpp"
#include "../../include/main/window.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <string>

/*
    Title: Engine defualt constructor
    Description: initializes the values that will be passed through each
    component of the engine and preps it for the main game loop
*/
Engine::Engine(std::string windowTitle, int winWidth, int winHeight): 
	done_(false),
	m_windowData(windowTitle, winWidth, winHeight), 
	m_rendererData(),
	m_window(nullptr, SDL_DestroyWindow),
	m_renderer(nullptr, SDL_DestroyRenderer){}

/*
    Title: initialize function
    Description: initializes all components being utilized with the values passed through
*/
void Engine::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Window* rawWindow;
    SDL_Renderer* rawRenderer;

    if (SDL_CreateWindowAndRenderer(m_windowData.getTitle().c_str(), m_windowData.getWidth(), m_windowData.getHeight(), 0, &rawWindow, &rawRenderer) < 0) {
        std::cerr << "Window and Renderer could not be created: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    m_window.reset(rawWindow);
    m_renderer.reset(rawRenderer);

    m_windowData.setWindow(rawWindow);
    m_rendererData.setRenderer(rawRenderer);
}

Engine::~Engine(){
	SDL_Quit();
}

void Engine::handleEvents(){
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
    Title: update function
    Description: updates every component while waiting for events.
*/
void Engine::update(){
    // Game Logic Here
}
void Engine::render(){
	SDL_Renderer* renderer = m_renderer.get();

    if (renderer) {

        if (renderer == nullptr){
            std::cout << "Renderer is a null pointer" << std::endl;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_FRect rect = {100.0f, 100.0f, 50.0f, 50.0f};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
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