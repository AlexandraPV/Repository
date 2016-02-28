#ifndef student_h
#define student_h

#include <stdio.h>

typedef struct STUDENT list_t;

enum RESULTS{
    LIST_IS_EMPTY,
    LIST_IS_FULL,
    SUCCESS,
    NO_INDEX,
    EMPTY
};

list_t  *list_creat();

enum RESULTS add_elem(list_t *,char, int, float);    //add element to list
enum RESULTS delete_elem(list_t *,int);     //delete element from list
int size_of_list(list_t *);            // size of list
int student_max_mark(list_t *);        // find the student with the highest average score
int student_name(list_t *, char);            //find the student (use name)
void print_list(list_t * );
enum RESULTS list_free(list_t *);

#endif /* student_h */
