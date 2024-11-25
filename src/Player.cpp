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
		if (key == SDL_SCANCODE_S)
		{
            direction = DIRECTION::DOWN;
		}
		if (key == SDL_SCANCODE_W)
		{
            direction = DIRECTION::TOP;
		}
		if (key == SDL_SCANCODE_A)
		{
            direction = DIRECTION::LEFT;
		}
		if (key == SDL_SCANCODE_D)
		{
            direction = DIRECTION::RIGHT;
		}
	}
}

void    Player::update(void) {
    Vector position = snakePos.front();

    switch (direction)
    {
    case DIRECTION::TOP:
        velocity.setY(-0.2);
        velocity.setX(0.0);
        break;
    case DIRECTION::DOWN:
        velocity.setY(0.2);
        velocity.setX(0.0);
        break;
    case DIRECTION::RIGHT:
        velocity.setY(0.0);
        velocity.setX(0.2);
        break;
    case DIRECTION::LEFT:
        velocity.setY(0.0);
        velocity.setX(-0.2);
        break;
    default:
        break;
    }
    position += velocity;

    snakePos.push_front(position);

    if (snakePos.size() > size)
        snakePos.pop_back();
}

void    Player::render(SDL_Renderer *renderer) {
    SDL_Texture* texture = TextureManager::getInstance()->getTexture(textureName);
    SDL_Rect src, dest;
    src.x = 0;
    src.y = 0;
    src.w = dest.w = TILE;
    src.h = dest.h = TILE;

    for (auto position : snakePos) {
        dest.x = (int)position.getX();
        dest.y = (int)position.getY();
        SDL_RenderCopyEx(renderer, texture, &src, &dest, 0, 0, SDL_FLIP_NONE);
    }
}