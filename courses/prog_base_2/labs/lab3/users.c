//
//  user.c
//  Lab_2_3
//
//  Created by Alexandra on 20.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//

#include <stdio.h>
#include "Header.h"

struct user_s{
    char *name;
    int id;
    callb callback1;
    callb callback2;
};


user_t *user_new(char * new_user, int id_s){
    user_t *self = malloc(sizeof(user_t));
    self->name = new_user;
    self->id = id_s;
    self->callback1 = NULL;
    self->callback2 = NULL;
    return self;
}

void user_free(user_t * self){
    free (self);
}

int user_subscribe_1(user_t * user, callb callback, seismograph_t * seism)
{
    if(user != NULL && seism != NULL){
    user->callback1 = callback;
    if (!event_contains(seism_get_event(seism), user))
        event_add_user(seism_get_event(seism), user);
        return 1;
    }
    else return 0;
}
int user_subscribe_2(user_t * user, callb callback,seismograph_t * seism)
{
    if(user != NULL && seism != NULL){
    user->callback2 = callback;
    if (!event_contains(seism_get_event(seism), user))
        event_add_user(seism_get_event(seism), user);
        return 1;
    }
    else return 0;
}

callb getCollback1(user_t *us){
    if (us == NULL)
        return NULL;
    return us->callback1;
}

callb getCollback2(user_t *us){
    if (us == NULL)
        return NULL;
    return us->callback2;
}





