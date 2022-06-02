#include "headers/Map.h"

Map::Map()
{
	dirt = TextureHandler::CreateTexture("C:\\Dev\\SDL2\\SDL_Project_2\\SDL_Project_2\\assets\\dirt.png");
	water = TextureHandler::CreateTexture("C:\\Dev\\SDL2\\SDL_Project_2\\SDL_Project_2\\assets\\water.png");
	rock = TextureHandler::CreateTexture("C:\\Dev\\SDL2\\SDL_Project_2\\SDL_Project_2\\assets\\rock.png");
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;
	destRect.x = destRect.y = 0;
	destRect.w = destRect.h = 32;
}
Map::~Map()
{
	SDL_DestroyTexture(dirt);
	SDL_DestroyTexture(water);
	SDL_DestroyTexture(rock);
}

void Map::UpdateMap(int newMap[16][24])
{
	for (int i = 0; i < 16; i++)
		for (int k = 0; k < 24; k++)
			map[i][k] = newMap[i][k];
}

void Map::RenderMap()
{
	int result = 0;
	enum
	{
		DIRT,
		WATER,
		ROCK
	};
	for (int i = 0; i < 16; i++)
	{
		for (int k = 0; k < 24; k++)
		{
			destRect.x = k * 32;
			destRect.y = i * 32;
			switch (map[i][k])
			{
			case DIRT:
				result = SDL_RenderCopy(Game::renderer, dirt, &srcRect, &destRect);
				break;
			case WATER:
				result = SDL_RenderCopy(Game::renderer, water, &srcRect, &destRect);
				break;
			case ROCK:
				result = SDL_RenderCopy(Game::renderer, rock, &srcRect, &destRect);
				break;
			}
			if (result != 0)
				printf("Error with map rendering, Error: %s\n", SDL_GetError());
		}
	}
}