#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <fstream>
#include <string>
#include "Texture.hpp"
#include "ErrorHandler.hpp"

#define TILE 20

class Grid {
    public:
        Grid(void);
        ~Grid(void);
        void	checkCollision(void);
        void	update(void);
        void	render(SDL_Renderer *);
    private:
        std::vector< std::vector<char> > grid;
        const char *filePath = "./assets/grid.txt";
};