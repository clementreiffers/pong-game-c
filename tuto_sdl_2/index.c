#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main( int argc, char *argv[ ] )
{
    SDL_Surface *screen;
    if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
    {
        printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }

    atexit( SDL_Quit ); 
    screen = SDL_SetVideoMode( 640, 480, 16, SDL_HWSURFACE );

    if( screen == NULL )
    {
        printf( "Can't set video mode: %s\n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }   

    SDL_Delay( 3000 );

    return EXIT_SUCCESS;
}