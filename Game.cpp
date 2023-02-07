#include "Game.h"
#include "GameObject.h"
#include "Map.h"

SDL_Renderer* Game::gRenderer = nullptr;
GameObject* player = nullptr;
GameObject* enemy = nullptr;
Map* map = nullptr;


SDL_Rect src2, dst2;
SDL_Texture* sprite = NULL;


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


	src2.x = 0;
	src2.y = 0;
	src2.w = 64;
	src2.h = 64;
	dst2.x = 200;
	dst2.y = 450;
	dst2.w = 64;
	dst2.h = 64;
	sprite = IMG_LoadTexture(Game::gRenderer, "assets/hero_idle.png");
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

	case SDL_KEYDOWN:
		// printf("Key press detected\n");
		// std::cout << "Key Pressed! Key Code: " << e.key.keysym.sym << ", Key Name: " << SDL_GetKeyName(e.key.keysym.sym) << '\n';

		if (e.key.keysym.sym == 27) 
		{
			std::cout << "escape button pressed\n";
			isRunning = false;
		}
		if (e.key.keysym.sym == 1073741903) // "Right"
		{
			player->dst.x += 32;
		}
		if (e.key.keysym.sym == 1073741904) // "Left"
		{
			player->dst.x -= 32;
		}
		if (e.key.keysym.sym == 1073741906) // "Up"
		{
			player->dst.y -= 32;
		}
		if (e.key.keysym.sym == 1073741905) // "Down"
		{
			player->dst.y += 32;
		}
		break;

	case SDL_KEYUP:
		// printf("Key release detected\n");
		break;

	case(SDL_MOUSEBUTTONDOWN):
		// printf("mouse button pressed detected\n");
		break;

	case(SDL_MOUSEBUTTONUP):
		// printf("mouse button release detected\n");
		if (e.button.button == SDL_BUTTON_LEFT) {
			// printf("mouse button LEFT release detected\n");
		}
		else if (e.button.button == SDL_BUTTON_RIGHT) {
			// printf("mouse button RIGHT release detected\n");
		}
		break;
	case(SDL_MOUSEMOTION):
		// printf("mouse motition detected\n");
		break;
	default:
		break;
	}

	int x, y;
	SDL_GetMouseState(&x, &y);
	// std::cout << "Mouse is at " << x << ", " << y;
}


void Game::handleKeyEvents() 
{

}


void Game::update()
{
	player->update();
	enemy->update();
	map->update();
	

	if (xcounter > 2) {
		xcounter = 0;
	}
	src2.x = xcounter * 64;
	std::cout << "counter: " << xcounter << " frame: " << src2.x << "\n";
	xcounter++;
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
	
	SDL_RenderCopy(this->gRenderer, sprite, &src2, &dst2);

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


void getFrames() {
	src2.x = 32;
	src2.y = 0;
	
}