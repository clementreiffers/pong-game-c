#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL_ttf.h>

#include "jeu_pong.h"
#include "formes.h"
#include "menu.h"
/*
	les differents types rendus:

		SDL_RENDERER_SOFTWARE	   (acceleration depuis le processeur)
		SDL_RENDERER_ACCELERATED   (acceleration matèriel utlisation de la carte graphique)
		SDL_RENDERER_PRESENTVSYNC  (rendu pour la synchronisation verticale)
		SDL_RENDERER_TARGETTEXTURE (rendus pour les textures)
*/


int main(int argc, char *argv[])
{
	SDL_Window *window = NULL; //pointeur par défaut pour la fenêtre
	SDL_Renderer *renderer = NULL; //pointeur qui va créer un rendu

	//lancement SDL
	SDL_Init(SDL_INIT_VIDEO);
	//création fenêtre + rendu
	int width = 0;
	int height = 0;
	// ici on initialise la fenetre en fullscreen
	SDL_CreateWindowAndRenderer(width,height, SDL_WINDOW_FULLSCREEN, &window, &renderer);
	// on recupere la taille de la fenetre
	width = SDL_GetWindowSurface(window)->w;
	height = SDL_GetWindowSurface(window)->h;


	int choix = menu(window, renderer, width, height);
	int gagnant = 0;
	if(choix == 0) {
		//mode facile
		gagnant = pong(window, renderer, 0.5, 0.5, 0.5, width, height);
	}
	if(choix == 1) {
		//mode normal
		gagnant = pong(window, renderer, 1, 1, 1, width, height);
	}
	if(choix == 2) {
		//mode harcore
		gagnant = pong(window, renderer, 2, 2, 2, width, height);
	}
	gagnant == 1 ? afficher_gagnant(window, renderer, "BRAVO AU JOUEUR 1", width, height) : afficher_gagnant(window, renderer, "BRAVO AU JOUEUR 2", width, height);
	

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
