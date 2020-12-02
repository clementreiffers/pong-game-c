#include <SDL2/SDL.h>
#include "formes.h"
#include<stdio.h>
#include<SDL2/SDL_ttf.h>
int menu(SDL_Window *window, SDL_Renderer *renderer, float width, float height) {
    
	SDL_Rect facile = { width/3, height/5, width/3, height/15};
	SDL_Rect normal =  { width/3, height/5 + 2* height/15, width/3, height/15};
	SDL_Rect hardcore = { width/3, height/5 + 4* height/15, width/3, height/15};
	SDL_Rect quitter = { width/3, height/5+ 6* height/15, width/3, height/15};

    int choix = 0;
	int continuer = 1;
	int x = width/3.3-50, y= height/4.3 , r = 10;
	TTF_Init();
	TTF_Font * font = TTF_OpenFont("Digit.ttf", 25);
    SDL_Color color = { 0, 0, 0 };
	SDL_Color white = {255, 255, 255};
    SDL_Surface * rectfacile = TTF_RenderText_Solid(font, "Mode Debutant", color);
    SDL_Texture * texfacile = SDL_CreateTextureFromSurface(renderer, rectfacile);

	SDL_Surface * rectnorm = TTF_RenderText_Solid(font, "Mode Normal", color);
    SDL_Texture * texnorm = SDL_CreateTextureFromSurface(renderer, rectnorm);
	SDL_Surface * rectdiff = TTF_RenderText_Solid(font, "Mode Difficile", color);
    SDL_Texture * texdiff = SDL_CreateTextureFromSurface(renderer, rectdiff);
	SDL_Surface * rectquit = TTF_RenderText_Solid(font, "Quitter", white);
    SDL_Texture * texquit = SDL_CreateTextureFromSurface(renderer, rectquit);
    int texW = 0;
    int texH = 0;
	SDL_QueryTexture(texfacile, NULL, NULL, &texW, &texH);
    SDL_QueryTexture(texnorm, NULL, NULL, &texW, &texH);
    SDL_QueryTexture(texdiff, NULL, NULL, &texW, &texH);
    SDL_QueryTexture(texquit, NULL, NULL, &texW, &texH);

	while(continuer) {
		// on affiche les menus
		SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer,&facile);
		SDL_RenderFillRect(renderer,&normal);
		SDL_RenderFillRect(renderer,&hardcore);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer,&quitter);
		
		SDL_Event evenement; //tous nos evenements seront gérés à partir de cette ligne
		while(SDL_PollEvent(&evenement))//fonction qui va capturer, enregistrer tous les evenements
		{
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

		SDL_RenderCopy(renderer, texfacile, NULL, &facile);
		SDL_RenderCopy(renderer, texnorm, NULL, &normal);
		SDL_RenderCopy(renderer, texdiff, NULL, &hardcore);
		SDL_RenderCopy(renderer, texquit, NULL, &quitter);

        ellipse(renderer, x, y, r, r);

		SDL_RenderPresent(renderer); 

	}
	SDL_DestroyTexture(texfacile);
	SDL_DestroyTexture(texnorm);
	SDL_DestroyTexture(texdiff);
    SDL_FreeSurface(rectfacile);
    SDL_FreeSurface(rectnorm);
    SDL_FreeSurface(rectdiff);
    TTF_CloseFont(font);
    TTF_Quit();
    return choix;
}
