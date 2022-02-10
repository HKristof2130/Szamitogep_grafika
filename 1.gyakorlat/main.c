#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Brick{
    int aoldal;
    int boldal;
    int coldal;

} Brick;

void setSize( Brick* b);
int calcVolume( Brick* b);
int calcSurface( Brick* b);
bool isSquare( Brick* b);

int main()
{
    Brick test;

    setSize(&test);
    printf(" A test felszine: %d \t terfogata: %d\n",calcSurface(&test),calcVolume(&test));
    if( isSquare(&test) == true){
        printf("A testnek van negyzet oldallapja\n");
    }else{
        printf("A testnek nincs oldallapja\n");
    }

    return 0;
}


void setSize( Brick* b){

    bool ok;
    ok=false;
    do{
        printf("Adja meg az a el hooszat:");
        scanf("%d",&b->aoldal);
        if(b->aoldal < 1){
            printf("Nem lehet 1 nel kisebb az el!\n");
        }else ok=true;
    }while(!ok);

    ok= false;

    do{
        printf("Adja meg az b el hooszat:");
        scanf("%d",&b->boldal);
        if(b->boldal < 1){
            printf("Nem lehet 1 nel kisebb az el!\n");
        }else ok=true;
    }while(!ok);

    ok=false;

    do{
        printf("Adja meg az c el hooszat:");
        scanf("%d",&b->coldal);
        if(b->coldal < 1){
            printf("Nem lehet 1 nel kisebb az el!\n");
        }else ok=true;
    }while(!ok);

    return ;
}

int calcVolume( Brick* b){

    int volume;
    volume = b->aoldal*b->boldal*b->coldal;

    return volume;

}

int calcSurface( Brick* b){

    int surface;
    surface = 2*(b->aoldal+b->boldal+b->aoldal+b->coldal+b->boldal+b->coldal);

    return surface;

}

bool isSquare( Brick* b){

    bool square;
    square= false;
    if(b->aoldal == b->boldal){
        square=true;
    }else if( b->aoldal == b->coldal){
        square=true;
    }else if(b->boldal == b->coldal){
        square=true;
    }

    return square;

}
