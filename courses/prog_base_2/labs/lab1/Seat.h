#ifndef Seat_h
#define Seat_h

#include <stdbool.h>
#include <stdio.h>

typedef struct A SEAT;
SEAT * seat_new (int i);
void seat_free(SEAT *st);
int seat_print (SEAT * seat);
int seat_return(SEAT * seat);
bool seat_status(SEAT * seat);
bool seat_unReservation(SEAT * seat);
bool seat_unBuy(SEAT * seat);

#endif /* Seat_h */
