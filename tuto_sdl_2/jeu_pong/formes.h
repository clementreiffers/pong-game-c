#include <SDL2/SDL.h>

void ellipse(SDL_Renderer* r, int x0, int y0, int radiusX, int radiusY); // fonction qui cree nos ellipses
SDL_Rect createRect(int x, int y, int w, int h); // fonction qui cree notre rectangle
void compteur(SDL_Renderer* r, float w, float h);