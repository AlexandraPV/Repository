#include "student.h"
#include <stdlib.h>
#include <strings.h>
#define QUANTITY_STUDENTS 10
#define MAX_SIZE_OF_NAME 20

struct student_s {
    char name[MAX_SIZE_OF_NAME]; 
    float ball;	
};
struct list_s {
    struct student_s * student;
    int size;
};

list_t * list_creat (int size){
    
    list_t * std = malloc(sizeof(list_t));
    std->student = malloc(size * sizeof(student_t));
    std->size = 0;
    return std;
}


enum RESULTS list_add_elem(list_t * self,char last_name[MAX_SIZE_OF_NAME], int index, float average_score){
    if (index <= self->size && index >= 0){
        for (int i = self->size - 1; i >= index; i--){
            self->student[i+1] = self->student[i];
        }
        strcpy(self->student[index].name, last_name);
        self->student[index].ball = average_score;
        self->size++;
        return SUCCESS;
    }
    else return NO_INDEX;
    
}

enum RESULTS list_delete_elem(list_t * self, int index){
    if (index < self->size && index >= 0){
        for (int i = index ; i < self->size; i++){
            self->student[i] = self->student[i + 1];
         }
        self->size--;
        return SUCCESS;
    }else return NO_INDEX;
}


int list_size(list_t * self){
    return self->size;
}

int list_student_max_mark(list_t * self ){
    float max=0;
    for(int i=0; i < self->size; i++){
        if( self->student[i].ball > max){
            max = self->student[i].ball;
        }
    }
    return max;
}


void list_student_name(list_t * self, char name[MAX_SIZE_OF_NAME]){
    for (int i=0; i<self->size; i++) {
        if (strcmp(name, self->student[i].name) == 0){
            printf("Surname: %s\n", self->student[i].name);
            printf("Score: %.2f\n", self->student[i].ball);
        }
    }
}


void list_print(list_t * self){
    for (int i = 0; i < self->size; i++)
        printf("%s %.2f\n", self->student[i].name, self->student[i].ball);
}

void list_remove(list_t ** std){
    free((*std)->student);
    free(*std);
    *std = NULL;
}
