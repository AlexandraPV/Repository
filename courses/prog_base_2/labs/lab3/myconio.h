//
//  myconio.h
//  wow
//
//  Created by Alexandra on 02.03.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#ifndef myconio_h
#define myconio_h

#include <stdio.h>
void gotoxy (int x, int y);
void clrscr ();
void setAttribute (int attribute);
void setColors (int mainColor, int backgroundColor);
int getch ();
int kbhit ();
void Sleep (double millisecs);
#endif /* myconio_h */
