#include <iostream>
#include <SDL2/SDL.h>
#include "Game.hpp"

int main (int ac, char **av) {
    Game *game = new Game();
    while (game->isRunning())
    {
        game->handleInput();
        game->update();
        game->render();
    }
    delete game;
    return (0);
}
