#pragma once
#include "Components.h"
#include "../headers/TextureHandler.h"

class SpriteComponent : public Component
{
private:
	PositionComponent *position;
	SDL_Texture *texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char *path)
	{
		texture = TextureHandler::CreateTexture(path);
	}

	void init() override
	{
		position = &entity->getComponent<PositionComponent>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;

		destRect.w = destRect.h = 64;
	}

	void update() override
	{
		if (position == NULL)
			return;
		destRect.x = position->getX();
		destRect.y = position->getY();
	}

	void draw() override
	{
		TextureHandler::Draw(texture, srcRect, destRect);
	}
};