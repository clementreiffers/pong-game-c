#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include<stdio.h>


void afficher_gagnant(SDL_Window *window, SDL_Renderer* renderer, char* phrase)
{
    SDL_Init(SDL_INIT_VIDEO);
	//création fenêtre + rendu
	int width = 0;
	int height = 0;
	// ici on initialise la fenetre en fullscreen
	SDL_CreateWindowAndRenderer(width,height, SDL_WINDOW_MAXIMIZED, &window, &renderer);
    // on recupere la taille de la fenetre
	width = SDL_GetWindowSurface(window)->w;
	height = SDL_GetWindowSurface(window)->h;

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
    SDL_Rect dstrect = { width/3, height/2, 600, 100 };
    while (!quit)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                quit = 1;
            break;
        }
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    TTF_Quit();
}