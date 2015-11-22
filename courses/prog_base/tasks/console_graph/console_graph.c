#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<conio.h>

void PosCursor (int x, int y){
COORD coord = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, coord);
}

void Color(int color)
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, color);


}

int main (){

printf("F(x) = - 2 / (4 * x - 1) - 1\n");
printf("F(x) = sin(x^2) + cos(x)^2");
int red = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN| BACKGROUND_RED | BACKGROUND_INTENSITY;
int blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY| BACKGROUND_BLUE | BACKGROUND_INTENSITY;
int Y =12;
int X = 39;
if ((Y >= 0) && (Y <= 24)){
for (X = 79; X >= 0; X--){
PosCursor(X, Y);
if ((X%3)==0) printf("+");
else printf("-");
}
}

X = 39;
if ((X >= 0) && (X <= 79)){
for (Y = 24; Y >= 0; Y--){
PosCursor(X, Y);
if ((Y%2)==0) printf("+");
else printf("|");
}
}



int Y0=0;
int X0=0;
int k=1;
 for (X0=0; X0<=79; X0++){
Y0=-((- 2) / ((pow(4,X0) - 1) - 1)*k);
X0+=X;
Y0+=Y;
 if (X0>=0 && X0<=79 && Y0>=0 && X0<=24){
 PosCursor(X0, Y0);
  Color(red);

 printf ("*");
}
}


int Y1=0;
int X1=0;

 for (X1=0; X1<=79; X1++){
Y1=-((sin(pow(X1,2)) + cos(pow(X1,2)))*k);
X1+=X;
Y1+=Y;
 if (X1>=0 && X1<=79 && Y1>=0 && X1<=24){
 PosCursor(X1, Y1);
 Color(blue);
 printf ("*");

}
}
char F = getch();
switch(F)
{
   case '+': {k=k*2;} break;
   case '-': {k=k/2;} break;
   case 'l': {X=X-1;} break;
   case 'f': {X=X+1;} break;
   case 'd': {Y=Y+1;} break;
   case 'u': {Y=Y-1;} break;
}
return 0;
}


