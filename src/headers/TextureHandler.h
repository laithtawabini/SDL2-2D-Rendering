#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
#include <string>

class TextureHandler
{
private:
	static SDL_Surface *LoadSurface(const std::string &path);

public:
	static SDL_Texture *CreateTexture(const std::string path);
	static bool Draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect);
};
