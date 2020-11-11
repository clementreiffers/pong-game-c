
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ellipse(SDL_Renderer* r, int x0, int y0, int radiusX, int radiusY)
{
    float pi  = 3.14159265358979323846264338327950288419716939937510;
    float pih = pi / 2.0; //half of pi

    //drew  28 lines with   4x4  circle with precision of 150 0ms
    //drew 132 lines with  25x14 circle with precision of 150 0ms
    //drew 152 lines with 100x50 circle with precision of 150 3ms
    const int prec = 27; // precision value; value of 1 will draw a diamond, 27 makes pretty smooth circles.
    float theta = 0;     // angle that will be increased each loop

    //starting point
    int x  = (float)radiusX * cos(theta);//start point
    int y  = (float)radiusY * sin(theta);//start point
    int x1 = x;
    int y1 = y;

    //repeat until theta >= 90;
    float step = pih/(float)prec; // amount to add to theta each time (degrees)
    for(theta=step;  theta <= pih;  theta+=step)//step through only a 90 arc (1 quadrant)
    {
        //get new point location
        x1 = (float)radiusX * cosf(theta) + 0.5; //new point (+.5 is a quick rounding method)
        y1 = (float)radiusY * sinf(theta) + 0.5; //new point (+.5 is a quick rounding method)

        //draw line from previous point to new point, ONLY if point incremented
        if( (x != x1) || (y != y1) )//only draw if coordinate changed
        {
            SDL_RenderDrawLine(r, x0 + x, y0 - y,    x0 + x1, y0 - y1 );//quadrant TR
            SDL_RenderDrawLine(r, x0 - x, y0 - y,    x0 - x1, y0 - y1 );//quadrant TL
            SDL_RenderDrawLine(r, x0 - x, y0 + y,    x0 - x1, y0 + y1 );//quadrant BL
            SDL_RenderDrawLine(r, x0 + x, y0 + y,    x0 + x1, y0 + y1 );//quadrant BR
        }
        //save previous points
        x = x1;//save new previous point
        y = y1;//save new previous point
    }
    //arc did not finish because of rounding, so finish the arc
    if(x!=0)
    {
        x=0;
        SDL_RenderDrawLine(r, x0 + x, y0 - y,    x0 + x1, y0 - y1 );//quadrant TR
        SDL_RenderDrawLine(r, x0 - x, y0 - y,    x0 - x1, y0 - y1 );//quadrant TL
        SDL_RenderDrawLine(r, x0 - x, y0 + y,    x0 - x1, y0 + y1 );//quadrant BL
        SDL_RenderDrawLine(r, x0 + x, y0 + y,    x0 + x1, y0 + y1 );//quadrant BR
    }
}

void SDL_ExitWithError(const char *message); //fonction creee pour afficher un message lorsque la fenêtre ne peut s'afficher

//draw one quadrant arc, and mirror the other 4 quadrants


int main(int argc, char *argv[])
{
	SDL_Window *window = NULL; //pointeur par défaut pour la fenêtre
	SDL_Renderer *renderer = NULL; //pointeur qui va créer un rendu
	int continuer = 1;
  int width = 500;
  int height = 500;

	//lancement SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("initialisation SDL");

	//création fenêtre + rendu

	if (SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) != 0) 
		SDL_ExitWithError("Impossible de creer rendu et fenêtre");

  float x = 100;
  float y = 100;
  float dx = rand() % 4;
  int sx = 1;
  float dy = rand() % 4;
  int sy = 1;
  int r = 10;
	while(continuer)
	{
		SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer,0,0,0,0);
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
          }
			}
		}
		if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) !=0)
			SDL_ExitWithError("Il n'est pas possible de changer la couleur");

    ellipse(renderer, x, y, r, r);
    x+=dx;
    y+=dy;

    x<=0+r || x>=width-r ? sx=-sx, dx = sx * rand()%4 : 1;
    y<=0+r || y>=height-r ? sy=-sy, dy = sy * rand()%4 : 1;

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