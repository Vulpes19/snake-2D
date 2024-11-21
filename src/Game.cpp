#include "Game.hpp"
#include "ErrorHandler.hpp"

#define WIDTH 600
#define HEIGHT 300

Game::Game(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw(ErrorHandler("SDL failed to initialise: " + std::string(SDL_GetError()), __FILE__, __LINE__));

	window = SDL_CreateWindow("Raptor Island",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH,
		HEIGHT,
		0);
	if (window == NULL)
		throw(ErrorHandler("SDL window failed to initialise: " + std::string(SDL_GetError()), __FILE__, __LINE__));

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL)
		throw(ErrorHandler("SDL renderer failed to initialise: " + std::string(SDL_GetError()), __FILE__, __LINE__));

	//init game stuff
	running = true;
}

Game::~Game(void) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void    Game::handleInput(void) {
    while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				running = false;
				break;
		}
	}
}

void    Game::update(void) {

}

void    Game::render(void) {
    SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

bool    Game::isRunning(void) const {
    return (running);
}