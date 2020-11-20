#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "jeu_pong.h"

/*
	les differents types rendus:

		SDL_RENDERER_SOFTWARE	   (acceleration depuis le processeur)
		SDL_RENDERER_ACCELERATED   (acceleration matèriel utlisation de la carte graphique)
		SDL_RENDERER_PRESENTVSYNC  (rendu pour la synchronisation verticale)
		SDL_RENDERER_TARGETTEXTURE (rendus pour les textures)
*/

void SDL_ExitWithError(const char *message); //fonction creee pour afficher un message lorsque la fenêtre ne peut s'afficher
SDL_Rect createRect(int x, int y, int w, int h); // fonction qui cree notre rectangle

int main(int argc, char *argv[])
{
	SDL_Window *window = NULL; //pointeur par défaut pour la fenêtre
	SDL_Renderer *renderer = NULL; //pointeur qui va créer un rendu

	pong(window, renderer, 1, 1, 1);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
