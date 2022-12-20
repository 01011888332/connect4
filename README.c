#include <stdio.h>
#include <stdlib.h>
char place[8][7];
int Height=8,Width=7;
char disc='X';
int col=0;
void start(){
    int i,j;
    for(i=0;i<Height;i++){
        for(j=0;j<Width;j++){
            place[i][j]=' ';
        }
    }
}
void pick(){
    int i;
    while(1){
        printf("choose column\n");
        scanf("%d",&i);
        if(i<Width+1&&i>=0){
            col=i-1;
        }
        else{
            printf("Enter a correct number\n\n\n");
            col=-1;
        }
        if(place[0][col]==' '){
            fillCol();
            disc = (disc == 'X') ? 'O' : 'X';
            break;
        }
        boardd();
    }
}
void fillCol(){
    int i;
    for(i=Height-1;i>=0;i--){
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
void boardd(){
    int i,j;
    for(i =0;i<Height;i++){
        for(j=0;j<Width;j++){
            printf("|---|");
        }
        printf("\n");
        for(j=0;j<Width;j++){
            printf("| %c |",place[i][j]);
        }
        printf("\n");
    }
    for(int y=0;y<Width;y++){
        printf("-----");
    }
    printf("\n");
}

int main(){
    start();
    boardd();
    while(1){
        pick();
        printf("\n\n\n");
        boardd();
    }
    return 0;
}
