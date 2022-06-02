#pragma once
#include <SDL2/SDL.h>
#include "GameObject.h"
#include <iostream>
#include <vector>

class Game
{
public:
	static SDL_Surface *surface;
	static SDL_Renderer *renderer;

public:
	Game(std::string name, const int WIDTH, const int HEIGHT);

	void HandleEvents();
	void Update();
	void Render();

	bool Running() { return running == true; };
	void Close();

	// utility functions
private:
	bool Init();

private:
	bool running = false;
	int WIDTH;
	int HEIGHT;
	std::string name;
	SDL_Window *window = NULL;
};
