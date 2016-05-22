//
//  Header.h
//  Lab_2_3
//
//  Created by Alexandra on 20.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include <stdlib.h>
typedef struct seismograph_s  seismograph_t;
typedef struct event_s event_t;
typedef struct user_s user_t;
typedef void (*callb)(int val);

seismograph_t *seismograph_new();
void seismograph_free(seismograph_t * self);

event_t *event_new();
void event_free(event_t * self);

user_t *user_new(char * new_user, int id_s);
void user_free(user_t * self);

event_t * seism_get_event(seismograph_t * seism);
int event_contains(event_t * ev,user_t * user);
void event_add_user(event_t * ev,user_t * new_user);

callb getCollback1(user_t *us);
callb getCollback2(user_t *us);

void event_earthquake(event_t * ev,int val);

int user_subscribe_1(user_t * user, callb callback, seismograph_t * seism);
int user_subscribe_2(user_t * user, callb callback,seismograph_t * seism);

void seism_check(seismograph_t * seism);


void seismograph_status(seismograph_t * seism);

void event_off(event_t * ev,int val);