#include "main1.h"
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

void addElem(STACK *stack){
    printf("Enter string ");
    char *str=(char*)malloc(sizeof(char)*(100));;
    scanf("%s", str);
    stack_push(stack, str);
    
}

void removeElems(STACK *stack){
    printf("Enter count of delete elements ");
    int count;
    scanf("%d",&count);
    if (count<1 || count>11)
        printf ("Wrong count");
    else{
        for(int i=0; i<count; i++)
        stack_pop(stack);
    }
}
