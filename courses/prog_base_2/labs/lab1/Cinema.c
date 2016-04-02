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
    if (i>=0){
        SEAT * st = malloc(sizeof(struct A));
        st->num = i;
        st->buy=false;
        st->reservations=false;
        return st;
    }
    else return NULL;
}

BUYER * person_new(char * name_person)
{
    if (name_person!= NULL){
        BUYER *chv=malloc(sizeof(struct B));
        chv->name=name_person;
        chv->count=0;
        return chv;
    }
    else return NULL;
}

void seat_free(SEAT *st){
    free(st);
}

void person_free(BUYER *pr){
    free(pr);
}

bool buyer_seat_reservation(SEAT * holl, int seat, BUYER * person){
    holl=holl+seat-1;
    if (seat > 0 && seat < QUANTITY_SEAT){
        if(holl->buy == false && holl->reservations == false){
            holl->reservations = true;
            person->my_seat[person->count]=*(holl);
            person->count++;
        }
        else{ printf("\nThe seat is engaged\n ");return false;}

    }
    else{ printf("\nThe seat not found\n");return false;}
    return  true;
}


bool buyer_seat_buy(SEAT * holl, int seat, char * name, BUYER * person){
    holl=holl+seat-1;
    if (holl != NULL && seat > 0 && seat < QUANTITY_SEAT && person != NULL && name != NULL){
        if(holl->buy == false && holl->reservations == false){
            holl->buy = true;
            person->my_seat[person->count]=*(holl);
            person->count++;
        }
        else{ printf("\nThe seat is engaged\n ");return false;}

    }
    else{ printf("\nThe seat not found\n");return false;}
    return true;
}


int buyer_seat_print(BUYER * person){
    if (person!=NULL){
        for(int i=0;i<person->count;i++)
            seat_print(person->my_seat+i);
        return 1;}
    else return 0;
}

int seat_print (SEAT * seat){
    if(seat==NULL)
    {
        puts("seat not found\n");
        return 0;
    }
    int m = seat->num;
    printf("%i: ",m);
    if ( seat->buy==true )
        printf("Bought\n");
    else
        if ( seat->reservations == true )
            printf("Reservation\n");
        else printf( "Empty\n" );
    return 1;

}

int seat_return( SEAT * seat ){
    if (seat !=NULL){
        int st;
        st = seat->num;
        return st;
    } else return NULL;
}

bool seat_status( SEAT * seat ){
    if ( seat !=NULL && (seat->reservations == false || seat->buy == false) ){
        return true;
    }
    else return false;
}

bool seat_unReservation( SEAT * seat ){
    if(seat != NULL) {
        if ( seat->reservations==true){
            seat->reservations = false;
        } else
            printf("This seat isn`t reservated\n");
        return true;
    }
    return false;
}

bool seat_unBuy( SEAT * seat ){
    if (seat != NULL){
        if ( seat->buy==true){
            seat->buy = false;
        } else
            printf("This seat isn`t buy\n");
        return true;
    }
    return false;
}


