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


//code qui marche pour l'affichage d'une fenêtre et d'un rendu mais trop complexe a expliqué

#include<SDL2/SDL.h>
#include<stdio.h>
 
const int WIDTH  = 640;
const int HEIGHT = 480;
 
int main(int argc, char** argv)
{
  SDL_Window *win = 0;
  SDL_Renderer *ren = 0;
 
  /* Initialisation de la SDL. Si ça se passe mal, on quitte */
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
      fprintf(stderr,"Erreur initialisation\n");
      return -1;
  }
  /* Création de la fenêtre et du renderer */
  SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &ren); // SDL_WINDOW_SHOWN|SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC,&win,&ren);
 
  if (!win || !ren) 
     {
        fprintf(stderr,"Erreur à la création des fenêtres\n");
        SDL_Quit();
        return -1;
     }
  /* Affichage du fond noir */
  SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
  SDL_RenderClear(ren);
  SDL_RenderPresent(ren);
 
  SDL_Delay(4000);
 
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}

/*

//creation d'une fenêtre
    window = SDL_CreateWindow("PONG SDL2",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1500,800,0);

    if (window == NULL)
        SDL_ExitWithError("creation fentre echouee");



renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE); 
                                //pour les paramètres
                                    //1er : fenêtre où l'on va afficher le rendu
                                    //2eme : -1 corresponds au driver
                                    //3eme : type de rendu choisis

    if (renderer == NULL)
        SDL_ExitWithError("Creation rendu echouee"); // on reutilise la focntion Exit si le rendu ne marche pas

*/