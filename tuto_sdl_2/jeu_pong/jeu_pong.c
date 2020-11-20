#include <SDL2/SDL.h>
#include "formes.h"
#include <stdio.h>

void pong(SDL_Window *window, SDL_Renderer *renderer, float dx, float dy, float vitesse_raquette){
    int continuer = 1;
	// dimension des raquettes et sa vitesse
	int largeur = 5;
	int longueur = 100;
	//lancement SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("initialisation SDL");

	//création fenêtre + rendu
	int width = 0;
	int height = 0;
	// ici on initialise la fenetre en fullscreen
	if (SDL_CreateWindowAndRenderer(width,height, SDL_WINDOW_MAXIMIZED, &window, &renderer) != 0) 
		SDL_ExitWithError("Impossible de creer rendu et fenêtre");
	// on recupere la taille de la fenetre
	width = SDL_GetWindowSurface(window)->w;
	height = SDL_GetWindowSurface(window)->h;

	// on cree les deux raquettes et on les places en fonction de la taille de l'écran
	SDL_Rect rectangle1 = createRect(20, 200, largeur, longueur); // creation des coordonnées du rectangle
	SDL_Rect rectangle2 = createRect(width-20, 200, largeur, longueur); // creation des coordonnées du rectangle

	// score des deux joueurs
	int J1 = 0;
	int J2 = 0;
	// variables pour la balle
    float x = width/2; // sa position en x
    float y = height/2; // sa position en y
    //float dx = (rand() % 3)+1; // sa norme en vitesse en x
	int sx = 1; // son signe en x
    //float dy = (rand() % 3)+1; // sa norme en vitesse en y
	int sy = 1; // son signe en y
    int r = 5; // son rayon
    while(continuer)
	{
		SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		SDL_RenderClear(renderer);

		raquettes R = deplacement(renderer, rectangle1, rectangle2, height, vitesse_raquette);		
		continuer = exitOrNot();
		rectangle1.y = R.y1;
		rectangle2.y = R.y2;

		if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) !=0)
			SDL_ExitWithError("Il n'est pas possible de changer la couleur");
		
		if (SDL_RenderFillRect(renderer,&rectangle1) !=0 )
			SDL_ExitWithError("Impossible de creer le rectangle de gauche");

		if (SDL_RenderFillRect(renderer,&rectangle2) !=0 )
			SDL_ExitWithError("Impossible de creer le rectangle de droite");
        // on dessine le terrain
        compteur(renderer, width, height);
        ellipse(renderer, width/2, height/2, width/6,width/6);
        SDL_RenderDrawLine(renderer, width/2, 0, width/2, height);

        // on dessine la balle et on gère ses évènements
        ellipse(renderer, x, y, r, r);
        x+=dx;
        y+=dy;



        y<=0+r || y>=height-r ? sy=-sy, dy = sy*dy : 1; // * ((rand()%3)+1): 1;
		// rebond de la balle sur la raquette gauche
		x<=rectangle1.x+largeur && y >=rectangle1.y && y<= rectangle1.y+longueur ? sx=-sx, dx = sx*dx:1;// * ((rand()%3)+1) : 1;
		// rebond raquette droite
		x>=rectangle2.x && y >= rectangle2.y && y<=rectangle2.y+longueur ? sx=-sx, dx = sx*dx :1;//* ((rand()%3)+1) : 1;
		
		// au cas où la balle va là où on ne veut pas
		if (x>rectangle2.x+longueur) {
      		J1++; // on incremente le gagnant
			printf("%d - %d \n", J1, J2); // on affiche le resultat dans le terminale mais il faudra l'afficher dans la fenetre
			x = width/2;
			y = height/2;
    	}
    	if (x<rectangle1.x) {
      		J2++;// on incremente le gagnant
			printf("%d - %d \n", J1, J2); // on affiche le resultat dans le terminale mais il faudra l'afficher dans la fenetre
			x = width/2;
			y = height/2;
    	}
		SDL_RenderPresent(renderer); //fonction qui affiche le rendu et va prendre en paramètre renderer	
	}
}