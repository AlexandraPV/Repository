#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dlfcn.h>
#include "Stack.h"
#include "main1.h"
#include "main2.h"

int choose_library();
int choose_function();
int prog (STACK * stack, void* lib_handle1, void* lib_handle2);

int main(){
    void* lib_handle1 = dlopen("/Users/Alisandra/Desktop/Lab_2_2/Lab_2_2/libLab2DLL1.dylib", RTLD_LOCAL|RTLD_LAZY);
    void* lib_handle2 = dlopen("/Users/Alisandra/Desktop/Lab_2_2/Lab_2_2/libLab2DLL2.dylib", RTLD_LOCAL|RTLD_LAZY);
    
    STACK * stack = stack_new();
    
    while (1) {
        int result = prog(stack, lib_handle1, lib_handle2);
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


int prog (STACK * stack, void* lib_handle1, void* lib_handle2 ){
    
    int lib_num = choose_library();
    if (lib_num == 0)
        return 0;
    
    int func_num = choose_function();
    if (func_num == 0)
        return 0;
    
    if (func_num == 99)
        return 0;
    
    if ( lib_num == 1){
        if (func_num == 1 ){
            void (*addElem)(STACK*) = dlsym(lib_handle1, "addElem");
            addElem(stack);
        }
        else if (func_num==5){
            stack_print(stack);
        }
        else {
            void (*removeElems)(STACK*) = dlsym(lib_handle1, "removeElems");
            removeElems(stack);
        }
    }
    
    if ( lib_num == 2){
        if (func_num == 1 ){
            void (*addElem_Rand)(STACK*) = dlsym(lib_handle2, "addElem_Rand");
            addElem_Rand(stack);
        }
        else if (func_num==5){
            stack_print(stack);
        }
        else {
            void (*removeElems_Rand)(STACK*) = dlsym(lib_handle2, "removeElems_Rand");
            removeElems_Rand(stack);
        }
    }
    return 1;
}
