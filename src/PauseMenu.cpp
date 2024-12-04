#include "PauseMenu.hpp"

PauseMenu::PauseMenu(void)
{
	std::cout << "pause menu is pushed" << std::endl;
	stateName = PauseMenuState;
	label.addButtonType("PauseMenu", 100, 50, { 136, 8, 8, 255 });
	buttonsState["Resume"] = FOCUS_ON;
	buttonsState["Quit"] = FOCUS_OFF;
}

PauseMenu::~PauseMenu(void)
{}

void	PauseMenu::keyDown(SDL_Scancode key, double deltaTime, InputManager* input, SDL_Renderer*)
{
	if (InputDetector::getInstance()->isKeyPressed(key) && StatesManager::getInstance()->getCurrentState() == PauseMenuState)
	{
		if (key == SDL_SCANCODE_DOWN)
		{
			buttonsState["Resume"] = FOCUS_OFF;
			buttonsState["Quit"] = FOCUS_ON;
		}
		if (key == SDL_SCANCODE_UP)
		{
			buttonsState["Resume"] = FOCUS_ON;
			buttonsState["Quit"] = FOCUS_OFF;
		}
		if (key == SDL_SCANCODE_RETURN && buttonsState["Resume"] == FOCUS_ON)
		{
			StatesManager::getInstance()->removeState(input);
            return ;
		}
		if (key == SDL_SCANCODE_RETURN && buttonsState["Quit"] == FOCUS_ON)
        {
			StatesManager::getInstance()->removeState(2, input);
            return ;
        }
	}
}

void	PauseMenu::mouseMove(Uint8 mouseButton, InputManager* input, SDL_Renderer*)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= (WIDTH - 80) / 2 && x <= (WIDTH - 80) / 2 + 100 && y >= 300 && y <= 350 && StatesManager::getInstance()->getCurrentState() == PauseMenuState)
	{
		buttonsState["Resume"] = FOCUS_ON;
		buttonsState["Quit"] = FOCUS_OFF;
		if (mouseButton == SDL_BUTTON_LEFT)
		{
			StatesManager::getInstance()->removeState(input);
			//std::cout << "replacing observer " << StatesManager::getInstance()->getCurrentState() << std::endl;
			//InputObserver* observer = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			//if (observer)
				//input->addObserver(observer);
		}
	}
	if (x >= (WIDTH - 80) / 2 && x <= (WIDTH - 80) / 2 + 100 && y >= 400 && y <= 450 && StatesManager::getInstance()->getCurrentState() == PauseMenuState)
	{
		buttonsState["Resume"] = FOCUS_OFF;
		buttonsState["Quit"] = FOCUS_ON;
		if (mouseButton == SDL_BUTTON_LEFT)
		{
			StatesManager::getInstance()->removeState(2, input);
			std::cout << "********** after **********"<< std::endl;
			// InputObserver* observer = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			// if (observer)
			// 	input->addObserver(observer);
		}
	}
}

void	PauseMenu::handleInput(void)
{

}

void	PauseMenu::update(double)
{

}

void	PauseMenu::render(SDL_Renderer* renderer)
{
	label.render((WIDTH - 100) / 2, 300, 2, "PauseMenu", "Resume", "SIXTY", renderer, buttonsState["Resume"]);
	label.render((WIDTH - 100) / 2, 400, 2, "PauseMenu", "Quit", "SIXTY", renderer, buttonsState["Quit"]);
}