#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "student.h"
#define MAX_SIZE_OF_NAME 20



int main(){
    list_t * group = list_creat(8);
    print_list(group);
    if(SUCCESS == add_elem(group, "Ivanov", 0, 4))
        puts("success");
    if(SUCCESS == add_elem(group, "Petrov", 1, 3.5))
    puts("success");
    if(SUCCESS == add_elem(group, "Antonov", 2, 5))
    puts("success");
    if(SUCCESS == add_elem(group, "Svistunov", 3, 3))
    puts("success");
    if(SUCCESS == add_elem(group, "Zhuravel", 4, 4.3))
    puts("success");
    if(SUCCESS == add_elem(group, "Shannon", 5, 4.7))
    puts("success");
    
    delete_elem(group, 3);
   // assert(student_max_mark(group) == 5);
    printf("Max score: %d/n", student_max_mark(group));
    
    char *fam ="Ivanov";
    student_name(group, fam);
    
    print_list(group);
    list_remove(&group);
    return 0;
}

