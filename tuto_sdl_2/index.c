#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture, *tmp = NULL;
    SDL_Surface *surface = NULL;
 
    if (NULL != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }
 
    {
        window = SDL_CreateWindow("Appli test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
 
        if(window)
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if ( renderer )
            {
                surface = SDL_LoadBMP("ball.png");//chargement de l'image
                if (surface)
                {
                    texture = SDL_CreateTextureFromSurface(renderer, surface);
                    if (texture)
                    {
                        SDL_Rect dest = { 640/2 - surface->w/2,480/2 - surface->h/2, 0, 0};//un SDL_Rect qui sers de destination à l'image
                        SDL_RenderCopy(renderer, texture, NULL, &dest); // copie de surface grâce au SDL_Renderer
 
                        SDL_RenderPresent(renderer); //Affichage
                        SDL_Delay(3000);
 
                        SDL_DestroyTexture(texture);//fin de programme, destruction des entitées utilisées
                    }
                    else
                    {
                        fprintf(stderr, "Echec de création de la texture : %s", SDL_GetError());
                    }
                    SDL_FreeSurface (surface);
 
                }
                else
                {
                    fprintf(stderr, "Echec de chargement du sprite : %s ", SDL_GetError());
                }
                SDL_DestroyRenderer(renderer);
            }
            else
            {
                fprintf(stderr, "echec de création du renderer : %s", SDL_GetError());
            }
        }
        else
        {
            fprintf(stderr, "Erreur creation window : %s", SDL_GetError());
        }
    }
 
    SDL_Quit();
 
    return 0;
}