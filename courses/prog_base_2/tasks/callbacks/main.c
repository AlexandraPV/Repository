#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 20

typedef int(*CallBack)(int );

void stackProcess(CallBack checkCB, CallBack processCB) {
    int stack[STACK_MAX_SIZE];
    int top=0;
    while (top <STACK_MAX_SIZE){
    int val=rand()%511-225;
        if ( top <= STACK_MAX_SIZE){
            if (checkCB(val)==1){
             stack[top] = val;
              top++;
            }
            else processCB (top);
        } else
           {
            printf ("Stack is full");
               exit(0);
           }
 }
    for (int i=0; i<top; i++)
        printf("%d ", stack[i]);
}

int checkCB(int val){
    if( val>0){
        return 1;
    }
    else return 0;
}

void processCB (int size){
    size--;
}

int main(){
    CallBack check =checkCB;
    CallBack pro = processCB;
    stackProcess(check, pro);
    
    return 0;
}
