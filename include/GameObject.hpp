#pragma once

#include "Vector.hpp"
#include "Texture.hpp"
#include <SDL.h>

#define MIN_X 0
#define MAX_X 800
#define MIN_Y 0
#define MAX_Y 600

// enum class TYPES
// {
// 	PLAYER,
// 	RAPTOR
// };

class GameObject
{
	public:
		GameObject(std::string);
		~GameObject(void);
		virtual void	update(size_t &);
		virtual void	render(SDL_Renderer *);
	protected:
		Vector	position;
		Vector	velocity;
		std::string	textureName;
};