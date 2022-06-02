#include "headers/GameObject.h"

GameObject::GameObject(std::string name, std::string path, int xpos, int ypos)
{
	this->name = name;
	this->path = path;

	srcRect.w = srcRect.h = 32;
	srcRect.x = srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = destRect.h = 32;

	texture = TextureHandler::CreateTexture(this->path);
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
}

void GameObject::Update(int newX, int newY)
{
	x = newX;
	y = newY;
}

bool GameObject::Render()
{
	if (SDL_RenderCopy(Game::renderer, this->texture, &srcRect, &destRect) != 0)
	{
		printf("SDL failed to render copy, error: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

SDL_Texture *GameObject::GetTexture()
{
	return texture;
}

void GameObject::SetTexture(SDL_Texture *texture)
{
	this->texture = texture;
}

SDL_Rect &GameObject::GetRect()
{
	return destRect;
}

void GameObject::SetRect(SDL_Rect &newRect)
{
	destRect = newRect;
}

std::string GameObject::GetPath()
{
	return path;
}

void GameObject::SetPath(std::string newPath)
{
	path = newPath;
}

std::string GameObject::GetName()
{
	return name;
}

void GameObject::SetName(std::string newName)
{
	name = newName;
}
