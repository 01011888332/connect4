//دي حركه دي حركه دي حركه
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
char save[]="save";
char load[]="load";
char undo[]="undo";
char redo[]="redo";
char yes[]="yes";
char LOAD[]="load";
char user_answer[10];
char disc;
int current_col;
int current_row;
int counter1=0;
int counter2=0;
int board_printing_controller=0;
int row_stack[150];
int column_stack[150];
int width =8;
int height = 8;
char board[150][150];
int score_1=0, score_2=0,row,col ;
void diagonal2_score(int* s);
void diagonal1_score(int* s);
void columns_score(int* s);
void rows_score(int* s);
void check_score(int* score);
void get_row();
void fill_board(int p);
void switch_turns(int a);
void game_mode();
void print_board();
void start();
int main()
{
    int starter=1;
    start();
    score_1=0,score_2=0;
    while(starter==1){
        printf("return to main menu ???\n");
        gets(user_answer);
        if(strcmp(user_answer,yes)==0){
            start();
        }
        else{
            starter=0;
        }

    }
    return 0;
}
void start()
{
    system("cls");
 system("color 01");
     int i,j;
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            board[i][j]='.';
        }
    }
    int choose;
    printf("                   \t\t\tConnect 4 Game\n                ");
    printf("\n\n");
    printf("                  \t\t\t\t 1-New Game\n\n\n                     ");
    printf("                  \t 2-Load Game\n\n\n                   ");
    printf("                  3-High Score\n                   ");
    printf("\n\n\n\n");
    printf("                                    \t\t\t\t\t by: Eng.Omar Aldawy\n");
    printf("                                        \t\t\t\t\t Eng.Bahaa Khaled\n\n");
    printf("   Enter Your Selection Number: ");
    scanf("%d",&choose);
    switch(choose){
    case 1:
        game_mode(); break;
    case 2:
        //لسه معرفش
        break;
    case 3:
        //لسه معرفش
        break;
        default: break;
    }
}
void print_board()
{
    system("cls");
    int i,j;
    for(i =0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            printf("|---|");
        }
        printf("\n");
        for(j=0; j<width; j++)
        {
            printf("| %c |",board[i][j]);
        }
        printf("\n");
    }
    for(int y=0; y<width; y++)
    {
        printf("-----");
    }
    printf("\n");
    printf("player 1 score = %d\n",score_1);
    printf("player 2 score = %d\n",score_2);
}
void game_mode()
{
    int choice=0;
    if(user_answer[0]!='l'|| strcmp(user_answer,load)!=0){
          printf("\n\n\n\n\n");
    printf("                      \t\t\t\t 1- Player Vs Player \n\n\n");
    printf("                      \t\t\t\t 2- Player Vs Computer\n\n\n\n");
    printf("    Enter Your Selection Mode: ");
    scanf("%d",&choice);
    print_board();
    //stack();
    }
    if(choice==1){
        for(int i=0;i<width*height;i++){
            switch_turns(i);
        }

    }
}
void switch_turns(int a){
    if(a%2==0){
       printf("player 1 turn\n choose the column you want to play in: ");
       scanf("%d",&current_col);
       column_stack[counter1++]=current_col-1;
       get_row(); 
       fill_board(a);
    }
    else{
        printf("player 2 turn\n choose the column you want to play in: ");
        scanf("%d",&current_col);
        column_stack[counter1++]=current_col-1;
        get_row();
        fill_board(a);
    }
}
void get_row(){
    for(int j=0;j<=height-1;j++){
        if(board[j][current_col-1]=='.')
        current_row=j;
        row_stack[counter2++]=j;
    }
}
void fill_board(int p){
    if (p%2==0){
        board[current_row][current_col-1]='X';
        disc='X';
        score_1=0;
        check_score(&score_1);
    }
    else{
        board[current_row][current_col-1]='O';
        disc='O';
        score_2=0;
        check_score(&score_2);
    }
    print_board();
}
void check_score(int* scores){
    rows_score(scores);
    columns_score(scores);
    diagonal1_score(scores);
    diagonal2_score(scores);
}
void rows_score(int* s){
    int counter=0;
    for(int j=height-1;j>=0;j--){
        for(int c=width-1;c>=0;c--){
            for(int k=c;k>=0;k--){
                if(board[j][k]==disc){
                    counter++;
                    if(counter==4){
                        (*s)++;
                        counter=0;
                    }
                }
                else
                {
                counter=0;
                break;
                }

        }
    }
}
}
void columns_score(int* s){
    int counter=0;
    for(int j=width-1;j>=0;j--){
        for(int c=height-1;c>=0;c--){
            for(int k=c;k>=0;k--){
                if(board[k][j]==disc){
                    counter++;
                    if(counter==4){
                        (*s)++;
                        counter=0;
                    }


                }
                else{
                counter=0;
                break;
            }

        }
    }
}

}
void diagonal1_score(int* s){
    int a=0;
    int counter=0;
    for(int j=0;j<=height-1;j++){
        for(int p=0;p<=width-1;p++){
            a=0;
            for(int k=p;k<=width-1;k++){
                if(board[j+a][k]==disc){
                    counter++;
                    if(counter==4){
                        (*s)++;
                        counter=0;
                    }

                }
                else{
                counter=0;
                break;
            }
            a++;
            }
        }
    }

}
void diagonal2_score(int* s){
     int a=0;
    int counter=0;
    for(int j=0;j<=height-1;j++){
        for(int p=width-1;p>=0;p--){
            a=0;
            for(int k=p;k>=0;k--){
                if(board[j+a][k]==disc){
                    counter++;
                    if(counter==4){
                        (*s)++;
                        counter=0;
                    }

                }
                else
                {
                    counter=0;
                break;
                }
                a++;
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
    //hhhh

}