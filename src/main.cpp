#include <iostream>
#include <SDL2/SDL.h>
#include "Game.hpp"

int main (int ac, char **av) {
    try {
        Game *game = new Game();
        while (game->isRunning())
        {
            game->handleInput();
            game->update();
            game->render();
        }
        delete game;
    }
    catch (const ErrorHandler &e)
	{
		std::cerr << e.what() << " - " << "in file: " << e.getFile() << " line: " << e.getLine() << std::endl;
	}
    return (0);
}
