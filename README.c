#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//fscanf(file,%d %d,&Height,&Width);         //مش عارف هيبقي كده ولا لا
const int Width=7,Height=5;
char place[Width][Height];
void start(){
    for(int i=0;i<Width;i++){
        for(int j=0;j<Height;j++){
            place[i][j]=' ';
        }
    }
}

void enterance(){
    printf("choose your mode:\n\n");
    printf("          1- single player\n");
    printf("          2- multiplayer\n");
}

void boardd(int Width,int Height ){
    int i,j;
    for(i =0;i<Width;i++){
        for(j=0;j<Height;j++){
            printf("|---|");
        }
        printf("\n");
        for(int x=0;x<Height;x++){
            printf("| %c |",place[i][j]);
        }
        printf("\n");
    }
    for(int y=0;y<Height;y++){
        printf("-----");
    }
}

int main(){
    enterance();
    boardd(Width,Height);
    return 0;
}
