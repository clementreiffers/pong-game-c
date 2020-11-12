#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
	les differents types rendus:

		SDL_RENDERER_SOFTWARE	   (acceleration depuis le processeur)
		SDL_RENDERER_ACCELERATED   (acceleration matèriel utlisation de la carte graphique)
		SDL_RENDERER_PRESENTVSYNC  (rendu pour la synchronisation verticale)
		SDL_RENDERER_TARGETTEXTURE (rendus pour les textures)
*/

void SDL_ExitWithError(const char *message); //fonction creee pour afficher un message lorsque la fenêtre ne peut s'afficher
SDL_Rect createRect(int x, int y, int w, int h); // fonction qui cree notre rectangle
void ellipse(SDL_Renderer* r, int x0, int y0, int radiusX, int radiusY); // fonction qui cree nos ellipses
void compteur(SDL_Renderer* r, float w, float y); // fonction qui cree notre compteur

int main(int argc, char *argv[])
{
	SDL_Window *window = NULL; //pointeur par défaut pour la fenêtre
	SDL_Renderer *renderer = NULL; //pointeur qui va créer un rendu
	int continuer = 1;
	// dimension des raquettes et sa vitesse
	int largeur = 5;
	int longueur = 100;
	int vitesse_raquette = 1;
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
    float dx = 1;
	int sx = 1; // son signe en x
    //float dy = (rand() % 3)+1; // sa norme en vitesse en y
    float dy = 1;
	int sy = 1; // son signe en y
    int r = 5; // son rayon

	while(continuer)
	{
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
							continuer = 0;
						break;
						// on verifie qu'on peut faire le mouvement sinon on teleporte
						
						case SDLK_z:
							if(rectangle1.y <= 0){
								rectangle1.y = height-longueur;
							}
							else {
								rectangle1.y -= vitesse_raquette;
							}
						break;

						case SDLK_s:
							if(rectangle1.y >= height){
								rectangle1.y = 0;
							}
							else {
								rectangle1.y += vitesse_raquette;
							}
						break;

						case SDLK_UP:
							if(rectangle2.y <= 0){
								rectangle2.y = height-longueur;
							}
							else {
								rectangle2.y -=vitesse_raquette;
							}
						break;

						case SDLK_DOWN:
							if(rectangle2.y >= height){
								rectangle2.y = 0;
							}		
							else {
								rectangle2.y +=vitesse_raquette;
							}
					}
				case SDL_KEYUP:
					switch(evenement.key.keysym.sym)
					{
			case SDLK_z:
				if(rectangle1.y <= 0){
					rectangle1.y = height-longueur;
				}
				else {
					rectangle1.y -= 50;
				}
			break;
			case SDLK_s:
				if(rectangle1.y >= height){
					rectangle1.y = longueur;
				}
				else {
					rectangle1.y += 50;
				}
			break;
			case SDLK_UP:
				if(rectangle2.y <= 0){
					rectangle2.y = height-longueur;
				}
				else {
					rectangle2.y -=50;
				}
			break;
			case SDLK_DOWN:
				if(rectangle2.y >= height-longueur){
					rectangle2.y = longueur;
				}		
				else {
					rectangle2.y +=50;
				}
			}
		}
	}
		


		SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		SDL_RenderClear(renderer);


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

        y<=0+r || y>=height-r ? sy=-sy, dy = sy: 1; // * ((rand()%3)+1): 1;
		// rebond de la balle sur la raquette gauche
		x<=rectangle1.x+largeur && y >=rectangle1.y && y<= rectangle1.y+longueur ? sx=-sx, dx = sx * ((rand()%3)+1) : 1;
		// rebond raquette droite
		x>=rectangle2.x && y >= rectangle2.y && y<=rectangle2.y+longueur ? sx=-sx, dx = sx * ((rand()%3)+1) : 1;
		
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
SDL_Rect createRect(int x, int y, int w, int h) {
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;

	return rectangle;
}
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
void compteur(SDL_Renderer* r, float w, float h){
    SDL_RenderDrawLine(r, w/2-100, 0, w/2-100, h/15);
    SDL_RenderDrawLine(r, w/2+100, 0, w/2+100, h/15);
    SDL_RenderDrawLine(r, w/2-100, h/15, w/2+100, h/15);

	/* ajouter le texte à mettre dans la fenetre ici */

}