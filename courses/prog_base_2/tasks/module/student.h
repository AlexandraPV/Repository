#ifndef student_h
#define student_h

#include <stdio.h>

typedef struct list_s list_t;
typedef struct student_s student_t;

enum RESULTS{
    LIST_IS_EMPTY,
    LIST_IS_FULL,
    SUCCESS,
    NO_INDEX,
    EMPTY
};

list_t  *list_creat(int size);

enum RESULTS list_add_elem(list_t *,char [], int, float);    //add element to list
enum RESULTS list_delete_elem(list_t *, int);     //delete element from list
int list_size(list_t *);            // size of list
int list_student_max_mark(list_t *);        // find the student with the highest average score
void list_student_name(list_t *, char []);            //find the student (use name)
void list_print(list_t * );
enum RESULTS list_free(list_t *);
void list_remove(list_t ** std);

#endif /* student_h */
