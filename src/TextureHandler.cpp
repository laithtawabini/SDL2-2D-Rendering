#include "headers/TextureHandler.h"

SDL_Surface* TextureHandler::LoadSurface(const std::string &path)
{
	SDL_Surface *loadedImage = NULL;
	SDL_Surface *optimizedImage = NULL;

	loadedImage = IMG_Load(path.c_str());

	if (loadedImage == NULL)
	{
		printf("SDL_IMG failed to load image %s, error: %s\n", path.c_str(), IMG_GetError());
		return NULL;
	}

	optimizedImage = SDL_ConvertSurface(loadedImage, Game::surface->format, SDL_RLEACCEL);
	SDL_FreeSurface(loadedImage);

	return optimizedImage;
}

SDL_Texture* TextureHandler::CreateTexture(const std::string path)
{
	SDL_Surface* loadedSurface = LoadSurface(path);

	// Hides transparent background of the PNG image
	Uint32 colorkey = SDL_MapRGB(loadedSurface->format, 0, 0, 0);
	SDL_SetColorKey(loadedSurface, SDL_TRUE, colorkey);

	// texture being created for the object using the surface that is loaded using the image of the object
	SDL_Texture* txt = SDL_CreateTextureFromSurface(Game::renderer, loadedSurface);

	if (txt == NULL)
	{
		printf("SDL failed to create texture, error: %s\n", IMG_GetError());
		return NULL;
	}

	return txt;
}

bool TextureHandler::Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect)
{
	if (SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect) != 0)
	{
		printf("SDL failed to render copy, error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}