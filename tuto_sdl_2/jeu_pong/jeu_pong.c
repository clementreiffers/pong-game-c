#include <SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include "formes.h"
#include <stdio.h>

int pong(SDL_Window *window, SDL_Renderer *renderer, float dx, float dy, float vitesse_raquette){
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
	TTF_Init();
	TTF_Font * font = TTF_OpenFont("Digit.ttf", 25);
	SDL_Color white = { 255, 255, 255 };

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
        SDL_Rect rJ1 = {width/2-50,0,50,50};
		SDL_Rect rJ2 = {width/2+50,0,50,50};
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer,&rJ1);
		SDL_RenderFillRect(renderer,&rJ2);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		char strJ1[2];
		sprintf(strJ1, "%d", J1);

		char strJ2[2];
		sprintf(strJ2, "%d", J2);

		SDL_Surface * surfJ1 = TTF_RenderText_Solid(font,  strJ1, white);
		SDL_Texture * texJ1 = SDL_CreateTextureFromSurface(renderer, surfJ1);
		SDL_Surface * surfJ2 = TTF_RenderText_Solid(font, strJ2, white);
		SDL_Texture * texJ2 = SDL_CreateTextureFromSurface(renderer, surfJ2);

		int texW = 0;
		int texH = 0;
		SDL_QueryTexture(texJ1, NULL, NULL, &texW, &texH);
		SDL_QueryTexture(texJ2, NULL, NULL, &texW, &texH);

		SDL_RenderCopy(renderer, texJ1, NULL, &rJ1);
		SDL_RenderCopy(renderer, texJ2, NULL, &rJ2);

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
		if (J1>8) {
			continuer = 0;
		}
		if (J2>8) {
			continuer = 0;
		}
		SDL_RenderPresent(renderer); //fonction qui affiche le rendu et va prendre en paramètre renderer	
	}

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
	int gagnant = J1>8 ?  1 :  2; 
	return gagnant;
}