#include "student.h"
#include <stdlib.h>
#define QUANTITY_STUDENTS 10
#define MAX_SIZE_OF_NAME 20

struct STUDENT {
    char name[MAX_SIZE_OF_NAME]; 
    int size;
    int * mas;
    float ball;	
};

list_t *list_creat (){
    
    list_t * std = malloc(sizeof(list_t));
    std->mas = malloc(100*sizeof(int));
    std->size = 0;
    return std;
}


 enum RESULTS add_elem(list_t * self,char last_name, int index, float average_score){
    if (index < self->size){
        for (int i = self->size - 1; i >= index; i--){
            self->mas[i+1] = self->mas[i];
        }
        self->name[index] = last_name;
        self->ball=average_score;
        self->size++;
        return SUCCESS;
    }
    else return NO_INDEX;
    
}

enum RESULTS delete_elem(list_t * self, int index){
    if (index < self->size){
        for (int i = index ; i < self->size; i++){
            self->mas[i]=self->mas[i+1];
         }
        return SUCCESS;
    }else return NO_INDEX;
}


int size_of_list(list_t * self){
    int length;
    for(int i=0; i<self->size; i++){
        length++;
    }
    return length;
}

int student_max_mark(list_t * self ){
    float max=0;
    for(int i=0; i<self->size; i++){
        if( self->ball > max){
            max = self->ball;
        }
    }
    return max;
}


int student_name(list_t * self, char name){
    for (int i=0; i<self->size; i++) {
        if (name == self->name){
            printf("Surname: %s", self->name);
            printf("Score: %f", self->ball);
        }
    }
    return 0;
}


void print_list(list_t * self){
    for (int i = 0; i < self->size; i++){
        printf("%d ", self->mas[i]);
    }

}
