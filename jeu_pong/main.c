#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "jeu_pong.h"
#include "formes.h"
#include "menu.h"

int main(int argc, char *argv[])
{
	SDL_Window *window = NULL; //pointeur par défaut pour la fenetre
	SDL_Renderer *renderer = NULL; //pointeur qui va créer un rendu

	//lancement SDL
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	//création fenetre + rendu
	int width = 0;
	int height = 0;
	// ici on initialise la fenetre en fullscreen
	SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_FULLSCREEN, &window, &renderer);

	//initialisation de la musique
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	// on met la musique
	Mix_Music *backgroundSound = Mix_LoadMUS("musique_de_fond.wav");

	// on la joue
	Mix_PlayMusic(backgroundSound, -1);

//--------------------------------------
	// on recupere la taille de la fenetre
	width = SDL_GetWindowSurface(window)->w;
	height = SDL_GetWindowSurface(window)->h;

	// on recupere le choix du joueur grace a notre menu (voir menu.c)
	int choix = menu(window, renderer, width, height);

	// on lance la partie de pong selon la difficulté choisie, (voir jeu_pong.c), on recupère le numero des gagnants
	int gagnant = 0;
	// dans la fonction pong, on lui donne notre fenetre, rendu, la vitesse des raquettes et de la balle et la taille
	// de notre screen
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
	gagnant == 1 ? afficher_gagnant(window, renderer, "BRAVO AU JOUEUR 1", width, height) : NULL ;
	gagnant == 2 ? afficher_gagnant(window, renderer, "BRAVO AU JOUEUR 2", width, height) : NULL ;
	
	// on arrête tous les processsus qu'on a commencé
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_FreeMusic(backgroundSound);
	SDL_Quit();

	return EXIT_SUCCESS;
}
