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
	
	src.x = src.y=0;
	src.w = src.h = 232;
	dst.x = dst.y = x;
	dst.w = dst.h = 64;	
}

GameObject::~GameObject()
{}

void GameObject::update()
{
	if (dst.x > 0 && dst.x < 800)
	{
		dst.x++;
	}

}

void GameObject::render()
{
	SDL_RenderCopy(Game::gRenderer, this->objTex, &this->src, &this->dst);
}

