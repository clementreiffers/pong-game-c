//premier code

/*
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    int statut = EXIT_FAILURE;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                640, 480, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    statut = EXIT_SUCCESS;
    SDL_Delay(3000);
    SDL_DestroyWindow(window);
    printf("salut\n");
Quit:
    SDL_Quit();
    return statut;
}
*/


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

/*
    les differents types rendus:

        SDL_RENDERER_SOFTWARE      (acceleration depuis le processeur)
        SDL_RENDERER_ACCELERATED   (acceleration matèriel utlisation de la carte graphique)
        SDL_RENDERER_PRESENTVSYNC  (rendu pour la synchronisation verticale)
        SDL_RENDERER_TARGETTEXTURE (rendus pour les textures)
*/

void SDL_ExitWithError(const char *message); //fonction creee pour afficher un message lorsque la fenêtre ne peut s'afficher

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL; //pointeur par défaut pour la fenêtre
    SDL_Renderer *renderer = NULL; //pointeur qui va créer un rendu

    SDL_Rect rectangle1; // creation des coordonnées du rectangle
    rectangle1.x = 50;
    rectangle1.y = 300;
    rectangle1.w = 20;
    rectangle1.h = 50;

    SDL_Rect rectangle2; // creation des coordonnées du rectangle
    rectangle2.x = 1420;
    rectangle2.y = 300;
    rectangle2.w = 20;
    rectangle2.h = 50;

    //lancement SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("initialisation SDL");

    //création fenêtre + rendu

    if (SDL_CreateWindowAndRenderer(1500,900, 0, &window, &renderer) != 0) 
        //l'esperluette à un pointeur de pointeur donc il faut passer par l'adresse
        SDL_ExitWithError("Impossible de creer rendu et fenêtre");

    /*------------------------------------------------------------------------------------------------------------------*/

    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;

    image = SDL_LoadBMP("src/nom.bmp");

    if (image == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de creer l'image");
    }

    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);


    if (texture == NULL)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de creer la texture");
    }


    SDL_Rect rectIm;

    if(SDL_QueryTexture(texture, NULL, NULL, &rectIm.w, &rectIm.h) !=0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de charger la texture");
    }

    rectIm.x = (1500 - rectIm.w) / 2;
    rectIm.y = (900 - rectIm.h) / 2;

    if(SDL_RenderCopy(renderer, texture, NULL, &rectIm) !=0)
            {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible d'afficher la texture");
    }


    if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) !=0)
        SDL_ExitWithError("Il n'est pas possible de changer la couleur");
/*
    if (SDL_RenderDrawPoint(renderer, 100, 450) !=0 )
        SDL_ExitWithError("Il est Impossible de dessiner un point");

    if (SDL_RenderDrawLine(renderer, 55, 55, 200, 400) !=0 )
            // les deux premiers paramètres prennent le x et y du pt A
            //les deux derniers paramètres prennent le x et y du pt B
        SDL_ExitWithError("Il est Impossible de dessiner un point");
*/

    if (SDL_RenderFillRect(renderer, &rectangle1) !=0)
        SDL_ExitWithError("Impossible de dessiner un rectangle");

    if (SDL_RenderFillRect(renderer, &rectangle2) !=0)
        SDL_ExitWithError("Impossible de dessiner un rectangle");


    SDL_RenderPresent(renderer); //fonction qui affiche le rendu et va prendre en paramètre renderer
    SDL_Delay(3000);

    /*------------------------------------------------------------------------------------------------------------------*/

    SDL_DestroyTexture(texture);
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