#include "../include/main/engine.hpp"
#include <iostream>
#include <cstdlib>
#include <SDL3/SDL.h>
#include <memory>
#include <stdexcept>

int main(){
    
    // Create a unique pointer of type Engine
    std::unique_ptr<Engine> engine = std::make_unique<Engine>("Hello SLD3!", 600, 300);

    // Initialize the engine
    engine->initialize();
	
    // Output to signal that SDL has succeeded
    std::cout << "Hello SDL3!!!!" << std::endl;
    
    // While the engine is still running, update everything
    while(!engine->isDone()){
		engine->handleEvents();
        engine->update();
		engine->render();
    }
    return 0;
}