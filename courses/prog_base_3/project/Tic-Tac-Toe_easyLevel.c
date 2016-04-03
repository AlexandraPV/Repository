#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POINT ' ' 
char field[3][3] = { 
    {POINT, POINT, POINT},
    {POINT, POINT, POINT},
    {POINT, POINT, POINT}
} ;
void computer_step_easy(void);
void player_step(void);
void game_field(void);
char status_of_game (void);
void game();

int main()
{
    game();
    return 0;
}

void player_step(void)
{
    int x, y;
    printf("Enter coordinates for your X (Row Column):\n");
    scanf ("%d %d", &x, & y);
    
    x--; y--;
    if (x<0 || y<0 || x>2 || y>2 || field[x][y] !=POINT)
    {
        printf("Incorrect move, try again.\n");
        player_step();
    }
    else field[x][y]='X';
}

void computer_step_easy(void)
{
    int i;
    char *n = (char *) field;
    for (i=0; *n!=POINT && i<9; i++)
        n++;
    if(i==9)
    {
        printf("Draw\n");
        exit(0); /* game over */
    }
    else *n = 'O';
}


void game_field(void)
{
    int i;
    for(i=0; i<3; i++)
    {
        printf(" %c | %c | %c", field[i][0], field[i][1], field[i][2]);
        if(i!=2) printf("\n---|---|---\n");
    }
    printf("\n");
}

char status_of_game(void)
{
    int i;
    char *n;
    for(i=0; i<3; i++) { 
        n = &field[i][0];
        if (*n==*(n+1) && *(n+1)==*(n+2))
            return *n;
    }
    for(i=0; i<3; i++) { 
        n = &field[0][i];
        if(*n==*(n+3) && *(n+3)==*(n+6))
            return *n;
    }
  
    if(field[0][0]==field[1][1] && field[1][1]==field[2][2] )
        return field[0][0];
    if(field[0][2]==field[1][1] && field[1][1]==field[2][0])
        return field[0][2];
    return POINT;
}

void game(){
    srand(time(NULL));
    char done;
    printf("You will be playing against the computer.\n");
    done = POINT;
    do {
        game_field(); 
        player_step();
        done = status_of_game(); 
        if (done!=POINT)
            break; 
        computer_step_easy();
        done=status_of_game(); 
    } while(done==POINT);
    if(done=='X')
        printf("You win!\n");
    else printf("You lose!\n");
    game_field();
}
