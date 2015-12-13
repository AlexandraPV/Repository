#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char Recurs(char *str, int i, char first, char last){
    char current = tolower(str[i]);
    if (current == '\0') {
        return (first < last) ? first : last;
    }
    if (isxdigit(current)) {
        if (first== 0) {
            first = current;
        } else {
            last = current;
        }
    }
    
   return Recurs(str, i + 1, first, last);
}

int main()
{
    int i;
    char *str=malloc(100*sizeof(char));
    printf("Enter string:");
    scanf("%s", str);
    
    char result = Recurs(str, 0, 0, 0);
    if (result == 0) {
        printf("There are less than 2 hexadecimal values in the string.\n");
    } else {
        printf("The smaller value is %c\n", result);
    }
    free(str);
    return 0;
    
}
