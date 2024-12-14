#include "GamePlay.hpp"

GamePlay::GamePlay(InputManager *input, SDL_Renderer *renderer) : input(input)
{
	std::cout << "gameplay menu is pushed" << std::endl;
	stateName = GamePlayState;

	grid = new Grid();
	TextureManager::getInstance()->loadTextures(renderer);
	//creating player
	player = new Player();
	//add grid as observer to player
	Player *playerCollider = dynamic_cast<Player*>(player);
	if (playerCollider)
		playerCollider->addObserver(grid);
	else
		throw(ErrorHandler("casting error, causes the collision to not work: ", __FILE__, __LINE__));
	//add player as an observer to input
	InputObserver* playerObserver = dynamic_cast<InputObserver*>(player);
	if (playerObserver)
		input->addObserver(playerObserver);
	else
		throw(ErrorHandler("Can't cast player to an observer, causes the input to not work: ", __FILE__, __LINE__));
	label.addButtonType("GamePlay", 80, 20, { 0, 0, 0, 255 });
}

GamePlay::~GamePlay(void)
{
	// InputObserver* observer = dynamic_cast<InputObserver*>(player);
	// if (observer) {
	// 	input->eraseObserver(observer);
	// }
	// label.deleteButtonType("GamePlay");
	// delete grid;
	// delete player;
}

void	GamePlay::clean(void)
{
	InputObserver* observer = dynamic_cast<InputObserver*>(player);
	if (observer) {
		input->eraseObserver(observer);
	}
	// delete grid;
	// delete player;
	label.deleteButtonType("GamePlay");
}

void	GamePlay::keyDown(SDL_Scancode key, double deltaTime, InputManager* input, SDL_Renderer* renderer)
{
	if (InputDetector::getInstance()->isKeyPressed(key) && StatesManager::getInstance()->getCurrentState() == GamePlayState)
	{
		if (key == SDL_SCANCODE_ESCAPE && StatesManager::getInstance()->getCurrentState() != PauseMenuState)
		{
			StatesManager::getInstance()->addState(new PauseMenu());
			InputObserver* pauseObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			if (pauseObserver)
				input->addObserver(pauseObserver);
			else
				throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
		}
	}
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
	player->update(score);
	if (player->isWasted())
	{
		StatesManager::getInstance()->addState(new GameOver());
		InputObserver* gameOverObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
			if (gameOverObserver)
				input->addObserver(gameOverObserver);
			else
				throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
	}
}

void	GamePlay::render(SDL_Renderer *renderer)
{
	grid->render(renderer);
	player->render(renderer);
	label.render((WIDTH - 80) / 2, 0, 1, "GamePlay", "score: " + std::to_string(score), "SIXTY", renderer, FOCUS_ON);
}