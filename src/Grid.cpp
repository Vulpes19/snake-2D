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

COLLISION    Grid::checkCollision(Vector playerPos) {
    int col = static_cast<int>(playerPos.getX() / TILE);
	int row = static_cast<int>(playerPos.getY() / TILE);
	int col2 = static_cast<int>((playerPos.getX() + TILE) / TILE);
	int row2 = static_cast<int>((playerPos.getY() + TILE) / TILE);

    // std::cout << "x: " << foodSpawnPoint.getX() / TILE << " -- " << "y: " << foodSpawnPoint.getY() / TILE << std::endl;
    // std::cout << "pl x: " << col << " -- " << "y: " << row << std::endl;
    // std::cout << "pl ext x: " << col2 << " -- " << "y: " << row2 << std::endl;
    if (row >= 0 && row2 >= 0 && col >= 0 && col2 >= 0 && row < grid.size() && col < grid[row].size() && row2 < grid.size() && col2 < grid[row2].size()
		&& (grid[row][col] == '1' || grid[row2][col2] == '1' || grid[row][col2] == '1' || grid[row2][col] == '1'))
        return COLLISION::WALL;
    
	if (row >= 0 && row2 >= 0 && col >= 0 && col2 >= 0 && row < grid.size() && col < grid[row].size() && row2 < grid.size() && col2 < grid[row2].size()
		&& (grid[row][col] == '2' || grid[row2][col2] == '2' || grid[row][col2] == '2' || grid[row2][col] == '2'))
    {
        std::cout << "ATE IT" << std::endl;
        grid[foodSpawnPoint.getY() / TILE][foodSpawnPoint.getX() / TILE] = '0';
        foodSpawnPoint.setX(0.0);
        foodSpawnPoint.setY(0.0);
        return COLLISION::FOOD;
    }
    return COLLISION::NONE;        
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

    int rowMin = 1;
    int rowMax = 28;
    int colMin = 1;
    int colMax = 38;

    if (foodSpawnPoint.getX() == 0 && foodSpawnPoint.getY() == 0)
    {
        int randomRow = rand() % (rowMax - rowMin) + rowMin;
        int randomcol = rand() % (colMax - colMin) + colMin;

        foodSpawnPoint.setX(randomcol * TILE);
        foodSpawnPoint.setY(randomRow * TILE);
    }
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
			if (col == foodSpawnPoint.getX() / TILE && row == foodSpawnPoint.getY() / TILE)
			{
                grid[row][col] = '2';
				SDL_RenderCopyEx(renderer, yellow, &src, &dest, 0, 0, SDL_FLIP_NONE);
			}
			if (line[col] == '1')
			{
				SDL_RenderCopyEx(renderer, white, &src, &dest, 0, 0, SDL_FLIP_NONE);
			}
		}
            // std::cout << std::endl;
	}
}