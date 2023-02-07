#include<iostream>
#include<stdio.h>

#include <SDL.h>
#undef main
#include<SDL_image.h>

#include "Game.h"

Game* game = NULL;




int main() 
{	
	const int fps = 60;
	const int frameDelay = 1000 / fps;

	game = new Game();
	game->init();
	Uint32 frameStart = 0;



	while (game->running() == true)
	{
		frameStart = SDL_GetTicks();
		//
		game->handleEvents();
		game->update();
		game->render();
		//
		int frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay-frameTime);
		}

	}

	game->close();
	system("pause");

	return 0;
}