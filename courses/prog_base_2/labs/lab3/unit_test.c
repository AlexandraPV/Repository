//
//  unit_test.c
//  Lab_2_3
//
//  Created by Alexandra on 21.05.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//
/*
#include <stdio.h>
#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

//#include <cmocka.h>

#include "Header.h"


static void user_subscribe_1__userANDcallbackANDseism__1OR0(void **stus){
    user_t * us=user_new("USER1", 0);
    callb call;
    seismograph_t * seism = seismograph_new();
    assert_int_equal(user_subscribe_1(us, call, seism), 1);
    user_free(us);
    assert_int_equal(user_subscribe_1(us, call, seism), 0);
    seismograph_free(seism);
}

static void user_subscribe_2__userANDcallbackANDseism__1OR0(void **stus){
    user_t * us=user_new("USER2", 0);
    callb call;
    seismograph_t * seism = seismograph_new();
    assert_int_equal(user_subscribe_2(us, call, seism), 1);
    user_free(us);
    assert_int_equal(user_subscribe_2(us, call, seism), 0);
    seismograph_free(seism);
}



static void getCollback1_user_callb(void **stus){
    assert_int_equal(getCollback1(us), NULL );
   //user_t *us = user_new("USER1", 0);
    
}


static void getCollback2_user_callb(void **stus){
    //user_t *us = user_new("USER2", 0);
    assert_int_equal(getCollback2(us), NULL );
}
*/