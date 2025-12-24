#include "display.hpp"

#include <SDL3/SDL_video.h>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

Display::Display(size_t width, size_t height, size_t windowScale) {
    _width = width;
    _height = height;
    _windowScale = windowScale;

    _frameBuffer = new uint8_t[width * height * 4];

    _window = SDL_CreateWindow(
            "Chip-8",
            width * windowScale,
            height * windowScale,
            0);
    _renderer = SDL_CreateRenderer(_window, NULL);
    _texture = SDL_CreateTexture(_renderer,
            SDL_PixelFormat::SDL_PIXELFORMAT_ARGB8888,
            SDL_TextureAccess::SDL_TEXTUREACCESS_STREAMING,
            width,
            height);

    assert(_frameBuffer);
    assert(_window);
    assert(_renderer);
    assert(_texture);
}

Display::~Display() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyTexture(_texture);

    delete[] _frameBuffer;
}

void Display::eventHandler(SDL_Event& e) {
    if (e.type == SDL_EventType::SDL_EVENT_QUIT) {
        _done = true;
    }
    if (e.type == SDL_EventType::SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE) {
        _done = true;
    }
}

void Display::start() {
    _done = false;

    SDL_Event e;
    while (!_done) {
        if (SDL_PollEvent(&e)) {
            eventHandler(e);
        }

        uint8_t* pixels;
        int pitch;

        SDL_LockTexture(_texture, NULL, (void**)&pixels, &pitch);
        copy(_frameBuffer, _frameBuffer + (_width * _height * 4), pixels);
        SDL_UnlockTexture(_texture);

        SDL_RenderTexture(_renderer, _texture, NULL, NULL);
        SDL_RenderPresent(_renderer);
    }
}
