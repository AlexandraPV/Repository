#include <stdio.h>

#include "director.h"

void print_dir(const director_t *director)
{
    printf("Name: %s\n", director->name);
    printf("Surname: %s\n", director->surname);
    printf("Budget:%i\n", director->budget);
    printf("Years: %.2f\n", director->years);
    printf("Birthdate: %s\n", director->birthDate);
    
}

void print_AllDir(director_t *director, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%i.", (i+1));
        print_dir(&director[i]);
        printf("");
    }
}
