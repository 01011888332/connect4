#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char place[8][7];
int Height=8,Width=7;
char disc='X';
int col=0;
int scores1=0;
int scores2=0;
int row_to_be_checked=0;
void start()
{
    int i,j;
    for(i=0; i<Height; i++)
    {
        for(j=0; j<Width; j++)
        {
            place[i][j]=' ';
        }
    }
}
void pick()
{
    int i;
    while(1)
    {
        printf("choose column\n");
        scanf("%d",&i);
        if(i<Width+1&&i>=0)
        {
            col=i-1;
        }
        else
        {
            printf("Enter a correct number\n\n\n");
            col=-1;
        }
        if(place[0][col]==' ')
        {
            fillCol();
            boardd();
            disc = (disc == 'X') ? 'O' : 'X';
            break;
        }
        /*boardd();*/
    }
}
void fillCol()
{
    int i;
    for(i=Height-1; i>=0; i--)
    {
        if(place[i][col]==' ')
        {
            place[i][col]=disc;
            row_to_be_checked=i;
            break;
        }
    }
    if(disc=='X')
    {
        /*row score*/
        /*score_in_row(Width-1,row_to_be_checked,&scores1);
        /*column score*/
        /*score_in_coloumn(Height-1,col-1,&scores1);*/
       score_in_row(row_to_be_checked,col-1,&scores1);
        score_in_coloumn(row_to_be_checked,col-1,&scores1);


    }
    else
    {
        score_in_row(row_to_be_checked,col-1,&scores2);
        score_in_coloumn(row_to_be_checked,col-1,&scores2);
        /*score_in_row(Width-1,row_to_be_checked,&scores2);
        score_in_coloumn(Height-1,col-1,&scores2);*/

    }
}
void enterance()
{
    int mode;
    printf("choose your mode:\n\n");
    printf("          1- single player\n");
    printf("          2- multiplayer\n");
}
int modeNumber(int x)
{
    scanf("%d",&x);
    if(x==1)
    {

    }
    else if(x==2)
    {

    }
    else
    {
        printf("Enter the right number");
    }
}
void boardd()
{
    system("cls");
    int i,j;
    for(i =0; i<Height; i++)
    {
        for(j=0; j<Width; j++)
        {
            printf("|---|");
        }
        printf("\n");
        for(j=0; j<Width; j++)
        {
            printf("| %c |",place[i][j]);
        }
        printf("\n");
    }
    for(int y=0; y<Width; y++)
    {
        printf("-----");
    }
    printf("\n");
    printf("player 1 score = %d\n",scores1);
    printf("player 2 score = %d\n",scores2);
}
void score_in_row(int row,int coloumn,int*score)
{
  int counter=0;
    if(coloumn+3<=Width-1&&coloumn-3>=0)
    {
        for(int i=coloumn-3; i<=coloumn+3; i++)
        {
            for(int k=i; k<=coloumn+3-i; k++)
            {
                if(place[row][k]==disc)
                {
                    counter++;
                    if(counter==4)
                    {
                        (*score)++;
                        counter=0;
                    }
                }
                else
                {
                    counter=0;
                }
            }
        }
    }
    if(coloumn+3>Width-1)
    {
        for(int i=coloumn-3; i<=Width-1; i++)
        {
            for(int k=i; k<=Width-1-i; k++)
            {
                if(place[row][k]==disc)
                {
                    counter++;
                    if(counter==4)
                    {
                        (*score)++;
                        counter=0;
                    }
                }
                else
                {
                    counter=0;
                }
            }
        }
    }
    if(coloumn-3<0)
    {
        for(int i=0; i<=coloumn+3; i++)
        {
            for(int k=i; k<=coloumn+3; k++)
            {
                if(place[row][k]==disc)
                {
                    counter++;
                    if(counter==4)
                    {
                        (*score)++;
                        counter=0;
                    }
                }
                else
                {
                    counter=0;
                }
            }
        }



    }



}
void score_in_coloumn(int row,int coloumn,int*score)
{
    int counter=0;
    if(row-3>=0&&row+3<= Height-1)
    {
        for(int i=row-3; i<=row+3; i++)
        {
            for(int k=i; k<=row+3-i; k++)
            {
                if(place[k][coloumn]==disc)
                {
                    counter++;
                    if(counter==4)
                    {
                        (*score)++;
                        counter=0;
                    }
                }
                else
                {
                    counter=0;
                }
            }
        }
    }
    if(row-3<0)
    {
        for(int i=0; i<=row+3; i++)
        {
            for(int k=i; k<=row+3-i; k++)
            {
                if(place[k][coloumn]==disc)
                {
                    counter++;
                    if(counter==4)
                    {
                        (*score)++;
                        counter=0;
                    }
                }
                else
                {
                    counter=0;
                }
            }
        }
    }
    if(row+3> Height-1)
    {
        for(int i=row-3; i<=Height-1; i++)
        {
            for(int k=i; k<=Height-1-i; k++)
            {
                if(place[k][coloumn]==disc)
                {
                    counter++;
                    if(counter==4)
                    {
                        (*score)++;
                        counter=0;
                    }
                }
                else
                {
                    counter=0;
                }
            }
        }
    }

}
/*void score_in_row(int moving_direction,int constant_position,int *Score)
{
    int counter=0;
    for(int i=moving_direction; i>=0; i--)
    {
        if(place[constant_position][i]==disc)
        {
            counter++;
            if(counter==4)
            {
                *Score++;
                counter=0;
            }
        }
        else
        {
            counter=0;
        }
    }
}
void score_in_coloumn(int moving_direction,int constant_position,int *Score)
{
    int counter=0;
    for(int i=moving_direction; i>=0; i--)
    {
        if(place[i][constant_position]==disc)
        {
            counter++;
            if(counter==4)
            {
                *Score++;
                counter=0;
            }
        }
        else
        {
            counter=0;
        }
    }

}
void score_in_diagonal(int horizontal,int vertical,int *Score){
    int counter=0;
    int p;
    int j= vertical;
    for(int i=horizontal;i<width;i++){
            p=i;
        if(place[i][j]==disc){
                counter++;
        }
    if(place[i-1][j-1]==dics){
        counter++;
    }
    if(counter==4){
        *score++;
        counter=0;
    }


    }


}*/
int main()
{
    start();
    boardd();
    while(1)
    {
        pick();
        printf("\n\n\n");
        boardd();
    }
    return 0;
    //hhhhnnnmmmkkkhhjjnnnnnnnnnmmmmmm

}
