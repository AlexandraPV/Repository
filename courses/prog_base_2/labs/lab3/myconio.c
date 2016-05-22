//
//  myconio.c
//  wow
//
//  Created by Alexandra on 02.03.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include "myconio.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <termios.h>
#include <fcntl.h>

struct timeval now;
int rc;
double nowt;

double nowtime ()

{
    rc = gettimeofday (&now, 0);
    if (rc==0)
    {
        nowt = now.tv_sec + (now.tv_usec/1000000.0);
    }
    else
    {
        printf ("Cannot get current time. Please, try again.");
    }
    return nowt;
}

// x - height, y - width
void gotoxy (int x, int y) {
    printf ("\033[%d;%df", x+1, y+1);
}
void clrscr () {
    printf ("\033[2J");
    printf ("\033[0;0f");
}
void setAttribute (int attribute) {
    printf ("\033[%dm", attribute);
}
void setColors (int mainColor, int backgroundColor) {
    printf ("\033[%d;%dm", mainColor, backgroundColor);
}

int getch ()

{
    struct termios oldt,
    newt;
    int            ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

int kbhit ()

{
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    
    return 0;
}

void Sleep (double millisecs)

{
    double t1, t2;
    double secs = millisecs/1000.0;
    t1 = nowtime ();
    int exit = 0;
    while (exit == 0)
    {
        t2 = nowtime ();
        if ((t2 - t1) > secs)
        {
            exit = 1;
        }
        if (kbhit())
        {
            getch ();
        }
    }
}

void setcursor (int position)

{
    if (position==0)
    {
        printf("\e[?25l");
    }
    else
    {
        printf("\e[?25h");
    }
}