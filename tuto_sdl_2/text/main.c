// #include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>
// #include <stdio.h>
// #include <stdlib.h>

// // void drawText (SDL_Surface* screen, char* string, int size, int x, int y, int fR, int fG, int fB, int bR, int bG, int bB);

// int main(int argc, char *argv[])
// {
// 	SDL_Window *window = NULL; //pointeur par défaut pour la fenêtre
// 	SDL_Renderer *renderer = NULL; //pointeur qui va créer un rendu
// 	int continuer = 1;
// 	// dimension des raquettes et sa vitesse

// 	//lancement SDL
//     SDL_Init(SDL_INIT_VIDEO);
//     /*
// 	if (SDL_Init(SDL_INIT_VIDEO) != 0)
// 		SDL_ExitWithError("initialisation SDL");*/

// 	//création fenêtre + rendu
// 	int width = 0;
// 	int height = 0;
// 	// ici on initialise la fenetre en fullscreen
//     SDL_CreateWindowAndRenderer(width,height, SDL_WINDOW_MAXIMIZED, &window, &renderer);
// 	/*if (SDL_CreateWindowAndRenderer(width,height, SDL_WINDOW_MAXIMIZED, &window, &renderer) != 0) 
// 		SDL_ExitWithError("Impossible de creer rendu et fenêtre");*/
// 	// on recupere la taille de la fenetre
// 	width = SDL_GetWindowSurface(window)->w;
// 	height = SDL_GetWindowSurface(window)->h;


// 	while(continuer)
// 	{
// 		TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24); //this opens a font style and sets a size

// 		SDL_Color White = {255, 255, 255};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

// 		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

// 		SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

// 		SDL_Rect Message_rect; //create a rect
// 		Message_rect.x = 0;  //controls the rect's x coordinate 
// 		Message_rect.y = 0; // controls the rect's y coordinte
// 		Message_rect.w = 100; // controls the width of the rect
// 		Message_rect.h = 100; // controls the height of the rect

// 		//Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understand

// 		//Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

// 		SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

// 		//Don't forget to free your surface and texture
// 		SDL_FreeSurface(surfaceMessage);
// 		SDL_DestroyTexture(Message);
//         SDL_RenderPresent(renderer); //fonction qui affiche le rendu et va prendre en paramètre renderer	
//     }
//     SDL_DestroyRenderer(renderer);
// 	SDL_DestroyWindow(window);
// 	SDL_Quit();

// 	return EXIT_SUCCESS;
// }
// /*
// void drawText (SDL_Surface* screen, char* string, int size, int x, int y, int fR, int fG, int fB, int bR, int bG, int bB)
// {
// 	TTF_Init();
// 	TTF_Font* font = TTF_OpenFont("ARIAL.TTF", size);

// 	SDL_Color foregroundColor = { fR, fG, fB };
// 	SDL_Color backgroundColor = { bR, bG, bB };

// 	SDL_Surface* textSurface = TTF_RenderText_Shaded(font, string, foregroundColor, backgroundColor);

// 	SDL_Rect textLocation = { x, y, 0, 0 };

// 	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

// 	SDL_FreeSurface(textSurface);

// 	TTF_CloseFont(font);

// }*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
int main(int argc, char ** argv)
{
 int quit = 0;
 SDL_Event event;
 SDL_Init(SDL_INIT_VIDEO);
 TTF_Init();
 SDL_Window * window = SDL_CreateWindow("SDL_ttf in SDL2",
  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
  480, 0);
 SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
 TTF_Font * font = TTF_OpenFont("arial.ttf", 25);
//  const char * error = TTF_GetError();
 SDL_Color color = { 255, 255, 255 };
 SDL_Surface * surface = TTF_RenderText_Solid(font,
  "Welcome to Programmer's Ranch", color);
 SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
  surface);
 int texW = 0;
 int texH = 0;
 SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
 SDL_Rect dstrect = { 0, 0, texW, texH };
 while (!quit)
 {
  SDL_WaitEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
   quit = 1;
   break;
  }
  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
  SDL_RenderPresent(renderer);
 }
 SDL_DestroyTexture(texture);
 SDL_FreeSurface(surface);
 TTF_CloseFont(font);
 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 TTF_Quit();
 SDL_Quit();
 return 0;
}