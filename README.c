#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Width=7,Height=5;
char place[Width][Height];
char disc='X';
int col=0;
void start(){
    for(int i=0;i<Width;i++){
        for(int j=0;j<=Height;j++){
            place[i][j]=' ';
        }
    }
}

void fillCol(){
    for(int i=Height-1;i>=0;i--){
        if(place[i][col]==' '){
            place[i][col]=disc;
            break;
        }
    }
}

void enterance(){
    int mode;
    printf("choose your mode:\n\n");
    printf("          1- single player\n");
    printf("          2- multiplayer\n");
}
int modeNumber(int x){
    scanf("%d",&x);
    if(x==1){

    }
    else if(x==2){

    }
    else{
        printf("Enter the right number");
    }
}

void boardd(int Width,int Height){
    int i,j;
    for(i =0;i<Height;i++){
        for(j=0;j<Width;j++){
            printf("|---|");
        }
        printf("\n");
        for(int x=0;x<Width;x++){
            printf("| %c |",place[i][j]);
        }
        printf("\n");
    }
    for(int y=0;y<Height;y++){
        printf("-------");
    }
}

int main(){
    boardd(Width,Height);
    return 0;
}
