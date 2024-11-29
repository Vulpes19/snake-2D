#include "InputManager.hpp"

#include "InputManager.hpp"

InputManager::InputManager(void)
{}

InputManager::~InputManager(void)
{}

void	InputManager::addObserver(InputObserver* newObserver)
{
	observers.push_back(newObserver);
}

void	InputManager::eraseObserver(InputObserver* observer)
{
	auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end())
	    observers.erase(it);
}

void	InputManager::notifyOnKeyDown(SDL_Scancode key, double deltaTime, SDL_Renderer *renderer)
{
	for (auto observer : observers)
	{
		if (observer)
			observer->keyDown(key, deltaTime, this, renderer);
	}
}

void	InputManager::notifyOnMouseMove(Uint8 mouseButton, SDL_Renderer* renderer)
{
	for (auto observer : observers)
	{
		// GameState* state = dynamic_cast<GameState*>(observer);
		// if (!state)
		// 	continue;
		observer->mouseMove(mouseButton, this, renderer);
	}
}