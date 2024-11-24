#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include "ErrorHandler.hpp"

class TextureManager {
    public:
        ~TextureManager(void);
        static TextureManager  *getInstance(void);
        void    loadTextures(SDL_Renderer *);
        SDL_Texture *getTexture(std::string);
    private:
        TextureManager(void);
        std::map<std::string, SDL_Texture *> textures;
        static TextureManager  *instance;
};