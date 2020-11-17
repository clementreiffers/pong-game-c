#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

void drawText (SDL_Surface* screen, char* string, int size, int x, int y, int fR, int fG, int fB, int bR, int bG, int bB);

int main(int argc, char *argv[])
{
	SDL_Window *window = NULL; //pointeur par défaut pour la fenêtre
	SDL_Renderer *renderer = NULL; //pointeur qui va créer un rendu
	int continuer = 1;
	// dimension des raquettes et sa vitesse

	//lancement SDL
    SDL_Init(SDL_INIT_VIDEO);
    /*
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("initialisation SDL");*/

	//création fenêtre + rendu
	int width = 0;
	int height = 0;
	// ici on initialise la fenetre en fullscreen
    SDL_CreateWindowAndRenderer(width,height, SDL_WINDOW_MAXIMIZED, &window, &renderer);
	/*if (SDL_CreateWindowAndRenderer(width,height, SDL_WINDOW_MAXIMIZED, &window, &renderer) != 0) 
		SDL_ExitWithError("Impossible de creer rendu et fenêtre");*/
	// on recupere la taille de la fenetre
	width = SDL_GetWindowSurface(window)->w;
	height = SDL_GetWindowSurface(window)->h;


	while(continuer)
	{
        SDL_RenderPresent(renderer); //fonction qui affiche le rendu et va prendre en paramètre renderer	

    }
    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}

void drawText (SDL_Surface* screen, char* string, int size, int x, int y, int fR, int fG, int fB, int bR, int bG, int bB)
{
	//TTF_Init();
	//TTF_Font* font = TTF_OpenFont("ARIAL.TTF", size);

	SDL_Color foregroundColor = { fR, fG, fB };
	SDL_Color backgroundColor = { bR, bG, bB };

	SDL_Surface* textSurface = TTF_RenderText_Shaded(font, string, foregroundColor, backgroundColor);

	SDL_Rect textLocation = { x, y, 0, 0 };

	//SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

	//SDL_FreeSurface(textSurface);

	//TTF_CloseFont(font);

}