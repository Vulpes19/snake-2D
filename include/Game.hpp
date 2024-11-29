#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "Grid.hpp"
#include "Texture.hpp"
#include "StatesManager.hpp"
#include "GamePlay.hpp"

class Game {
    public:
        Game(void);
        ~Game(void);
        void	handleInput(void);
        void	update(void);
        void	render(void);
        bool	isRunning(void) const;
    private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
		SDL_Event	event;
        InputManager *input = nullptr;
		Uint32	prevTime;
		Uint32	currTime;
		double			deltaTime;
		bool	running = false;
};