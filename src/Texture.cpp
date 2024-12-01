#include "Texture.hpp"

TextureManager *TextureManager::instance = nullptr;

TextureManager::TextureManager(void)
{
	if (IMG_Init(IMG_INIT_PNG) < 0)
		throw(ErrorHandler("SDL_image failed to initialize: " + std::string(IMG_GetError()), __FILE__, __LINE__));
}

TextureManager::~TextureManager(void) {
    for (auto it = textures.begin(); it != textures.end(); ++it) {
        SDL_DestroyTexture(it->second);
    }
    textures.clear();
}

void    TextureManager::loadTextures(SDL_Renderer *renderer) {
    std::vector<const char *> texturesPaths;

    texturesPaths.push_back("./assets/red.png");
    texturesPaths.push_back("./assets/green.png");
    texturesPaths.push_back("./assets/yellow.png");
    texturesPaths.push_back("./assets/blue.png");
    texturesPaths.push_back("./assets/white.png");

    std::vector<SDL_Surface *> surfaces;

    for (auto &path : texturesPaths) {
        SDL_Surface *surface = IMG_Load(path);
        if (surface == NULL)
            throw(ErrorHandler("SDL failed to load surface from image: " + std::string(IMG_GetError()), __FILE__, __LINE__));
        else
            surfaces.push_back(surface);
    }

    for (auto i = 0 ; i < surfaces.size() && i < texturesPaths.size(); i++) {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surfaces[i]);
        SDL_FreeSurface(surfaces[i]);
        if (texture == NULL)
            throw(ErrorHandler("SDL failed to load texture from surface: " + std::string(IMG_GetError()), __FILE__, __LINE__));
        std::string key = std::string(texturesPaths[i]).substr(9, std::string(texturesPaths[i]).length() - 13);
        // std::cout << key << std::endl;
        textures[key] = texture;
    }
    surfaces.clear();
}

SDL_Texture *TextureManager::getTexture(std::string key) {
    auto it = textures.find(key);
    if (it != textures.end())
        return (textures[key]);
    else
        return (nullptr);
}

TextureManager  *TextureManager::getInstance(void) {
    if (instance == nullptr)
        instance = new TextureManager();
    return (instance);
}