#include "SDL.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main( int argc, char* argv[] )
{
	std::cout << "something is happening";
	const int WIDTH = 640;
	const int HEIGHT = 480;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	std::this_thread::sleep_for(5s);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}