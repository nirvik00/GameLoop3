#include<iostream>
#include<stdio.h>

#include <SDL.h>
#undef main
#include<SDL_image.h>

#include "Game.h"

Game* game = NULL;

int main() {	
	game = new Game();
	game->init();

	while (game->running() == true)
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->close();
	system("pause");

	return 0;
}