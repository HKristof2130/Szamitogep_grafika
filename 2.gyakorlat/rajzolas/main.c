#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Color{
    int red;
    int green;
    int blue;

}Color;

typedef struct Line{
    int x1Coord;
    int y1Coord;
    int x2Coord ;
    int y2Coord ;
    Color lineColor;
}Line;

void getColor(Color* c);
void setLineColor(Line l);
void setLine(Line* l);


int main(int argc, char *argv[])
{
    Line l1;
    l1.x2Coord = -1;
    l1.y2Coord = -1;

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_OPENGL);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


    bool running = true;
    SDL_Event event;
    while(running)
    {
        // Process events
        while(SDL_PollEvent(&event))
        {
            if(SDL_MOUSEBUTTONDOWN){
                SDL_GetMouseState(&l1.x1Coord,&l1.y1Coord);
                while(l1.x2Coord < 0 && l1.y2Coord < 0){
                    if(SDL_MOUSEBUTTONDOWN){
                        SDL_GetMouseState(&l1.x2Coord,&l1.y2Coord);
                    }
                }
                SDL_RenderDrawLine(renderer, l1.x1Coord, l1.y1Coord, l1.x2Coord, l1.y2Coord);
            }

            if(event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw

        // Show what was drawn
        SDL_RenderPresent(renderer);
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("x1: %d y1: %d \nx2: %d y2: %d \n",l1.x1Coord,l1.y1Coord,l1.x2Coord,l1.y2Coord);
    return 0;
}

void getColor(Color* c){

    int red,green,blue;
    bool ok;
    printf("Mi legyen az RGB r-piros arnyalata?\n");
    ok=false;
    do{
        scanf("%d",&red);
        if( red>255 || red<0){
            printf("Legyen 0-255 kozott!\n");
        }else ok=true;
    }while(!ok);

    printf("Mi legyen az RGB g-zold arnyalata?\n");
    ok=false;
    do{
        scanf("%d",&green);
        if( green>255 || green<0){
            printf("Legyen 0-255 kozott!\n");
        }else ok=true;
    }while(!ok);

    printf("Mi legyen az RGB b-kek arnyalata?\n");
    ok=false;
    do{
        scanf("%d",&blue);
        if( blue>255 || blue<0){
            printf("Legyen 0-255 kozott!\n");
        }else ok=true;
    }while(!ok);

    c->red = red;
    c->green = green;
    c->blue = blue;

    return;
}

void setLine(Line* l){

    int x,y;
    printf("Add meg az X koordinatat: ");
    scanf("%d",&x);
    printf("Add meg az Y koordinatat: ");
    scanf("%d",&y);
    l->x1Coord = x;
    l->y1Coord = y;
    getColor(&l->lineColor);

    return;

}

void setLineColor(Line l){


}
