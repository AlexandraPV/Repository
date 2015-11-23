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

int red = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN| BACKGROUND_RED | BACKGROUND_INTENSITY;
int blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY| BACKGROUND_BLUE | BACKGROUND_INTENSITY;
int Y =12;
int X = 39;
int m=0,n=0;
int a = 0;
float k=1;
Color(red);
while(1)
{
    Color(red);
    system("cls");

    Color(red);
printf("F(x) = 2 / (3 * x + 3)\n");
printf("F(x) = sin(x^2) + cos(x)^2");
Y=12;
if ((Y >= 0) && (Y-12 <= 24)){
for (X = 79; X >= 0; X--){
PosCursor(X+m*k, Y+n*k);
if ((X%3)==0) printf("+");
else printf("-");
}
}

X = 39;
if ((X >= 0) && (X <= 79)){
for (Y = 24; Y >= 0; Y--){
PosCursor(X+m*k, Y+n*k);
if ((Y%2)==0) printf("+");
else printf("|");
}
}



float Y0=0;
float X0=0;

float p;
 for (X0=0; X0<=79; X0+=0.01){
     if(X0!=38+m)
{Y0=k*(-(2 / (3 * (X0-39-m) + 3)) + 12+n);

 if (Y0>=0 && Y0<=24){
 PosCursor(X0, Y0);
  Color(red);

 printf ("*");
}}
}


float Y1=0;
float X1=0;

 for (X1=0; X1<=79; X1++){
Y1=-((sin(pow(X1-m,2)) + cos(pow(X1-39-m,2)))*k) + 13+n;

 if (X1>=0 && X1<=79 && Y1>=0 && Y1<=24){
 PosCursor(X1, Y1);
 Color(blue);
 printf ("*");

}
}
char F = getch();
switch(F)
{
   case 'p': k=k*2; break;
   case 'n': k=k/2; break;
   case 'l': m=m-1; break;
   case 'r': m=m+1; break;
   case 'd':n= n+1; break;
   case 'u': n= n-1; break;
   case 13: exit(1); break;

}

}
blue = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;
Color(blue);
return 0;
}




