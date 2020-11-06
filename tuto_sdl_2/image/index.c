#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_image.h"
#include <stdio.h>
#include <stdlib.h>
#define LARGEUR 800
#define HAUTEUR 600
using namespace std;
 
 
 
int main(int argc,char** argv)
{
/*----------------------------------INITIALISATION------------------------------------------*/
 
    SDL_Window     *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture   *texture = NULL;
    SDL_Surface     *image = NULL;
    SDL_Rect          dest;
 
/*----------------------------------VERIFICATION------------------------------------------*/
 
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        std::cout << "ERROR SDL_INIT %s " << SDL_GetError();
        goto Quit;
    }
 
    if(SDL_CreateWindowAndRenderer(LARGEUR,HAUTEUR,SDL_WINDOW_SHOWN,&window,&renderer)!=0)
    {
        std::cout << "ERROR SDL_CREATEWINDOWANDRENDERER %s " << SDL_GetError();
        goto Quit;
    }
 
    image = SDL_LoadBMP("a.bmp");
 
    if(image==NULL)
    {
        std::cout << "ERROR SDL_LOADBMP %s " << SDL_GetError();
        goto Quit;
    }
 
    texture = SDL_CreateTextureFromSurface(renderer,image);
 
    if(texture==NULL)
    {
        std::cout << "ERROR SDL_CREATETEXTUREFROMSURFACE %s " << SDL_GetError();
        goto Quit;
    }
 
    dest = {800/2 - image->w/2,600/2 - image->h/2,LARGEUR,HAUTEUR};
 
    if(SDL_RenderCopy(renderer,texture,NULL,&dest)!=0)
    {
        std::cout << "ERROR SDL_RENDERCOPY %s " << SDL_GetError();
        goto Quit;
    }
 
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
 
 
/*----------------------------------DESTRUCTION------------------------------------------*/
 
Quit:
    if(image!=NULL)
        SDL_FreeSurface(image);
    if(texture!=NULL)
        SDL_DestroyTexture(texture);
    if(renderer!=NULL)
        SDL_DestroyRenderer(renderer);
    if(window!=NULL)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
 
}