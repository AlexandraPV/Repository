//
//  Parking.h
//  test#2
//
//  Created by Alexandra on 13.06.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#ifndef Parking_h
#define Parking_h

#include <stdio.h>
#define MAX_COUNT_CAR 20

typedef struct A PARKING;
typedef struct B CAR;

CAR * car_new(char * namem, char * timeIN,  int numberOFcar);
void car_free(CAR *car);

PARKING * park_new(int count);
void park_free(PARKING *park);

int count_all_park(PARKING * park);
int count_empty_park(PARKING * park);

void enter_car(PARKING * park, CAR * car);
void exit_car(PARKING * park, CAR * car);

void list_of_car(PARKING *park);
void info_person(CAR * car);

void history_of_ener(PARKING * park, int N);






#endif /* Parking_h */
