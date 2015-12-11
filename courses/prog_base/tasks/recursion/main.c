#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


char Recurs(char *str, int i){
    if (i== (strlen(str)-1) )
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
    char *str=malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%s", str);
    
    
    printf("Smaller value: %d", Function (Recurs(str, 0)));
    free(str);
    return 0;
    
}
