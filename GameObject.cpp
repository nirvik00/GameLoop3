#include "GameObject.h"
#include "Game.h"

GameObject::GameObject(const char* filename, int x, int y)
{
	this->objTex = NULL;

	SDL_Surface* tmp = IMG_Load(filename);
	this->objTex = SDL_CreateTextureFromSurface(Game::gRenderer, tmp);
	SDL_FreeSurface(tmp);

	this->xpos = x;
	this->ypos = y;
	
	src.x = 0;
	src.y = 0;
	src.w = 232;
	src.h = 232;
	dst.x = xpos;
	dst.y = ypos;
	dst.w = 64;
	dst.h = 64;
}

GameObject::~GameObject()
{}

void GameObject::update()
{
	

}

void GameObject::render()
{
	SDL_RenderCopy(Game::gRenderer, this->objTex, &this->src, &this->dst);
}

