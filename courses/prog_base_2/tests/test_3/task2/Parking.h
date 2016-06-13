//
//  Parking.h
//  Parking
//
//  Created by Alexandra on 13.06.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#ifndef Parking_h
#define Parking_h

#include <stdio.h>
#include "list.h"
typedef struct park_s park_t;
typedef struct car_s car_t;

park_t * park_new(int count);
int park_in(park_t * p, car_t * car);
int park_out(park_t * p, car_t *car);
list_t park_get_cars(park_t * p);
list_t park_get_in_hist(park_t * p, int n);
list_t park_get_out_hist(park_t * p, int n);
int park_get_all_pl(park_t * p);
int park_get_free_pl(park_t * p);
car_t * car_new(int id, char * name);



#endif /* Parking_h */
