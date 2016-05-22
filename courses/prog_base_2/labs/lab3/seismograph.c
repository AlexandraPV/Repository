//
//  seismograph.c
//  Lab_2_3
//
//  Created by Alexandra on 20.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//
#include <stdlib.h>

#include "Header.h"

struct seismograph_s{
    event_t *event;
    int status;
    int count;
};

seismograph_t *seismograph_new(){
    seismograph_t *self = malloc(sizeof(seismograph_t));
    self->event=event_new();
    self->status=0;
    return self;
}
void seismograph_free(seismograph_t * self){
    free(self);
}

event_t * seism_get_event(seismograph_t * seism){
    return seism->event;
}

void seism_check(seismograph_t * seism){
    if (!seism->status)
        return;
    int i = rand()%10;
    if (i>5){
        seism->count++;
        if(seism->count>=3)
            event_earthquake(seism->event,i);
    }else seism->count=0;
}

void seismograph_status(seismograph_t * seism){
   // printf("off");
    if (seism->status == 1)
    {
       seism->status = 0;
        event_off(seism->event, 0);
    }
    else seism->status = 1;
}