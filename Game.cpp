#include "Game.h"
#include "GameObject.h"
#include "Map.h"

SDL_Renderer* Game::gRenderer = nullptr;
GameObject* player = nullptr;
GameObject* enemy = nullptr;
Map* map = nullptr;

Game::Game() 
{
	gWindow = NULL;
}

void Game::init()
{
	this->isRunning = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "all sdl systems initialized\n";
		this->gWindow = SDL_CreateWindow("abcd", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, 0);
		
		if (this->gWindow)
		{}
		else 
		{
			this->isRunning = false;
		}
		this->gRenderer = SDL_CreateRenderer(this->gWindow, -1, 0);
		if (this->gRenderer)
		{}
		else
		{
			this->isRunning = false;
		}
	}
	else
	{
		std::cout << "sdl system could not initialize \n";
		this->isRunning = false;
	}
	player = new GameObject("assets/player.png", 0, 0);
	enemy = new GameObject("assets/enemy.png", 230, 230);
	map = new Map();

}

void Game::handleEvents()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type)
	{
	case(SDL_QUIT):
		this->isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	player->update();
	enemy->update();
	map->update();
}

void Game::render()
{
	SDL_RenderClear(this->gRenderer);

	map->render();

	//SDL_Rect rect;
	//rect.x = rect.y = 100;
	//rect.w = rect.h = 232;
	//SDL_SetRenderDrawColor(this->gRenderer, 255, 0, 255, 0);
	//SDL_RenderDrawRect(this->gRenderer, &rect);

	player->render();
	enemy->render();

	SDL_SetRenderDrawColor(this->gRenderer, 0, 0, 255, 0);
	SDL_RenderPresent(this->gRenderer);
}

void Game::close()
{
	SDL_DestroyRenderer(this->gRenderer);
	SDL_DestroyWindow(this->gWindow);
	SDL_Quit();
	std::cout << "window closed...\n";
}

