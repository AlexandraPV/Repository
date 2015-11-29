#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fprocess(const char * pread, const char * pwrite)
{
    FILE * fr = fopen(pread, "r");
    FILE * fw = fopen(pwrite, "w");
    if (fr == NULL || fw == NULL)
        return;
    int a = 0, b = 0;
    for(a = 0; a < 13; a++)
        while (fgetc(fr) != 10);
    fscanf(fr, "%i=%i", &a, &b);
    if ( a == b){
    fprintf(fw, "true");
    }
    else fprintf(fw, "false");
    fclose (fw);
    fclose (fr); 
    
}

int main(void) {
    
    fprocess("temp.txt", "answer.txt");
    
    return 0;
}
