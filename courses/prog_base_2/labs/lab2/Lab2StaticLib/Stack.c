#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "Stack.h"


struct stack_s
{
    char data[MAX_COUNT_ELEM][MAX_SIZE_LINE];
    int size;
};

STACK *stack_new(void)
{
    STACK *stack = (STACK *)malloc(sizeof(struct stack_s));
    stack->size = 0;
    for(int i = 0; i < MAX_COUNT_ELEM; i++)
    {
        stack->data[i][0] = '\0';
    }
    return (stack);
}

void stack_delete(STACK * stack)
{
    free(stack);
}

void stack_push(STACK * stack, char *str)
{
    if(stack->size == MAX_COUNT_ELEM)
        printf("Stack is full");
    
    strcpy(stack->data[stack->size], str);
    stack->size++;
}

char *stack_pop(STACK * stack)
{
    char *str;
    if(stack->size == 0)
    {
        str = "";
        return (str);
    }
    str = stack->data[stack->size - 1];
    strcpy(stack->data[stack->size - 1], "");
    stack->size--;
    return (str);
}

char *stack_top(STACK * stack)
{
    return (stack->data[stack->size - 1]);
}

void stack_print(const STACK * stack)
{
    if(stack->size <= 0)
    {
        printf("Stack is empty\n");
        return;
    }
    
    else
    {
        for(int i = 0; i < stack->size; i++)
        {
            printf("%s\n", stack->data[i]);
        }
    }
    printf("\n");
}

int stack_getSize(const STACK * stack)
{
    return (stack->size);
}
