#include "window.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <memory>
#include <stdexcept>
#include <string>

class Engine{

    private:
        std::unique_ptr<Window> window_;
        bool done_;
        void stop();
    
    public:
        Engine();
        void initialize();
        void update();
        bool isDone();

};