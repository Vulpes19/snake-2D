#include "GameOver.hpp"

GameOver::GameOver(void)
{
	std::cout << "gameover menu is pushed" << std::endl;
	stateName = GameOverState;
	label.addButtonType("GameOver", 200, 80, { 136, 8, 8, 255 });
	buttonsState["Retry"] = FOCUS_ON;
}

GameOver::~GameOver(void)
{}

void	GameOver::clean(void)
{
	label.deleteButtonType("GameOver");
}

void	GameOver::keyDown(SDL_Scancode key, double deltaTime, InputManager *input, SDL_Renderer* renderer)
{
	if (InputDetector::getInstance()->isKeyPressed(key) && StatesManager::getInstance()->getCurrentState() == GameOverState)
	{
		if (key == SDL_SCANCODE_RETURN && buttonsState["Retry"] == FOCUS_ON)
        {
			StatesManager::getInstance()->removeState(2, input);
            return ;
        }
	}
}

void	GameOver::mouseMove(Uint8 mouseButton, InputManager* input, SDL_Renderer *renderer)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x >= (WIDTH - 200) / 2 && x <= (WIDTH - 200) / 2 + 100 && y >= 400 && y <= 480)
	{
		buttonsState["Retry"] = FOCUS_ON;
		if (mouseButton == SDL_BUTTON_LEFT)
		{
			StatesManager::getInstance()->removeState(input);
			return ;
		}
	}
	else
		buttonsState["Retry"] = FOCUS_OFF;
}

void	GameOver::handleInput(void)
{

}

void	GameOver::update(double)
{

}

void	GameOver::render(SDL_Renderer *renderer)
{
	label.render((WIDTH - 200) / 2, 300, 2, "GameOver", "Retry", "SIXTY", renderer, buttonsState["Retry"]);
}