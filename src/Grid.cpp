#include "Grid.hpp"

Grid::Grid(void) {
    std::ifstream file(filePath);

    if (!file.is_open())
        throw(ErrorHandler("Failed to load level file: " + std::string(filePath), __FILE__, __LINE__));
    
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

}