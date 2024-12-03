#include "MainMenu.hpp"

MainMenu::MainMenu(void)
{
	stateName = MainMenuState;
	label.addButtonType("MainMenu", 80, 200, { 136, 8, 8, 255 });
	buttonsState["Play"] = FOCUS_ON;
	buttonsState["Quit"] = FOCUS_OFF;
}

MainMenu::~MainMenu(void)
{}

void	MainMenu::keyDown(SDL_Scancode key, double deltaTime, InputManager *input, SDL_Renderer* renderer)
{
	if (InputDetector::getInstance()->isKeyPressed(key) && StatesManager::getInstance()->getCurrentState() == MainMenuState)
	{
		if (key == SDL_SCANCODE_DOWN)
		{
			buttonsState["Play"] = FOCUS_OFF;
			buttonsState["Quit"] = FOCUS_ON;
		}
		if (key == SDL_SCANCODE_UP)
		{
			buttonsState["Play"] = FOCUS_ON;
			buttonsState["Quit"] = FOCUS_OFF;
		}
		if (key == SDL_SCANCODE_RETURN && buttonsState["Play"] == FOCUS_ON)
		{
			std::cout << "gameplay is pushed" << std::endl;
			StatesManager::getInstance()->addState(new GamePlay(input, renderer));
			InputObserver* GamePlayObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			if (GamePlayObserver)
				input->addObserver(GamePlayObserver);
			else
				throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
		}
		if (key == SDL_SCANCODE_RETURN && buttonsState["Quit"] == FOCUS_ON)
			StatesManager::getInstance()->removeState(input);
	}
}

void	MainMenu::mouseMove(Uint8 mouseButton, InputManager* input, SDL_Renderer *renderer)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= 540 && x <= 740 && y >= 300 && y <= 380 && StatesManager::getInstance()->getCurrentState() == MainMenuState)
	{
		buttonsState["Play"] = FOCUS_ON;
		buttonsState["Quit"] = FOCUS_OFF;
		if (mouseButton == SDL_BUTTON_LEFT)
		{
			std::cout << "gameplay is pushed" << std::endl;
			StatesManager::getInstance()->addState(new GamePlay(input, renderer));
			InputObserver* GamePlayObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			if (GamePlayObserver)
				input->addObserver(GamePlayObserver);
			else
				throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
		}
	}
	if (x >= 540 && x <= 740 && y >= 400 && y <= 480)
	{
		buttonsState["Play"] = FOCUS_OFF;
		buttonsState["Quit"] = FOCUS_ON;
		if (mouseButton == SDL_BUTTON_LEFT)
			StatesManager::getInstance()->removeState(input);
	}
}

void	MainMenu::handleInput(void)
{

}

void	MainMenu::update(double)
{

}

void	MainMenu::render(SDL_Renderer *renderer)
{
	label.render(540, 300, 2, "MainMenu", "Play", "Bangers", renderer, buttonsState["Play"]);
	label.render(540, 400, 2, "MainMenu", "Quit", "Bangers", renderer, buttonsState["Quit"]);
}