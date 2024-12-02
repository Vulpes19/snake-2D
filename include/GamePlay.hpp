#pragma once

#include "GameState.hpp"
#include "InputObserver.hpp"
#include "Player.hpp"
#include "InputManager.hpp"
#include "StatesManager.hpp"
#include "Grid.hpp"
#include "UILabel.hpp"
#include "PauseMenu.hpp"

class GamePlay : public GameState, public InputObserver
{
	public:
		GamePlay(InputManager *, SDL_Renderer*);
		~GamePlay(void);
		void handleInput(void) override;
		void keyDown(SDL_Scancode, double, InputManager*, SDL_Renderer *) override;
		void mouseMove(Uint8, InputManager*, SDL_Renderer*) override;
		void update(double = 0) override;
		void render(SDL_Renderer *) override;
	private:
		Grid* 		grid = nullptr;
		GameObject* player = nullptr;
		size_t		score = 0;
};