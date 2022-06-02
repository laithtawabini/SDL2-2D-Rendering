#include "headers/Game.h"
#include "headers/Map.h"
#include "ECS/Components.h"

SDL_Surface* Game::surface = nullptr;
SDL_Renderer* Game::renderer = nullptr;

Manager manager;
Map* map;

Game::Game(std::string name, const int WIDTH, const int HEIGHT) : name(name), WIDTH(WIDTH), HEIGHT(HEIGHT)
{
	// Inits SDL
	if (!Init())
	{
		printf("Couldn't Initialize SDL or SDL_IMAGE.\n");
		return;
	}
	running = true;
	map = new Map();
	auto& player(manager.addEntity());
	player.addComponent<PositionComponent>();
	player.addComponent<SpriteComponent>("C:\\Dev\\SDL2\\SDL_Project_2\\SDL_Project_2\\assets\\player.png");
}

void Game::Update()
{
	manager.refresh();
	manager.update();
}

void Game::HandleEvents()
{
	SDL_Event input;
	while (SDL_PollEvent(&input) != 0)
	{
		if (input.type == SDL_QUIT)
			running = false;
		if (input.type == SDL_KEYDOWN)
		{
			
		}
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	map->RenderMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

bool Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL INIT ERROR: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("SDL failed to create window, error: %s\n", SDL_GetError());
			return false;
		}

		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		{
			printf("SDL image failed to initialize, error: %s\n", IMG_GetError());
			return false;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
		{
			printf("SDL error creating renderer %s\n", SDL_GetError());
			return false;
		}

		surface = SDL_GetWindowSurface(window);
		if (surface == NULL)
		{
			printf("SDL failed to get window surface, error: %s\n", SDL_GetError());
			return false;
		}

		if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0) != 0)
		{
			printf("SDL failed to render draw color, error: %s\n", SDL_GetError());
			return false;
		}
	}

	return true;
}

void Game::Close()
{
	SDL_FreeSurface(surface);
	surface = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
	IMG_Quit();
}