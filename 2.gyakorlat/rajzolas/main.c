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
    float xCoord;
    float yCoord;
    Color lineColor;
}Line;

void getColor(Color* c);
void setLine(Line* l);


int main(int argc, char *argv[])
{
    Line l1;
    setLine(&l1);
    printf("A vonal adatai:\nX koordinata: %f\nY koordinata: %f\nPiros: %d\nZold: %d\nKek: %d\n",l1.xCoord,l1.yCoord,l1.lineColor.red,l1.lineColor.green,l1.lineColor.blue);


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

    float x,y;
    printf("Add meg az X koordinatat: ");
    scanf("%f",&x);
    printf("Add meg az Y koordinatat: ");
    scanf("%f",&y);
    l->xCoord = x;
    l->yCoord = y;
    getColor(&l->lineColor);

    return;

}
