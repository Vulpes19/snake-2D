#include "Player.hpp"

Player::Player(void) {
    playerTexture = TextureManager::getInstance()->getTexture("green");
    snakePos.push_back(Vector(400.0, 300.0));
}

Player::~Player(void) {
    snakePos.clear();
    SDL_DestroyTexture(playerTexture);
}

void    Player::handleInput(void) {

}

void    Player::update(void) {

}

void    Player::render(SDL_Renderer *renderer) {
    SDL_Rect src, dest;

    src.x = 0;
    src.y = 0;
    src.w = dest.w = TILE;
    src.h = dest.h = TILE;

    for (auto position : snakePos) {
        dest.x = (int)position.getX();
        dest.y = (int)position.getY();
        SDL_RenderCopyEx(renderer, playerTexture, &src, &dest, 0, 0, SDL_FLIP_NONE);
    }
}