#include "GamePlay.hpp"

GamePlay::GamePlay(InputManager *input, SDL_Renderer *renderer)
{
	stateName = GamePlayState;

	grid = new Grid();
	TextureManager::getInstance()->loadTextures(renderer);
	//creating player
	player = new Player();
	//add player as an observer to input
	InputObserver* playerObserver = dynamic_cast<InputObserver*>(player);
	if (playerObserver)
		input->addObserver(playerObserver);
	else
		throw(ErrorHandler("Can't cast player to an observer, causes the input to not work: ", __FILE__, __LINE__));
}

GamePlay::~GamePlay(void)
{}

void	GamePlay::keyDown(SDL_Scancode key, double deltaTime, InputManager* input, SDL_Renderer* renderer)
{
	// if (InputDetector::getInstance()->isKeyPressed(key) && StatesManager::getInstance()->getCurrentState() == GamePlayState)
	// {
	// 	if (key == SDL_SCANCODE_ESCAPE && StatesManager::getInstance()->getCurrentState() != PauseMenuState)
	// 	{
	// 		StatesManager::getInstance()->addState(new PauseMenu());
	// 		InputObserver* pauseObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
	// 		if (pauseObserver)
	// 			input->addObserver(pauseObserver);
	// 		else
	// 			throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
	// 	}
	// }
}

void	GamePlay::mouseMove(Uint8 mouseButton, InputManager* input, SDL_Renderer* renderer)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	//to add pause mouse click
	
}

void	GamePlay::handleInput(void)
{

}

void	GamePlay::update(double deltaTime)
{
	grid->update();
	player->update();;
}

void	GamePlay::render(SDL_Renderer *renderer)
{
	grid->render(renderer);
	player->render(renderer);
}