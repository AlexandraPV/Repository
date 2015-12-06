#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

void Pos(int X,int Y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=X;
    pos.Y=Y;
    SetConsoleCursorPosition(hConsole, pos);
}
int Nullfunktion (int mas[], int size){        //Обнулити всі елементи масиву
    int i;
    for (i=0; i<size; i++)
        mas[i]=0;
    return mas[i];
}

void PrintMas(int mas[],int size)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    Pos(0,6);
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE |FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_INTENSITY | BACKGROUND_BLUE);
    puts("                                                           ");
    int j;

        for(j=0; j<size; j++)
        {
            SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE |FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            Pos(35-size*3+j*6+j,6);
            printf("%d ",*(mas+j));
        }
    printf("                                                                                                                                                                                ");
}


void PrintConsole(int size)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int i,j;
    for(i=0; i<80; i++)
        for(j=0; j<=12; j++)
        {
            Pos(i,j);
            SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE|FOREGROUND_BLUE |FOREGROUND_RED| FOREGROUND_GREEN );
            printf(" ");

        }
}
int IndexNum (int mas[], int size, int in, int num){      // Змінити елемент масиву за введеним індексом на введене значення
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int check1, check2;
    printf("index = ");
    check1 = scanf("%d", &in);
    fflush(stdin);
    printf("numeric = ");
    check2 = scanf("%d", &num);
    if (check1!=1 || check2!=1){
     fflush(stdin);
     Pos(3,20);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("error");
    Sleep(500);
    system("kotik.jpg");
    }
    else
    {
    fflush(stdin);
    mas[in]=num;
    }

    return 0;
}

int Random (int mas[], int size, int a,int b){    //Заповнити випадковими числами у діапазоні, який ввів користувач
    int j;
    for ( j=0; j<size; j++){
        mas[j] = rand()%(b-a) + a;
    }
    return 0;
}

int NewMas (int mas[], int size){  //Вивести елементи масиву у зворотньому порядку
    int j=0;
    int mas2[size];
int i;
    for ( i=size-1; i>=0; i--)
    {
        mas2[j]=mas[i];
        j++;
    }

    for (i=0; i<size; i++)
        mas[i]=mas2[i];
        return 0;
}

int * NegativeV(int mas[], int size,int *A){          //Вивести тільки від'ємні елементи масиву
    static int masnew[20];
    int j=0;
    int i;
    for (i = 0; i < size; i++)
        if (mas[i]<0)
        {
            *(masnew+j)=mas[i];
            j++;
        }

    *A=j;
    return masnew;
}

int NegQ(int mas[], int size){       //Вивести кількість від'ємних елементів масиву
    int q=0;
    int i;
    for (i = 0; i < size; i++){
        if (mas[i]<0)
            q++;
    }
    return q;
}

int Slide(int mas[], int size){   //Простий зсув вправо (нові значення заповнювати нулями) на введену кількість позицій
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("quantity simple = ");
    int qus, check;
    int i;
    check =scanf("%d", &qus);
    if (!check==1){
    fflush(stdin);
     Pos(3,20);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("error");
   Sleep(500);
    system("kotik1.jpg");
    }
    else {
    fflush(stdin);
    for(i=size-1;i>=0;i--)
    {
        if (i<qus) mas[i]=0;
        else
            mas[i]=mas[i-qus];
    }}
    return 0;
}

int ZuklSlide(int mas[], int size){    //Циклічний зсув вправо на введену кількість позицій
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("quantity cycle = ");
    int quc, check;
    int i,j, c;
    check=scanf("%d", &quc);
    if (!check==1){
    fflush(stdin);
     Pos(3,20);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("error");
    Sleep(500);
    system("kotik2.jpg");
    }
    else {
    fflush(stdin);
    for (j=0; j<quc;j++){
        c=mas[size-1];
        for (i=size-1; i>0;i--)
            mas[i]=mas[i-1];
        mas[0]=c;}}
    return 0;
}



 int Degree(int mas[], int size){     //Підняття всіх елементів до визначеного користувачем степеня
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     int st, check;
     printf("Degree = ");
     check=scanf("%d",&st);
     if (!check==1){
    fflush(stdin);
     Pos(3,20);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("error");
    Sleep(500);
    system("kotik5.jpg");
    }
    else {
     fflush(stdin);
     int i;
     for (i=0; i<size; i++){
         mas[i]=pow(mas[i],st);
         }
         }
     return 0;
 }

