#include <SDL2/SDL.h>

typedef struct Raquettes raquettes;
struct Raquettes
{
	int y1;
	int y2;
};

// void SDL_ExitWithError(const char *message);
void afficher_gagnant(SDL_Window *window, SDL_Renderer*, char*, float, float);
void ellipse(SDL_Renderer*, int, int, int, int); // fonction qui cree nos ellipses

raquettes deplacement(SDL_Renderer*, SDL_Rect, SDL_Rect, float, float);
int exitOrNot();

void compteur(SDL_Renderer*, float, float);
