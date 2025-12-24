#include "display.hpp"

#include <SDL3/SDL_init.h>
#include <iostream>

using namespace std;

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        return 1;
    }

    Display display;
    display.start();

    cout << "hello world" << endl;

    SDL_Quit();
    return 0;
}
