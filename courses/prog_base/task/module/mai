#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "student.h"

int main(){
    list_t * group = list_creat();
    add_elem(group, "Ivanov", 0, 4);
    add_elem(group, "Petrov", 1, 3.5);
    add_elem(group, "Antonov", 2, 5);
    add_elem(group, "Svistunov", 3, 3);
    add_elem(group, "Zhuravel", 4, 4.3);
    add_elem(group, "Shannon", 5, 4.7);
    
    delete_elem(group, 3);
    assert(student_max_mark(group) == 5);
    
    char fam ="Ivanov";
    student_name(group, fam);
    print_list(group);
}
