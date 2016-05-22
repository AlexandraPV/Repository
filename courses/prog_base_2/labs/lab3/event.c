//
//  event.c
//  Lab_2_3
//
//  Created by Alexandra on 20.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//


#include "Header.h"


struct event_s{
    user_t * users[10];
    int count;
};

event_t *event_new(){
    event_t * self = malloc(sizeof(event_t));
    for(int i=0; i<10; i++)
    self->users[i] = NULL;
    self->count = 0;
    return self;
}


void event_free(event_t * self){
    free(self);
}

int  event_contains(event_t * ev,user_t * user_h){
    for ( int i=0; i< ev->count; i++){
    if ( ev->users[i] == user_h)
        return 1;
    }
    return 0;
}

void event_add_user(event_t * ev,user_t * new_user){
    for (int i=0; i<10; i++){
    if(ev!=NULL && new_user != NULL && ev->users[i] == NULL){
        ev->users[i]=new_user;
        ev->count++;
        return ;
    }
    }
}


void event_earthquake(event_t * ev,int val){
    for(int i =0; i<10; i++){
        if(getCollback1 (ev->users[i])!= NULL){
            getCollback1(ev->users[i])(val);
        }
        
    }
}


void event_off(event_t * ev,int val){
    for(int i =0; i<10; i++){
        if(getCollback2 (ev->users[i])!= NULL){
            getCollback2(ev->users[i])(val);

        }
        
    }
}




