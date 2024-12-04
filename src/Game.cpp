#include "Game.hpp"
#include "ErrorHandler.hpp"

Game::Game(void) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw(ErrorHandler("SDL failed to initialise: " + std::string(SDL_GetError()), __FILE__, __LINE__));
	
	window = SDL_CreateWindow("Snake",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH,
		HEIGHT,
		0);
	if (window == NULL)
		throw(ErrorHandler("SDL window failed to initialise: " + std::string(SDL_GetError()), __FILE__, __LINE__));

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL)
		throw(ErrorHandler("SDL renderer failed to initialise: " + std::string(SDL_GetError()), __FILE__, __LINE__));

	//init game stuff
	running = true;
	TextureManager::getInstance()->loadTextures(renderer);
	input = new InputManager();
	StatesManager::getInstance()->addState(new MainMenu());
	InputObserver* stateObserver = dynamic_cast<InputObserver*>(StatesManager::getInstance()->getCurrentStateInstance());
	if (stateObserver)
		input->addObserver(stateObserver);
	else
		throw(ErrorHandler("Can't cast state to an observer, causes the input to not work: ", __FILE__, __LINE__));
}

Game::~Game(void) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void    Game::handleInput(void) {
    while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				input->notifyOnKeyDown(event.key.keysym.scancode, deltaTime, renderer);
				break;
			case SDL_MOUSEMOTION:
				input->notifyOnMouseMove(0, renderer);
			case SDL_MOUSEBUTTONDOWN:
				input->notifyOnMouseMove(event.button.button, renderer);
		}
	}
}

void    Game::update(void) {
	if (StatesManager::getInstance()->getCurrentState() == NoState)
	{
		// TextureManager::clean();
		// FontManager::clean();
		running = false;
	}
	StatesManager::getInstance()->update(deltaTime);
}

void    Game::render(void) {
	// exit(1);
    SDL_RenderClear(renderer);
	STATES currentState = StatesManager::getInstance()->getCurrentState();
	StatesManager::getInstance()->render(renderer);
	SDL_RenderPresent(renderer);
}

bool    Game::isRunning(void) const {
    return (running);
}