int MinV (int mas[], int size){    //Вивід першого мінімального значення масиву і його індексу
    int i;
    int minValue;

    minValue = mas[0];
    for(i = 0; i < size; ++i)
    {
        if (mas[i] < minValue )
            minValue = mas[i];
    }
    return minValue;}

int MinI (int mas[], int size){
    int i;
    int minIndex = 0;
    int minValue = mas[0];

    for(i = 0; i < size; ++i)
    {
        if (mas[i] < minValue )
        {
            minValue = mas[i];
            minIndex = i;
        }
    }

       return minIndex;
}

int ChangeV (int mas[], int size){          //Поміняти перший мінімальний і останній максимальний елементи місцями
    int minIndex= MinI( mas, size);
    int minValue = MinV(mas, size);
    int maxIndex;

    int maxValue = mas[0];
int i;
    for( i = 0; i < size; ++i) {
        if (mas[i] >= maxValue ) {
            maxValue = mas[i];
            maxIndex=i;
        }
    }

    mas[minIndex] = maxValue;
    mas[maxIndex] = minValue;
    return 0;
}

void Exit(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int i, j;
    for( i=0; i<80; i++)
        for( j=0; j<35; j++)
        {
            Pos(i,j);
            SetConsoleTextAttribute(hConsole,7);
            printf(" ");
        }
}
void Clean(void){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE |FOREGROUND_RED | FOREGROUND_GREEN);
Pos(0,15);
for (pos.X=0; pos.X<=80; pos.X++){
    for (pos.Y=15; pos.Y<=45;pos.Y++ ){
    SetConsoleCursorPosition(hConsole, pos);
      printf(" ");
    }
}
}
void DeletSpace(char text[78])
{
    int a;
    while(text[0]==' ')
    {
        for( a=0; a<=77; a++)
            text[a]=text[a+1];
    }
    text[78]=' ';
}

