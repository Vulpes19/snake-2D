#include "Player.hpp"

Player::Player(void) : GameObject("green") {
    snakePos.push_back(Vector(400.0, 300.0));
    velocity.setX(0.0);
    velocity.setY(0.0);
}

Player::~Player(void) {
    snakePos.clear();
}

void	Player::keyDown(SDL_Scancode key, double deltaTime, InputManager*, SDL_Renderer*) {

    if (InputDetector::getInstance()->isKeyPressed(key))
	{
		if (key == SDL_SCANCODE_S && velocity.getY() != -TILE)
		{
            direction = DIRECTION::DOWN;
		}
		if (key == SDL_SCANCODE_W && velocity.getY() != TILE)
		{
            direction = DIRECTION::TOP;
		}
		if (key == SDL_SCANCODE_A && velocity.getX() != TILE)
		{
            direction = DIRECTION::LEFT;
		}
		if (key == SDL_SCANCODE_D && velocity.getX() != -TILE)
		{
            direction = DIRECTION::RIGHT;
		}
	}
}

void    Player::update(void) {
    const int frameDelay = 100;
    Vector position = snakePos.front();

    switch (direction)
    {
    case DIRECTION::TOP:
        velocity.setY(-TILE);
        velocity.setX(0.0);
        break;
    case DIRECTION::DOWN:
        velocity.setY(TILE);
        velocity.setX(0.0);
        break;
    case DIRECTION::RIGHT:
        velocity.setY(0.0);
        velocity.setX(TILE);
        break;
    case DIRECTION::LEFT:
        velocity.setY(0.0);
        velocity.setX(-TILE);
        break;
    default:
        break;
    }
    position += velocity;

    snakePos.push_front(position);

    if (snakePos.size() > size)
        snakePos.pop_back();
    
    SDL_Delay(frameDelay);
}

void    Player::render(SDL_Renderer *renderer) {
    SDL_Texture* texture = TextureManager::getInstance()->getTexture(textureName);
    SDL_Rect src, dest;
    src.x = 0;
    src.y = 0;
    src.w = dest.w = TILE;
    src.h = dest.h = TILE;

    for (auto position : snakePos) {
        dest.x = (int)std::round(position.getX());
        dest.y = (int)std::round(position.getY());
        SDL_RenderCopyEx(renderer, texture, &src, &dest, 0, 0, SDL_FLIP_NONE);
    }
}