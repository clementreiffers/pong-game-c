#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include<stdio.h>


void afficher_gagnant(SDL_Window *window, SDL_Renderer* renderer, char* phrase, float width, float height)
{
    int quit = 0;
    SDL_Event event;

    TTF_Init();
    TTF_Font * font = TTF_OpenFont("Digit.ttf", 25);
    SDL_Color color = { 255, 255, 255 };

    SDL_Surface * surface = TTF_RenderText_Solid(font, phrase, color);
    
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 300;
    int texH = 100;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { width/4, height/3, 700, 100 };
    while (!quit)
    {
   		SDL_SetRenderDrawColor(renderer, 0,0,0,0);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
        SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
				case SDLK_ESCAPE: //fermeture de la fenetre via la touche echap
						quit = 1;
				break;
			}
		break;
		}
    }
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    TTF_Quit();
}