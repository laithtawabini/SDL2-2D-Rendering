#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureHandler.h"
#include <iostream>

class GameObject
{

public:
	GameObject(std::string = "Empty", std::string = "Empty", int = 0, int = 0);
	~GameObject();
	void Update(int, int);
	bool Render();

	SDL_Texture *GetTexture();
	void SetTexture(SDL_Texture *_texture);

	SDL_Rect &GetRect();
	void SetRect(SDL_Rect &newRect);

	std::string GetPath();
	void SetPath(std::string newPath);

	std::string GetName();
	void SetName(std::string);

private:
	std::string name;
	std::string path;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;
	int x, y;
};
