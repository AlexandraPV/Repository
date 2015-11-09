#include <stdio.h>
#include <unistd.h>
#include "myconio.h"


int width = 79;
int height = 23;

void makeColorfulStar (int color) {
    setAttribute((color == 2) ? 47 : color + 42);
}

void starPrint (int x, int y) {
    switch ((height - x) % 3) {
        case 0:
            makeColorfulStar(y % 3);
            break;
        case 1:
            makeColorfulStar(((y % 3) == 2) ? 0 : (y % 3) + 1);
            break;
        case 2:
            makeColorfulStar(((y % 3) == 0) ? 2 : (y % 3) - 1);
            break;
    }
    Sleep(1000);
    gotoxy(x, y);
    
    printf("*");
}

void perform () {
    int x = 0;
    int y = width;
    
    starPrint (x, y);
    y--;
    
    starPrint (x, y);
    
    while (1) {
        /////// Point 1
        
        do {
            x++;
            y++;
            
            starPrint (x, y);
            
        } while ((x != height) && (y != width));
        
        /////// Point 2
        
        if (x == height) {
            y--;
        } else {
            x++;
        }
        
        starPrint (x, y);
        
        if ((x == height) && (y == 0)) {
            break;
        }
        
        /////// Point 3
        
        do {
            x--;
            y--;
            
            starPrint (x, y);
            
        } while ((x != 0) && (y != 0));
        
        /////// Point 4
        
        if (x == 0) {
            y--;
        } else {
            x++;
        }
        
        starPrint (x, y);
        
        if ((x == height) && (y == 0)) {
            break;
        }
        
    }
}

int main () {
    
    clrscr();
    perform();
    setAttribute(0);
    getchar();
    
    clrscr();
    return 0;
}
