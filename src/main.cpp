#include "../include/engine.hpp"
#include <iostream>
#include <cstdlib>
#include <SDL3/SDL.h>
#include <memory>
#include <stdexcept>

int main(){
    
    // Create a unique pointer of type Engine
    std::unique_ptr<Engine> engine = std::make_unique<Engine>();

    // Initialize the engine
    engine.get()->initialize();

    // Output to signal that SDL has succeeded
    std::cout << "Hello SDL3!!!!" << std::endl;
    
    // While the engine is still running, update everything
    while(!engine.get()->isDone()){
        engine.get()->update();
    }

    // Clean Up SDL when finished
    SDL_Quit();
    return 0;
}