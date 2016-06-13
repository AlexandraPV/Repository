#include <stdio.h>
#include "myconio.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int findString(char * text, char * add);

int main()
{
    
    char s1[200],s0[200];
    //int i, j, s, l;
    printf("Введите первую строку:");
    gets(s1);
    printf("Введите подстроку:");
    gets(s0);
      int l = findString(s1, s0);
    printf("Количество вхождений подстроки = %d",l);
    return 0;
}



int findString(char * text, char * add){
    
    if (strlen(text) > strlen(add))
    {
        return 0;
    }
    int symbol;
    int i,j,l;
    
    for(i = 0, j = 0, symbol = 0; i <= strlen(add); i++)
    {
        if(add[i] == text[j])
        {
            symbol++;
            j++;
            return 1;
        }
        else
        {
            symbol = 0;
            j = 0;
            return 0;

        }
        if(symbol == strlen(text))
        {
            symbol = 0;
            j = 0;
            return 1;
         
        }
        
    }
    
}
    
    
    
