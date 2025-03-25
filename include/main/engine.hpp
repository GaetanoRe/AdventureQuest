#include "window.hpp"
#include "../rendering/renderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <memory>
#include <stdexcept>
#include <string>

class Engine{

    private:
        Window m_windowData;
		Renderer m_rendererData;
		std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
		std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
        bool done_;
        void stop();
    
    public:
        Engine(std::string winTitle, int winWidth, int winHeight);
		~Engine();
        void initialize();
		void handleEvents();
        void update();
		void render();
        bool isDone();

};