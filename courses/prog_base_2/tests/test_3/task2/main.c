//
//  main.c
//  #2
//
//  Created by Alexandra on 13.06.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "Parking.h"

int main()
{
    park_t * park = park_new(3);
    car_t * car1 = car_new(1, "stepa");
    park_in(park, car1);
    printf("Cars in park:%i, Free place: %i\n", list_size(park_get_cars(park)), park_get_free_pl(park));
    
    list_t list = park_get_in_hist(park, 5);
    for (int i = 0; i < list_size(list); i++)
        puts(car_get_name((car_t *)list_get(list, i)));
   
    park_out(park, car1);
    printf("Cars in park:%i,Free place:  %i\n", list_size(park_get_cars(park)), park_get_free_pl(park));
    printf("All place in park: %i", park_get_all_pl(park));
    park_get_out_hist(park, 5);
    
    return 0;
}





