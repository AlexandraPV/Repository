#include "Parking.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <string.h>


struct B{
    char *name;
    char *timeIn;
    char *timeFrom;
    int numberOFcar;
    
};

struct A{
    int count;
    bool empty;
    CAR all[MAX_COUNT_CAR];
};


CAR * car_new(char * name, char * timeIN, int numberOFcar){
    CAR * st = malloc(sizeof(struct A));
    st->name = name;
    st->timeIn=timeIN;
    st->timeFrom = 0;
    st->numberOFcar = numberOFcar;
    return st;

   
}
void car_free(CAR *car){
    free(car);
}

PARKING * park_new(int count){
    PARKING * st = malloc(sizeof(struct A));
}
void park_free(PARKING *park){
    free(park);
}

int count_all_park(PARKING * park);
int count_empty_park(PARKING * park);

void enter_car(PARKING * park, CAR * car);
void exit_car(PARKING * park, CAR * car);

void list_of_car(PARKING *park);
void info_person(CAR * car);

void history_of_ener(PARKING * park, int N);
