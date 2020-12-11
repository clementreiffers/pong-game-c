#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

//#define WAV_PATH "musique_de_fond.wav"
//#define MUS_PATH "musique_de_fond.wav"

// Our wave file
Mix_Chunk *wave = NULL;
// Our music file
Mix_Music *music = NULL;

void SDL_ExitWithError(const char *message);



int main(int argc, char* argv[])

{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

		

	//lancement SDL
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) !=0 )
		SDL_ExitWithError("Initialisation SDL");

	//vrétaion fenêtre et rendu
	if(SDL_CreateWindowAndRenderer(1920, 1080, 0, &window, &renderer) !=0)
		SDL_ExitWithError("Impossible de creer la fenetre et le rendu");


	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	Mix_Music *backgroundSound = Mix_LoadMUS("musique_de_fond.wav");

	Mix_PlayMusic(backgroundSound, -1);
//---------------------------------------------------------------------------------------

SDL_Surface *image = NULL;
SDL_Texture *texture = NULL;

image = SDL_LoadBMP("Arcade.bmp");

if(image == NULL)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_ExitWithError("Impossible de charger l'image");


}

texture = SDL_CreateTextureFromSurface(renderer, image);
SDL_FreeSurface(image);

if(texture == NULL)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_ExitWithError("Impossible de charger la texture");
}

SDL_Rect rectangle;

if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) !=0)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_ExitWithError("Impossible de charger la texture");
}

rectangle.x = (1980 - rectangle.w)/2;
rectangle.y = (1080 - rectangle.h)/2;

if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) !=0)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_ExitWithError("Impossible d'afficher la texture");

}

SDL_RenderPresent(renderer);

SDL_Delay(6000);


//----------------------------------------------------------------------------------------

SDL_DestroyTexture(texture);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
Mix_FreeMusic(backgroundSound);
SDL_Quit();

return EXIT_SUCCESS;

}

void SDL_ExitWithError(const char *message)
{
	SDL_Log("Erreur : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}



