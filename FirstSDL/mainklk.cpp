#include "stdio.h"
#include "/Users/alexa/Desktop/Cube/SDL/include/SDL.h"
#pragma comment(lib, "/Users/alexa/Desktop/Cube/SDL/libx86/SDL2.lib")
#pragma comment(lib, "/Users/alexa/Desktop/Cube/SDL/libx86/SDL2main.lib")


using namespace std;
void moveRectangle(SDL_Rect *rect, Uint32 &rectstate);
Uint32 WIDTH = 720;
Uint32 HEIGHT = 480;

int main(int argc, char* argv[])
{
	SDL_Window *window;                    // Declare a pointer
	SDL_Renderer *renderer = NULL;
	Uint32 rectstate = 0;


	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
										   // Create an application window with the following settings:
	window = SDL_CreateWindow(
		"TestProyecto",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		720,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_RESIZABLE                  // flags - see below
	);

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	SDL_Rect *rect = new SDL_Rect();
	rect->h = 50;
	rect->w = 50;
	rect->x = (WIDTH/2)-rect->w/2;
	rect->y = HEIGHT / 2 - (rect->h / 2);

	while (1)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		moveRectangle(rect, rectstate);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, rect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}

void moveRectangle(SDL_Rect *rect, Uint32 &rectstate)
{
	if (rectstate == 0)
	{
		if (rect->y > HEIGHT - rect->w) {
			rectstate = 1;
		}
		else rect->y += 5;

	}
	else {
		if (rect->y <= 0) {
			rectstate = 0;
		}
		else rect->y -= 5;
	}
}