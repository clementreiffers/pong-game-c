#include<SDL2/SDL.h>

SDL_Rect createRect(int x, int y, int w, int h) {
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;

	return rectangle;
}