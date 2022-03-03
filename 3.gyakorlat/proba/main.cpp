#include <exception>
#include <string>
#include <iostream>
#include <stdbool.h>
#include <SDL.h>


#define WIDTH 800
#define HEIGHT 600

int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Ablak cime",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer,0,255,255,255);

     bool running = true;
     SDL_Event event;
     while(running){

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
            }
        }

        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

     }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 1;
}
