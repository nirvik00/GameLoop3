#pragma once

#include<SDL.h>
#undef main
#include<SDL_image.h>


class GameObject {

private:
	float xpos;
	float ypos;
	SDL_Texture* objTex;
	

public:
	GameObject(const char*, int, int);
	~GameObject();

	void update();
	void render();

	SDL_Rect src, dst;
	

};