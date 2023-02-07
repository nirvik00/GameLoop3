#include <SDL.h>
#undef main
#include <SDL_image.h>

#include<iostream>


class Game {

private:
	SDL_Window* gWindow;
	bool isRunning;
	void handleKeyEvents();

	int xcounter = 0;
	int ycounter = 0;

public:
	static int d;
	static SDL_Renderer* gRenderer;

	Game();
	~Game();

	void init();
	void handleEvents();
	void update();
	void render();
	void close();

	SDL_Texture* LoadTexture(const char*);

	bool running() { return isRunning; }

};