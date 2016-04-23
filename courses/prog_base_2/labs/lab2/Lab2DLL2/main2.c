
#include "main2.h"
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

void addElem_Rand(STACK *stack){
    int N;
    N = arc4random_uniform(10)+1;
    char *str= (char*)malloc(sizeof(char)*(N+1));
    for (int i=0; i<N; i++)
        str[i]= arc4random_uniform(26) + 97;
    str[N]='\0';
    stack_push(stack, str);
    
}


void removeElems_Rand(STACK *stack){
    int count;
    char *str=stack_pop(stack);
    count = strlen(str);
        for(int i=0; i<count-1; i++)
            stack_pop(stack);
    
}
