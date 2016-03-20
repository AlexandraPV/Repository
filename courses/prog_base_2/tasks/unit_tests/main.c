#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "list.h"

static void list_add_elem__newElementAnd_index__successOrNoindexResult(void **stus){
    list_t * group1 = list_creat(8);
    assert_int_equal(list_add_elem(group1, "Ivanov", 0, 4),SUCCESS);
    assert_int_equal(list_add_elem(group1, "Petrov", 10, 3.5),NO_INDEX);
    assert_int_equal(list_remove(group1),SUCCESS);
    list_remove(group1);
    
}

static void list_delete_elem__newElementAnd_index__successOrNoindexResult(void **stus){
    list_t * group2 = list_creat(8);
    assert_int_equal(list_delete_elem(group2, 9),NO_INDEX);
    assert_int_equal(list_delete_elem(group2, 0),SUCCESS);
    list_remove(group2);
}

static void list_max_mark__StudentStruct__max_marc(void **stus){
    list_t * std = list_creat();
    list_add_elem(std, "Zhuravel", 0, 4.3);
    list_add_elem(std, "Shannon", 1, 4.7);
    list_add_elem(std, "Antonov", 2, 5);
    assert_int_equal(student_max_mark(std),5);
    list_add_elem(std, "Ivanov", 3, 5);
    assert_int_equal(student_max_mark(std),5);
    list_remove(std);
}
static void list_size__ListStudent__size(void **stus){
    list_t * std = list_creat();
    assert_int_equal(list_size(std),0);
    list_add_elem(std, "Zhuravel", 0, 4.3);
    list_add_elem(std, "Shannon", 1, 4.7);
    list_add_elem(std, "Antonov", 2, 5);
    assert_int_equal(list_size(std),3);
    list_add_elem(std, "Ivanov", 3, 5);
    list_remove(std);
}
static void list_student_name__StudentStructAnd_name__success(void **stus){
    list_t * std = list_creat();
    list_add_elem(std, "Zhuravel", 0, 4.3);
    list_add_elem(std, "Shannon", 1, 4.7);
    list_add_elem(std, "Antonov", 2, 5);
    assert_int_equal(list_student_name(std, "Antonov"),1);
    assert_int_equal(list_student_name(std, "Petrov"),0);
    list_remove(std);
}

int main(void) {
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(list_add_elem__newElementAnd_index__successOrNoindexResult),
        cmocka_unit_test(list_delete_elem__newElementAnd_index__successOrNoindexResult),
        cmocka_unit_test(list_max_mark__StudentStruct__max_marc),
        cmocka_unit_test(list_size__ListStudent__size),
        cmocka_unit_test(list_student_name__StudentStructAnd_name__success),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
