#include <SDL2/SDL.h>
#include "formes.h"
#include<stdio.h>
#include <stdlib.h>
#include<SDL2/SDL_ttf.h>


int menu(SDL_Window *window, SDL_Renderer *renderer, float width, float height) {
	//initialisation du fond d'ecran
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;
	image == NULL;
	image = SDL_LoadBMP("Arcade.bmp");
	texture = SDL_CreateTextureFromSurface(renderer, image);
	texture == NULL;
	SDL_Rect rectangle;
	
    // rectangles qui nous servirons pour les menus
	SDL_Rect facile = { width/3, height/5, width/3, height/15};
	SDL_Rect normal =  { width/3, height/5 + 2* height/15, width/3, height/15};
	SDL_Rect hardcore = { width/3, height/5 + 4* height/15, width/3, height/15};
	SDL_Rect quitter = { width/3, height/5+ 6* height/15, width/3, height/15};

    int choix = 0; // la variable qu'on renvoie à la fin
	int continuer = 1; // pour le while
	int x = width/3.3-50, y= height/4.3 , r = 10; // caracteristiques pour le cercle du menu
	TTF_Init(); // on initialise la biblio SDL2_TTF
	TTF_Font * font = TTF_OpenFont("Lazer84.ttf", 25); // tu mets la police
    SDL_Color color = { 224, 224, 224 }; // on definie la couleur noire et blanche
	SDL_Color white = { 255, 0, 0 };

	// on cree les ecritures et les textures
    SDL_Surface * rectfacile = TTF_RenderText_Solid(font, "Mode Debutant", color);
    SDL_Texture * texfacile = SDL_CreateTextureFromSurface(renderer, rectfacile);
	SDL_Surface * rectnorm = TTF_RenderText_Solid(font, "Mode Normal", color);
    SDL_Texture * texnorm = SDL_CreateTextureFromSurface(renderer, rectnorm);
	SDL_Surface * rectdiff = TTF_RenderText_Solid(font, "Mode Difficile", color);
    SDL_Texture * texdiff = SDL_CreateTextureFromSurface(renderer, rectdiff);
	SDL_Surface * rectquit = TTF_RenderText_Solid(font, "Quitter", white);
    SDL_Texture * texquit = SDL_CreateTextureFromSurface(renderer, rectquit);

	// on met la taille de la texture (notamment celle de la police)
	SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h);
	SDL_QueryTexture(texfacile, NULL, NULL, 0, 0);
    SDL_QueryTexture(texnorm, NULL, NULL, 0, 0);
    SDL_QueryTexture(texdiff, NULL, NULL, 0, 0);
    SDL_QueryTexture(texquit, NULL, NULL, 0, 0);

	rectangle.x = (width- rectangle.w)/2;
	rectangle.y = (height - rectangle.h)/2;

	while(continuer) {
		// on affiche les menus
		SDL_SetRenderDrawColor(renderer, 0,0,0,0); // on met le background noir
		SDL_RenderClear(renderer); // on nettoie le rendu
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // on met la couleur blanche pour nos objets
		SDL_RenderFillRect(renderer,&facile); // on affiche nos rectangles
		SDL_RenderFillRect(renderer,&normal);
		SDL_RenderFillRect(renderer,&hardcore);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE); // on met la couleur rouge
		SDL_RenderFillRect(renderer,&quitter);
		
		SDL_Event evenement; //tous nos evenements seront gérés à partir de cette ligne
		while(SDL_PollEvent(&evenement))//fonction qui va capturer, enregistrer tous les evenements
		{
			// ces conditions permettent de choisir le mode qu'on veut
			switch(evenement.type)
			{
				case SDL_KEYDOWN:
					switch(evenement.key.keysym.sym)
					{
						case SDLK_UP:
							if(y<=height/3) {
								y = height/4.3+6*height/15;
							}
							else {
								y-=2*height/15;
							}
						break;

						case SDLK_DOWN:
							if(y>= 8*height/15) {
								y = height/4.3;
							}
							else {
								y+=2*height/15;
							}
						break;
						case SDLK_RETURN:
							if(y>=height/4.3 && y<=height/4.3+2*height/15) {
								choix = 1;
							}
							if(y>=height/4.3+2*height/15 && y<=height/4.3+2*height/15+3*height/15) {
								choix = 2;
							}
							if(y>=height/4.3+4*height/15) {
								choix = 3;
							}
							continuer = 0;
					}
				break;
			}
		}
		// on applique la texture à nos rectangles
		SDL_RenderCopy(renderer, texture, NULL, &rectangle);
		SDL_RenderCopy(renderer, texfacile, NULL, &facile);
		SDL_RenderCopy(renderer, texnorm, NULL, &normal);
		SDL_RenderCopy(renderer, texdiff, NULL, &hardcore);
		SDL_RenderCopy(renderer, texquit, NULL, &quitter);
		

		// on affiche le cercle qu'on contrôle avec les fleches du clavier
        ellipse(renderer, x, y, r, r);

		// on rafraichis le rendu
		SDL_RenderPresent(renderer); 

	}
	// on détruit ce qu'on n'a plus besoin
	
	SDL_DestroyTexture(texfacile);
	SDL_DestroyTexture(texnorm);
	SDL_DestroyTexture(texdiff);
	SDL_DestroyTexture(texture);
    SDL_FreeSurface(rectfacile);
    SDL_FreeSurface(rectnorm);
    SDL_FreeSurface(rectdiff);
    TTF_CloseFont(font);
    TTF_Quit();
    return choix;
}
