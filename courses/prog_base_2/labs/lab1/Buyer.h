#ifndef Buyer_h
#define Buyer_h
#define QUANTITY_SEAT 20
#define MAX_SIZE_OF_NAME 20

typedef struct B BUYER;
BUYER * person_new(char * name_person);
void person_free(BUYER *pr);
bool buyer_seat_reservation(SEAT * holl, int seat, BUYER * person);
bool buyer_seat_buy(SEAT * holl, int seat, char * name, BUYER * person);
int buyer_seat_print(BUYER * person);


#endif /* Buyer_h */
