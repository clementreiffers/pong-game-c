#include<SDL2/SDL.h>

void compteur(SDL_Renderer* r, float w, float h){
    SDL_RenderDrawLine(r, w/2-100, 0, w/2-100, h/15);
    SDL_RenderDrawLine(r, w/2+100, 0, w/2+100, h/15);
    SDL_RenderDrawLine(r, w/2-100, h/15, w/2+100, h/15);
}