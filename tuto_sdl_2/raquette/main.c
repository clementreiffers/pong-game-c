
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

/*
	les differents types rendus:

		SDL_RENDERER_SOFTWARE	   (acceleration depuis le processeur)
		SDL_RENDERER_ACCELERATED   (acceleration matèriel utlisation de la carte graphique)
		SDL_RENDERER_PRESENTVSYNC  (rendu pour la synchronisation verticale)
		SDL_RENDERER_TARGETTEXTURE (rendus pour les textures)
*/

void SDL_ExitWithError(const char *message); //fonction creee pour afficher un message lorsque la fenêtre ne peut s'afficher

int main(int argc, char *argv[])
{
	SDL_Window *window = NULL; //pointeur par défaut pour la fenêtre
	SDL_Renderer *renderer = NULL; //pointeur qui va créer un rendu
	int continuer = 1;
	

	SDL_Rect rectangle1; // creation des coordonnées du rectangle
	rectangle1.x = 50;
	rectangle1.y = 300;
	rectangle1.w = 20;
	rectangle1.h = 70;

	SDL_Rect rectangle2; // creation des coordonnées du rectangle
	rectangle2.x = 1430;
	rectangle2.y = 300;
	rectangle2.w = 20;
	rectangle2.h = 70;


	//lancement SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("initialisation SDL");

	//création fenêtre + rendu

	if (SDL_CreateWindowAndRenderer(1500,900, 0, &window, &renderer) != 0) 
		SDL_ExitWithError("Impossible de creer rendu et fenêtre");


	while(continuer)
	{
		SDL_Event evenement; //tous nos evenements seront gérés à partir de cette ligne

		while(SDL_PollEvent(&evenement))//fonction qui va capturer, enregistrer tous les evenements
		{
			switch(evenement.type)
			{	
				case SDL_QUIT:
					continuer = 0;
				case SDL_KEYDOWN:
					switch(evenement.key.keysym.sym)
					{
						case SDLK_ESCAPE: //fermeture de la fenetre via la touche echap
						case SDLK_q:
							continuer = 0;
						break;

						case SDLK_z:
							rectangle1.y -= 20;
						break;

						case SDLK_s:
							rectangle1.y += 20;
						break;

						case SDLK_UP:
							rectangle2.y -=20;
						break;

						case SDLK_DOWN:
							rectangle2.y +=20;
					}
				case SDL_KEYUP:
					switch(evenement.key.keysym.sym)
					{
						case SDLK_z:
							rectangle1.y -= 20;
						break;

						case SDLK_s:
							rectangle1.y += 20;
						break;

						case SDLK_UP:
							rectangle2.y -=20;
						break;

						case SDLK_DOWN:
							rectangle2.y +=20;
					}

			}
		}
		SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer,0,0,0,0);

		if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) !=0)
			SDL_ExitWithError("Il n'est pas possible de changer la couleur");

		if (SDL_RenderFillRect(renderer,&rectangle1) !=0 )
			SDL_ExitWithError("Impossible de creer le rectangle de gauche");

		if (SDL_RenderFillRect(renderer,&rectangle2) !=0 )
			SDL_ExitWithError("Impossible de creer le rectangle de droite");


		SDL_RenderPresent(renderer); //fonction qui affiche le rendu et va prendre en paramètre renderer	
	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message)
{
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError()); //il va afficher l'erreur
	SDL_Quit();// si SDL n'a pas réussi à être initialiser par exemple, on va quiter SDL
	exit(EXIT_FAILURE);
}