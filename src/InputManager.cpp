#include "InputManager.hpp"

#include "InputManager.hpp"

InputManager::InputManager(void)
{}

InputManager::~InputManager(void)
{}

void	InputManager::addObserver(InputObserver* newObserver)
{
	std::cout << "new observer is added !" << std::endl;
	observers.push_back(newObserver);
	std::cout << "number of observers now: " << observers.size() << std::endl;
}

void	InputManager::eraseObserver(InputObserver* observer)
{
	auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end())
	    observers.erase(it);
	else
		std::cout << "not found" << std::endl;
	std::cout << "observer is erased !" << std::endl;
	std::cout << "number of observers now: " << observers.size() << std::endl;
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