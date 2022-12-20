#include <studio.h>
#include <stdlib.h>
#include <string.h>

void boardd(int Height,int Width){
    //fscanf(file,%d %d,&Height,&Width);         //مش عارف هيبقي كده ولا لا
    for(int i =0;i<Width;i++){
        for(int j=0;j<Height;j++){
            printf("|---|");
        }
        printf("\n");
        for(int x=0;x<Height;x++){
            printf("|   |");
        }
        printf("\n");
    }
    for(int y=0;y<Height;y++){
        printf("-----");
    }
}