int main(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    const char *comand[]= {" ",
                           "exit                 Exit the program",
                           "null                 Null all elements of the array",
                           "random               fill an array of numbers in the range from F to S (S>F)",
                           "v_change             changes the element with index A introduced C",
                           "reverse              bring the array elements in reverse order",
                           "v_neg                bring only negative array elements",
                           "q_neg                bring the number of negative elements in the array",
                           "simplslide           simple shift right on the number of items entered",
                           "zuklslide            cyclic shift to the right ",
                           "degree               raising all elements to a user-defined degree",
                           "min                  minimum output of the first array and its index",
                           "replace              first change the minimum and maximum latter locations"};

    int size;
    int A,B,k=0;
    int R;
    int i, check1, check2;
    int a,b, in, num;
    int D;
   double C;
    int r=0;
    int F=0,S=1;
    char text[78];
    char* str;

    srand(time(NULL));
    for(pos.Y=7; pos.Y<=13; pos.Y++)
    {

        for(pos.X=24; pos.X<=56; pos.X++)
        {
            Pos(pos.X,pos.Y);
            SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE );
            printf(" ");
        }
        printf(" \n");
    }
    while(k==0)
    {
        Pos(33,10);
        puts("                         ");
        Pos(28,8);
        SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE |FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_INTENSITY | BACKGROUND_BLUE);
        printf("Enter the array size(1..11)");
        Pos(33,10);
        SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE |FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_INTENSITY | BACKGROUND_BLUE);
        for(i = 0; i < 78 && text[i-1] != 13; i++)
        {
            text[i] = getch();
            putchar(text[i]);
        }
        text[i+1] = '\0';
        size=atoi(text);
        if (size<1||size>11)
        {
            Pos(34,12);
            SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE );
            printf("error");
            Sleep(500);
            system("kotik.jpg");
            k=0;
        }
        else k=1;
    }


    int mas[size];
    Nullfunktion(mas, size);

    PrintConsole(size);
    Pos(0,13);
    SetConsoleTextAttribute(hConsole,0);
    puts("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ");
    PrintMas(mas,size);
    do
    {
        Pos(0,0);
        SetConsoleTextAttribute(hConsole, 7);
        Pos(0,14);
        printf(">>                                                                                                  ");
        Pos(2,14);
        str = gets(text);
        DeletSpace(text);
        if(strcmp(str,"exit")==0)
        {

            Exit();
            break;
        }
        if(strcmp(str,"null")==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            Nullfunktion (mas, size);
            PrintMas(mas,size);
             getch();
            Clean();
        }
        if(strcmp(str,"random")==0)
        {

            for(i=0; i<=11; i++)
            {
                SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE );
                Pos(3,i);
                puts("                                                                                           ");
            }
            SetConsoleTextAttribute(hConsole, 7);
            Pos(0,15);
            printf("Enter range\n");
            check1 = scanf("%d", &a);
            fflush(stdin);
            check2 = scanf("%d", &b);
           if ((check1!=1) || (check2!=1)){
    fflush(stdin);
     Pos(3,20);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("error");
    Sleep(500);
    system("kotik4.jpg");
    }
    else {
            fflush(stdin);
            Random(mas, size,a,b);
            PrintMas(mas,size);
            Pos(3,16);
             SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE |FOREGROUND_RED | FOREGROUND_GREEN );
            printf("                                                            ");
    }
           getch();
          Clean();
        }
         if(strcmp(str,"v_change")==0)
        {
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            Pos(0,15);
             IndexNum(mas, size, in, num);
             PrintMas(mas,size);
            Pos(3,20);
             getch();
            Clean();
        }
        if(strcmp(str,"reverse")==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            NewMas (mas, size);
            PrintMas(mas,size);
             getch();
            Clean();
        }
         if(strcmp(str,"help")==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            for(i=1; i<=12; i++)
            {
                SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_INTENSITY  );
                Pos(3,17+i);
                puts(comand[i]);
            }
            SetConsoleTextAttribute(hConsole,7 );
            getch();
            Clean();
        }
         if(strcmp(str,"q_neg")==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            int q_neg;
            q_neg =NegQ(mas, size);
            Pos(3,17);
            printf("number of negative elements in the array: %d",q_neg);
            getch();
            Clean();
        }

         if(strcmp(str,"simplslide")==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            Slide (mas, size);
            PrintMas(mas,size);
            getch();
            Clean();
        }
        if(strcmp(str,"zuklslide")==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            ZuklSlide(mas, size);
            PrintMas(mas,size);
            getch();
            Clean();
        }
        if(strcmp(str,"degree")==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            Degree(mas, size);
            PrintMas(mas,size);
            getch();
            Clean();
        }
        if(strcmp(str,"min")==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            int min_v, min_q;
            min_v =MinV(mas, size);
            Pos(3,17);
            printf("min element: %d",min_v);
            min_q =MinI(mas, size);
            Pos(3,19);
            printf("index min element: %d",min_q);
            getch();
            Clean();
        }
            if(strcmp(str,"v_neg")==0)
            {
                size_t size_neg;
                int * mas_neg = NegativeV(mas,size, &size_neg);
                PrintMas(mas_neg,size_neg);
                getch();
                Clean();
            }
         if(strcmp(str,"replace")==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            ChangeV(mas, size);
            PrintMas(mas,size);
            getch();
            Clean();
        }

            if( strcmp(text,"replace")!=0 && strcmp(text,"v_neg")!=0 && strcmp(text,"min")!=0 &&
               strcmp(text,"degree")!=0 && strcmp(text,"zuklslide")!=0 && strcmp(text,"simplslide")!=0 && strcmp(text,"q_neg")!=0 &&
               strcmp(text,"help")!=0 && strcmp(text,"reverse")!=0 && strcmp(text,"v_change")!=0 && strcmp(text,"random")!=0 &&
               strcmp(text,"null")!=0 && strcmp(text,"exit")!=0)
                {
                Pos(3,20);
                SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("error");
                Sleep(500);
                system("kotik5.jpg");
                getch();
                Clean();
            }
    }

   while(1);
    SetConsoleTextAttribute(hConsole, 7);
    Pos(0,25);
    system("pause");
    return 0;
}
