#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "Grid.hpp"

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
        Grid    *grid = nullptr;
		SDL_Event	event;
		Uint32	prevTime;
		Uint32	currTime;
		double			deltaTime;
		bool	running = false;
};