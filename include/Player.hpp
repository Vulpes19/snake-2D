#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "Vector.hpp"
#include "Texture.hpp"
#include <deque>

#define TILE 20

class Player {
    public:
        Player(void);
        ~Player(void);
        void handleInput(void);
        void update(void);
        void render(SDL_Renderer *);
    private:
        std::deque<Vector>  snakePos;
        SDL_Texture         *playerTexture = nullptr;
        size_t              size = 1;
};