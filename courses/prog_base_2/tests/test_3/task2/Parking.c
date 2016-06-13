//
//  Parking.c
//  Parking
//
//  Created by Alexandra on 13.06.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include "Parking.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

typedef struct park_s
{
    int count;
    int free_count;
    list_t history_in;
    list_t history_out;
    list_t cars;
} park_t;

typedef struct car_s
{
    int id;
    char * name;
} car_t;

park_t * park_new(int count)
{
    park_t * park = malloc(sizeof(struct park_s));
    park->count = count;
    park->free_count = count;
    park->history_in = list_new();
    park->history_out = list_new();
    park->cars = list_new();
    return park;
}

int park_in(park_t * p, car_t * car)
{
    if (p->free_count > 0)
    {
        list_add(p->history_in, car, 0);
        list_add(p->cars, car, 0);
        p->free_count--;
        return 1;
    }
    return 0;
}

int park_out(park_t * p, car_t *car)
{
    for (int i = 0; i < list_size(p->cars); i++)
        if (list_get(p->cars, i) == car)
        {
            list_add(p->history_out, car, 0);
            list_del(p->cars, i);
            p->free_count++;
            return 1;
        }
    return 0;
}

list_t park_get_cars(park_t * p)
{
    list_t list = list_new();
    for (int i = 0; i < list_size(p->cars); i++)
        list_add(list, list_get(p->cars, i), i);
    return list;
}

list_t park_get_in_hist(park_t * p, int n)
{
    list_t list = list_new();
    for (int i = 0; i < list_size(p->history_in) && i < n; i++)
        list_add(list, list_get(p->history_in, i), i);
    return list;
}
list_t park_get_out_hist(park_t * p, int n)
{
    list_t list = list_new();
    for (int i = 0; i < list_size(p->history_out) && i < n; i++)
        list_add(list, list_get(p->history_out, i), i);
    return list;
    
}

int park_get_all_pl(park_t * p)
{
    return p->count;
}
int park_get_free_pl(park_t * p)
{
    return p->free_count;
}
car_t * car_new(int id, char * name)
{
    car_t * car = malloc(sizeof(struct car_s));
    car->id = id;
    car->name = malloc(sizeof(char) * strlen(name));
    strcpy(car->name, name);
    return car;
}
