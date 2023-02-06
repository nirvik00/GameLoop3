#pragma once
#include <SDL.h>
#undef main
#include <SDL_image.h>


class Map {
private:
	SDL_Rect src, dst;

	SDL_Texture* water = NULL;
	SDL_Texture* grass = NULL;
	SDL_Texture* dirt = NULL;

	int map[20][25];

public:

	Map();
	~Map();

	void update();
	void render();

};