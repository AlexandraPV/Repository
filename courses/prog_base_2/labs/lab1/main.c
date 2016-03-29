#include <stdio.h>
#include "Seat.h"
#include "Buyer.h"
#define QUANTITY_SEAT 20
#define MAX_SIZE_OF_NAME 20

int main(){
    BUYER * person[5];
    SEAT * seat[10];
    int i;
   /* for(i=0;i<5;i++)
        person[i]=person_new("abd");*/
    for(i=0;i<10;i++)
        seat[i]=seat_new(i);

    
    for (i=0; i<10; i++)
        seat_print(seat[i]);
    
    
    return 0;
}
