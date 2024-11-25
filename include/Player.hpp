#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "Vector.hpp"
#include "Texture.hpp"
#include <deque>
#include "InputObserver.hpp"
#include "InputDetector.hpp"
#include "GameObject.hpp"

#define TILE 20

enum DIRECTION {
    RIGHT,
    LEFT,
    TOP,
    DOWN
};

class Player : public InputObserver, public GameObject {
    public:
        Player(void);
        ~Player(void);
        void    keyDown(SDL_Scancode , double , InputManager*, SDL_Renderer*) override;
        void	mouseMove(Uint8, InputManager* = nullptr, SDL_Renderer* = nullptr) override {};
        void    update(void) override;
        void    render(SDL_Renderer *) override;
    protected:
        std::deque<Vector>  snakePos;
        DIRECTION direction;
        size_t              size = 2;
};