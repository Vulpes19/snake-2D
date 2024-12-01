#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <fstream>
#include <string>
#include "Texture.hpp"
#include "ErrorHandler.hpp"
#include "CollisionObserver.hpp"

#define TILE 20
#define WIDTH 800
#define HEIGHT 600

class Grid : public CollisionObserver {
    public:
        Grid(void);
        ~Grid(void);
        COLLISION	checkCollision(Vector) override;
        void	    update(void);
        void	    render(SDL_Renderer *);
    private:
        std::vector< std::vector<char> > grid;
        const char                       *filePath = "./assets/grid.txt";
        Vector  foodSpawnPoint;
};