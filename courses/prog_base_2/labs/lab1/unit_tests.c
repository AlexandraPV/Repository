#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "Seat.h"
#include "Buyer.h"


static void seat_print__seat__0OR1(void **stus){
    SEAT * seat[10];
    seat[4] = NULL;
    assert_int_equal(seat_print (seat[4]),0);
    for(int i=1;i<11;i++)
        seat[i]=seat_new(i);
    assert_int_equal(seat_print (seat[1]),1);
    seat_free(seat);
}

static void seat_return__seat__0OR1(void **stus){
    SEAT * seat[10];
    assert_int_equal(seat_return(NULL),NULL);
    for(int i=1;i<11;i++){
        seat[i]=seat_new(i);}
    assert_int_equal(seat_return (seat[3]),3);
    seat_free(seat);
}

static void seat_status__seat__trueORfalse(void **stus){
    SEAT * seat[10];
    BUYER * person[1];
    for(int i=1;i<11;i++)
        seat[i]=seat_new(i);
    
    person[0]=person_new("Ivanov");
    
    assert_int_equal(seat_status(seat[3]),true);
    buyer_seat_reservation(seat, 2, person[0]);
    assert_int_equal(seat_status(NULL),false);
    buyer_seat_buy(seat, 6, "Petrov", person[0]);
    assert_int_equal(seat_status(NULL),false);
    assert_int_equal(seat_status(seat[4]),true);
    person_free(person[0]);
    seat_free(seat);
}

static void seat_unReservation__seat__trueORfalse(void **stus){
    SEAT * seat[10];
    assert_int_equal(seat_unReservation(NULL),false);
    for(int i=0;i<10;i++)
        seat[i]=seat_new(i);
    assert_int_equal(seat_unReservation(seat[5]),true);
    for(int i=0;i<10;i++)
        seat_free(seat[i]);
}

/*static void seat_unBuy__seat__trueORfalse(void **stus){
    SEAT * seat[10];
    seat[7] = NULL;
    assert_int_equal(seat_unBuy(seat[7]),false);
    
    for(int i=0;i<10;i++)
        seat[i]=seat_new(i);
    
    //assert_int_equal(seat_unBuy(seat[7]),true);
    
    for(int i=0;i<10;i++)
        seat_free(seat[i]);
}*/

static void buyer_seat_reservation__hollANDseatnumberANDperson__trueORfalse(void **stus){
    SEAT * seat[10];
    BUYER * person[5];
    for(int i=0;i<10;i++)
        seat[i]=seat_new(i);
    
    person[5]=person_new("Ivanov");
    assert_int_equal(buyer_seat_reservation(seat, 3, person[5]),true);
    buyer_seat_reservation(seat, 4, person[5]);
    assert_int_equal(buyer_seat_reservation(seat, 4, person[5]),false);
    buyer_seat_buy(seat, 6, "Ivanov", person[5]);
    assert_int_equal(buyer_seat_reservation(seat, 6, person[5]),false);
    assert_int_equal(buyer_seat_reservation(seat, 30, person[5]),false);
    person_free(person[5]);
    for(int i=0;i<10;i++)
        seat_free(seat[i]);
}

static void buyer_seat_buy__hollANDseatnumberANDpersonnameANDperson__trueORfalse(void **stus){
    SEAT * seat[10];
    BUYER * person[1];
    for(int i=1;i<11;i++)
        seat[i]=seat_new(i);
    
    person[0]=person_new("Ivanov");
    assert_int_equal(buyer_seat_buy(seat, 3, "Ivanov",person[0]),true);
    buyer_seat_reservation(seat, 4, person[0]);
    assert_int_equal(buyer_seat_buy(NULL, 4, "Ivanov",person[0]),false);
    buyer_seat_buy(seat, 6, "Ivanov", person[0]);
    assert_int_equal(buyer_seat_buy(seat, 6, "Ivanov", NULL),false);
    assert_int_equal(buyer_seat_buy(seat, 30, "Ivanov",person[0]),false);
    person_free(person[0]);
    seat_free(seat);
}

static void buyer_seat_print__person__0OR1(void **stus){
    SEAT * seat[10];
    BUYER * person[1];
    assert_int_equal(seat_print (NULL),0);
    for(int i=1;i<11;i++)
        seat[i]=seat_new(i);
    person[0]=person_new("Ivanov");
    assert_int_equal(buyer_seat_print(person[0]),1);
    seat_free(seat);
    person_free(person[0]);
}


int main(void) {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(seat_print__seat__0OR1),
        cmocka_unit_test(seat_return__seat__0OR1),
        cmocka_unit_test(seat_status__seat__trueORfalse),
        cmocka_unit_test(seat_unReservation__seat__trueORfalse),
        //cmocka_unit_test(seat_unBuy__seat__trueORfalse),
        cmocka_unit_test(buyer_seat_reservation__hollANDseatnumberANDperson__trueORfalse),
        cmocka_unit_test(buyer_seat_buy__hollANDseatnumberANDpersonnameANDperson__trueORfalse),
        cmocka_unit_test(buyer_seat_print__person__0OR1)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
