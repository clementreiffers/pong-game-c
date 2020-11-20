#include<SDL2/SDL.h>
#include <stdio.h>

typedef struct Raquettes raquettes;
struct Raquettes
{
	int y1;
	int y2;
};

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

int exitOrNot() {
	SDL_Event evenement; //tous nos evenements seront gérés à partir de cette ligne
	while(SDL_PollEvent(&evenement))//fonction qui va capturer, enregistrer tous les evenements
	{
		switch(evenement.type)
		{
			case SDL_KEYDOWN:
				switch(evenement.key.keysym.sym)
				{
				case SDLK_ESCAPE: //fermeture de la fenetre via la touche echap
						return 0;
				break;
			}
		break;
		}
	}	
	return 1;
}

raquettes deplacement(SDL_Renderer* renderer, SDL_Rect rectangle1, SDL_Rect rectangle2, float height, float dy) {
		SDL_Event evenement; //tous nos evenements seront gérés à partir de cette ligne
		while(SDL_PollEvent(&evenement))//fonction qui va capturer, enregistrer tous les evenements
		{

			switch(evenement.type)
			{
				case SDL_KEYDOWN:
					switch(evenement.key.keysym.sym)
					{
						case SDLK_z:
							if(rectangle1.y <= 0){
								rectangle1.y = height-rectangle1.w;
							}
							else {
								rectangle1.y -= dy;
							}
						break;

						case SDLK_s:
							if(rectangle1.y >= height){
								rectangle1.y = 0;
							}
							else {
								rectangle1.y += dy;
							}
						break;

						case SDLK_UP:
							if(rectangle2.y <= 0){
								rectangle2.y = height-rectangle2.w;
							}
							else {
								rectangle2.y -=dy;
							}
						break;

						case SDLK_DOWN:
							if(rectangle2.y >= height){
								rectangle2.y = 0;
							}		
							else {
								rectangle2.y +=dy;
							}
					}
				case SDL_KEYUP:
					switch(evenement.key.keysym.sym)
					{
			case SDLK_z:
				if(rectangle1.y <= 0){
					rectangle1.y = height-rectangle1.w;
				}
				else {
					rectangle1.y -= 50;
				}
			break;
			case SDLK_s:
				if(rectangle1.y >= height){
					rectangle1.y = rectangle1.w;
				}
				else {
					rectangle1.y += 50;
				}
			break;
			case SDLK_UP:
				if(rectangle2.y <= 0){
					rectangle2.y = height-rectangle2.w;
				}
				else {
					rectangle2.y -=50;
				}
			break;
			case SDLK_DOWN:
				if(rectangle2.y >= height-rectangle2.w){
					rectangle2.y = rectangle2.w;
				}		
				else {
					rectangle2.y +=50;
				}
			}
		}
	}
        
	raquettes R;
	R.y1 = rectangle1.y;
	R.y2 = rectangle2.y;
    return R;
}