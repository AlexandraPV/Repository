#include "director.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>
#include <libxml/tree.h>


int main()
{
    const char *file = "director.xml";
    DIRECTOR *directors[4];
    

    for(int i = 0; i < 4; i++)
    {
        directors[i] = director_new();
    }
    
    docXML(directors, file);
    
    for(int i = 0; i < 4; i++)
    {
        printf("%i\n", (i+1));
        print_director(directors[i]);
    }

    for(int i = 0; i < 4; i++)
    {
        director_delete(directors[i]);
    }
    return 0;
}
