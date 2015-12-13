#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isHexadecimal (char ch) {
    return (isdigit (ch) || ((ch >= 'a') && (ch <= 'f')) || ((ch >= 'A') && (ch <= 'F')));
}

char Recurs(char *str, int i){
    if (i== (strlen(str)-1))
        return (tolower(str[0])<tolower(str[i])) ? str[0] : str[i];
    else
        return Recurs(str, i + 1);
}

int Function (char symbol){
    
    if (isdigit(symbol))
        return symbol-48;
    else
        symbol=tolower(symbol);
    return symbol-87;
}

int main()
{
    int i;
    char *str=malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%s", str);
    if (isHexadecimal(str[0]) && (isHexadecimal(str[strlen(str) - 1])))
        printf("Smaller value: %d", Function (Recurs(str, 0)));
    else
        printf("Error! First and last characters are not valid hexadecimal numbers");
    free(str);
    return 0;
    
}
