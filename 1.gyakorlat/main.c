#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Brick{
    int aoldal;
    int boldal;
    int coldal;

} Brick;

void setSize( Brick b);
int calcVolume( Brick b);
int calcSurface( Brick b);

int main()
{
    Brick test;

    setSize(test);
    printf(" a test a: %d  b: %d c:%d",test.aoldal,test.boldal,test.coldal);
    printf(" A test felszine: %d \t terfogata: %d",calcSurface(test),calcVolume(test));

    return 0;
}


void setSize( Brick b){

    bool ok;
    ok=false;
    do{
        printf("Adja meg az a el hooszat:");
        scanf("%d",&b.aoldal);
        if(b.aoldal < 1){
            printf("Nem lehet 1 nel kisebb az el!\n");
        }else ok=true;
    }while(!ok);

    ok= false;

    do{
        printf("Adja meg az b el hooszat:");
        scanf("%d",&b.boldal);
        if(b.boldal < 1){
            printf("Nem lehet 1 nel kisebb az el!\n");
        }else ok=true;
    }while(!ok);

    ok=false;

    do{
        printf("Adja meg az c el hooszat:");
        scanf("%d",&b.coldal);
        if(b.coldal < 1){
            printf("Nem lehet 1 nel kisebb az el!\n");
        }else ok=true;
    }while(!ok);

    return ;
}

int calcVolume( Brick b){

    int volume;
    volume = b.aoldal*b.boldal*b.coldal;

    return volume;

}

int calcSurface( Brick b){

    int surface;
    surface = 2*(b.aoldal+b.boldal+b.aoldal+b.coldal+b.boldal+b.coldal);

    return surface;

}
