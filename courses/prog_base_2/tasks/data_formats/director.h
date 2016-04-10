#ifndef director_h
#define director_h

#include <stdio.h>
#include <time.h>

typedef struct {
    char name[20];
    char specialization[20];
} COMPANY;

typedef struct{
    char name[10];
    char surname[20];
    struct tm birthDate;
    COMPANY company;
    int year;
    float rating;
} DIRECTOR;

DIRECTOR *director_new(void);
COMPANY *startup_new(void);
void director_delete(DIRECTOR *director);
void company_delete(COMPANY *company);

void docXML(DIRECTOR *directors[], const char * name_of_file);
void print_director (DIRECTOR *director);

#endif /* director_h */
