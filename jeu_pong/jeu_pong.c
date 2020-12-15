#include <SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include "formes.h"
#include <stdio.h>

int pong(SDL_Window *window, SDL_Renderer *renderer, float dx, float dy, float vitesse_raquette, float width, float height){
    int continuer = 1;
	// dimension des raquettes et sa vitesse
	int largeur = 5;
	int longueur = 100;

	// on cree les deux raquettes et on les places en fonction de la taille de l'écran
	SDL_Rect rectangle1 =  { 20, 200, largeur, longueur}; // creation des coordonnées du rectangle
	SDL_Rect rectangle2 = { width-20, 200, largeur, longueur}; // creation des coordonnées du rectangle

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
	TTF_Font * font = TTF_OpenFont("Lazer84.ttf", 25);
	SDL_Color white = { 255, 255, 255 };
    SDL_Rect rJ1 = {width/2-50,0,50,50};
	SDL_Rect rJ2 = {width/2+50,0,50,50};


    while(continuer)
	{
		SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		SDL_RenderClear(renderer);

		// on recupere les entrées claviers
		raquettes R = deplacement(renderer, rectangle1, rectangle2, height, vitesse_raquette);		
		continuer = exitOrNot();

		// selon les entrées clavier, on change la position de nos raquettes
		rectangle1.y = R.y1;
		rectangle2.y = R.y2;

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);	
		SDL_RenderFillRect(renderer,&rectangle1);
		SDL_RenderFillRect(renderer,&rectangle2);
        // on dessine le terrain
        compteur(renderer, width, height);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer,&rJ1);
		SDL_RenderFillRect(renderer,&rJ2);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		// on permet de mettre les score dans des chaines compatible char
		char strJ1[2];
		sprintf(strJ1, "%d", J1);

		char strJ2[2];
		sprintf(strJ2, "%d", J2);

		// on cree nos textes et nos textures
		SDL_Surface * surfJ1 = TTF_RenderText_Solid(font,  strJ1, white);
		SDL_Texture * texJ1 = SDL_CreateTextureFromSurface(renderer, surfJ1);
		SDL_Surface * surfJ2 = TTF_RenderText_Solid(font, strJ2, white);
		SDL_Texture * texJ2 = SDL_CreateTextureFromSurface(renderer, surfJ2);

		// change modifie la texture pour la taille de la police de base
		SDL_QueryTexture(texJ1, NULL, NULL, 0, 0);
		SDL_QueryTexture(texJ2, NULL, NULL, 0, 0);

		// on affiche nos raquettes mais avec la texture
		SDL_RenderCopy(renderer, texJ1, NULL, &rJ1);
		SDL_RenderCopy(renderer, texJ2, NULL, &rJ2);

		// on affiche un cercle au milieu
		ellipse(renderer, width/2, height/2, width/6,width/6);

		// on affiche la separation centrale
        SDL_RenderDrawLine(renderer, width/2, 0, width/2, height);

        // on dessine la balle et on gère ses évènements
        ellipse(renderer, x, y, r, r);
        x+=dx;
        y+=dy;

		// rebond de la balle en haut et en bas
        y<=0+r || y>=height-r ? sy=-sy, dy = sy*dy : 1; 
		// rebond de la balle sur la raquette gauche
		x<=rectangle1.x+largeur && y >=rectangle1.y && y<= rectangle1.y+longueur ? sx=-sx, dx = sx*dx:1;
		// rebond raquette droite
		x>=rectangle2.x && y >= rectangle2.y && y<=rectangle2.y+longueur ? sx=-sx, dx = sx*dx :1;
		
		// au cas où la balle va là où on ne veut pas
		if (x>rectangle2.x+longueur) {
      		J1++; // on incremente le gagnant
			x = width/2;
			y = height/2;
    	}
    	if (x<rectangle1.x) {
      		J2++;// on incremente le gagnant
			x = width/2;
			y = height/2;
    	}
		continuer = J1>8 || J2>8 ? 0 : 1;

		// on refresh le rendu
		SDL_RenderPresent(renderer); 
	}

	// on ferme ce qu'on a initialisé
    TTF_CloseFont(font);
    TTF_Quit();
	// on renvoie le score
	return J1>8 ?  1 :  2;
}