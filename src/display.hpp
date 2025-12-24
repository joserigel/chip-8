#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include <cstddef>
#include <cstdint>
#include <SDL3/SDL.h>

class Display {
    private:
        size_t _width;
        size_t _height;
        size_t _windowScale;

        bool _done;

        uint8_t* _frameBuffer;
        SDL_Texture* _texture;
        SDL_Renderer* _renderer;
        SDL_Window* _window;

        void eventHandler(SDL_Event& e);
    public:
        Display(size_t width = 64, size_t height = 32, size_t windowScale = 4);
        ~Display();
        void start();
};

#endif /* __DISPLAY_HPP__ */
