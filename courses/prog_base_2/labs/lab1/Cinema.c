#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <string.h>
#include "Seat.h"
#include "Buyer.h"
#define QUANTITY_SEAT 20
#define MAX_SIZE_OF_NAME 20

struct A{
    int num;
    bool buy;
    bool reservations;
};

struct B{
    char *name;
    SEAT my_seat[5];
    int count;
};


SEAT * seat_new (int i){
    SEAT * st = malloc(sizeof(struct A));
    st->num = i;
    st->buy=false;
    st->reservations=false;
   // seat_print(st);
    return st;
}

BUYER * person_new(char * name_person)
{
    BUYER *chv=malloc(sizeof(struct B));
    chv->name=name_person;
    chv->count=0;
    return chv;
}

void seat_free(SEAT *st){
    free(st);
}
void person_free(BUYER *pr){
    free(pr);
}

void buyer_seat_reservation(SEAT * holl, int seat, BUYER * person){
    holl=holl+seat-1;
    if (seat > 0 && seat < QUANTITY_SEAT){
        if(holl->buy == false && holl->reservations == false){
            holl->reservations = true;
            person->my_seat[person->count]=*(holl);
            person->count++;
        }
        else{ printf("\nThe seat is engaged\n ");exit(0);}
        
        
    }
    else{ printf("\nThe seat not found");exit(0);}
}


void buyer_seat_buy(SEAT * holl, int seat, char * name, BUYER * person){
    holl=holl+seat-1;
    if (seat > 0 && seat < QUANTITY_SEAT){
        if(holl->buy == false && holl->reservations == false){
            holl->buy = true;
            person->my_seat[person->count]=*(holl);
            person->count++;
        }
        else{ printf("\nThe seat is engaged\n ");exit(0);}
        
        
    }
    else{ printf("\nThe seat not found");exit(0);}
}


int buyer_seat_print(BUYER * person, char name[MAX_SIZE_OF_NAME]){
    for (int i=0; i<QUANTITY_SEAT; i++) {
        if (strcmp(name, &person->name[i]) == 0){
            printf("Name: %c\n", person->name[i]);
            seat_print(person->my_seat);
        }
    }
    return 1;
}

int seat_print (SEAT * seat){
    if(seat==NULL)
    {
        puts("seat not found");
        return 0;
    }
    int m = seat->num;
    printf("%i: ",m);
    if ( seat->buy==true )
        printf("Bought\n");
    else
    if ( seat->reservations ==true )
        printf("Reservation\n");
    else printf("Empty\n");
    return 1;
        
    
}
