#include "Grid.hpp"

Grid::Grid(void) {
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        throw(ErrorHandler("Failed to load level file: " + std::string(filePath), __FILE__, __LINE__));
        exit(1);
    }
    std::string temp;
    std::vector<char> line;

    while (std::getline(file, temp)) {
        line.clear();
        std::copy(temp.begin(), temp.end(), std::back_inserter(line));
        grid.push_back(line);
    }
}

void    Grid::checkCollision(void) {

}

void    Grid::update(void) {

}

void    Grid::render(SDL_Renderer *renderer) {
    SDL_Rect src, dest;

    SDL_Texture *red = TextureManager::getInstance()->getTexture("red");
    SDL_Texture *yellow = TextureManager::getInstance()->getTexture("yellow");
    SDL_Texture *green = TextureManager::getInstance()->getTexture("green");
    SDL_Texture *blue = TextureManager::getInstance()->getTexture("blue");
    SDL_Texture *white = TextureManager::getInstance()->getTexture("white");

    for (unsigned int row = 0; row < grid.size(); row++)
	{
		std::vector<char> line = grid[row];
		for (unsigned int col = 0; col < line.size(); col++)
		{
            // std::cout << line[col];
			src.x = 0;
			src.y = 0;
			src.w = dest.w = TILE;
			src.h = dest.h = TILE;
			dest.x = col * TILE;
			dest.y = row * TILE;
			// if (line[col] == '0')
			// {
			// 	SDL_RenderCopyEx(renderer, ground, &src, &dest, 0, 0, SDL_FLIP_NONE);
			// }
			if (line[col] == '1')
			{
				SDL_RenderCopyEx(renderer, white, &src, &dest, 0, 0, SDL_FLIP_NONE);
			}
		}
            // std::cout << std::endl;
	}
}