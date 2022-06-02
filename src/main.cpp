#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "headers/Game.h"

int main(int argc, char *argv[])
{
	const int FPS = 144;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Game* game = new Game("First Game", 768, 512);
	while (game->Running())
	{
		{
			frameStart = SDL_GetTicks();
		}

		game->HandleEvents();
		game->Update();
		game->Render();

		std::cout << "DN";
		{
			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime)
				SDL_Delay(frameDelay - frameTime);
		}
	}

	game->Close();
	return 0;
}
