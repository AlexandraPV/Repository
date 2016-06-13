//
//  main.c
//  №1
//
//  Created by Alexandra on 13.06.16.
//  Copyright © 2016 Alexandra. All rights reserved.
//



#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "test_1.h"

static void findString_charANDchar_0OR1(void **state)
{
    assert_int_equal(findString("ad", "adhfruhvggcj"), 1);
    assert_int_equal(findString("ad", "adhfr uhvg gcj"), 1);
    assert_int_equal(findString("ad", "gghghghg"), 0);
    assert_int_equal(findString("ad", "adhfruhva\dggcj"), 1);
}


int main(void){
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(findString_charANDchar_0OR1),
        
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
    
    return 0;
}


