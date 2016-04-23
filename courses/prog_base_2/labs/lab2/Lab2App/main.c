#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"
#include "main1.h"
#include "main2.h"

int choose_library();
int choose_function();
int prog (STACK * stack);

int main(){
    STACK * stack = stack_new();
    
    while (1) {
        int result = prog(stack);
        if (result==0){
            return 0;
        }
    }
    
}

int choose_library(){
    int N;
    printf("Enter library ");
    scanf("%d", &N);
    if (N==1 || N==2){
        return N;
    }
    else {
        printf("Wrong library ");
        return 0;
    }
}


int choose_function(){
    int N;
    printf("Enter function ( 1 - add, 2 - delete, 5 - print stack) ");
    scanf("%d", &N);
    if (N==1 || N==2 || N==99 || N==5){
        return N;
    }
    else {
        printf("Wrong function");
        return 0;
    }

}


int prog (STACK * stack){
    
    int lib_num = choose_library();
    if (lib_num == 0)
        return 0;
    
    int func_num = choose_function();
    if (func_num == 0)
        return 0;
    
    if (func_num == 99)
        return 0;
    
    if ( lib_num == 1){
        if (func_num == 1 )
            addElem(stack);
        else removeElems(stack);
    }
    if (func_num==5){
        stack_print(stack);
    }
    
    if ( lib_num == 2){
        if (func_num == 1 )
            addElem_Rand(stack);
        else removeElems_Rand(stack);
    }
    return 1;
}
