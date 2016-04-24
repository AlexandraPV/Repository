#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myconio.h"
#include <locale.h>

int** field;
int X, Y;

void init()
{
    setlocale(0,"");
    int x,y, i,j;
    srand(time(NULL));
    for(i=1; i<=15;)
    {
        x=rand()%4; y=rand()%4;
        if(field[x][y] == 0) field[x][y] = i++;
    }
    
    for(i=0; i<4; i++) //to find the empty cell
        for(j=0; j<4; j++)
            if(field[j][i] == 0)
            {
                X=j; Y = i;
                return;
            }
    
}


void printField()
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            if(field[j][i]) printf("%3d", field[j][i]);
            else printf(" _");
        printf("\n\n");
    }
    printf("\n\n");
}


int play()
{
    int i,j;
    for(i=0; i<3; i++)
        for(j=0; j<4; j++)
            if(field[j][i] != 4*i+j+1)
                return 0; //go on play
    if(field[0][3] != 13)
        return 0;
    
    return 1; //victory!
}


int game()
{
    char c;
   
    while(1)
    {
        c = getch();
        switch (c)
        {
        case 'a':
            if(X==0)
            {
                printf("Is not available\n\n");
                break;
            }
            else
            {
                field[X][Y] = field[X-1][Y];
                field[X-1][Y] = 0;
                X--;
                return 1;
            }
        case 'w':
            if(Y==0)
            {
                printf("Is not available\n\n");
                break;
            }
            else
            {
                field[X][Y] = field[X][Y-1];
                field[X][Y-1] = 0;
                Y--;
                return 2;
            }
        case 'd':
            if(X==3)
            {
                printf("Is not available\n\n");
                break;
            }
            else
            {
                field[X][Y] = field[X+1][Y];
                field[X+1][Y] = 0;
                X++;
                return 3;
            }
        case 's':
            if(Y==3)
            {
                printf("Is not available\n\n");
                break;
            } 
            else 
            { 
                field[X][Y] = field[X][Y+1]; 
                field[X][Y+1] = 0; 
                Y++; 
                return 4; 
            } 
        case 'q': exit(1); 
            
                printf("Welcome to the game of Barley-break\n");
                printf("To move the empty cells:\n");
                printf("Up W\n");
                printf("Down S\n");
                printf ("Left A\n");
                printf("Right D\n ");
        } 
    } 
} 


int main() 
{ 
    field = (int**)calloc(4, sizeof(int*)); 
    for(int i=0; i<4; i++) 
        field[i] = (int*)calloc(4, sizeof(int)); 
    
    do	init();
    while(play());
    printf("Welcome to the game of Barley-break\n");
    printf("To move the empty cells:\n");
    printf("Up W\n");
    printf("Down S\n");
    printf ("Left A\n");
    printf("Right D\n ");
    printField();
    
    while(!play())
    {
        game();
        printField(); 
    } 
    
    printf("\n You win!\n");
    getch();
    return 0;
}
