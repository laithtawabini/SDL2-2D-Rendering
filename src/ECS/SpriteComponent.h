#pragma once
#include "Components.h"
#include "../headers/TextureHandler.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
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
		transform = &entity->getComponent<TransformComponent>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;

		destRect.w = destRect.h = 64;
	}

	void update() override
	{
		destRect.x = (int) transform->position.x;
		destRect.y = (int) transform->position.y;
	}

	void draw() override
	{
		TextureHandler::Draw(texture, srcRect, destRect);
	}

	void setTexture(const char* path)
	{
		texture = TextureHandler::CreateTexture(path);
	}
};