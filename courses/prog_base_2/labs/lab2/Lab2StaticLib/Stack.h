#define MAX_COUNT_ELEM 10
#define MAX_SIZE_LINE 10

typedef struct stack_s STACK ;

STACK *stack_new(void);
void stack_delete(STACK * self);

void stack_push(STACK * self, char * element);
char *stack_pop(STACK * self);
char *stack_top(STACK * self);
void stack_print(const STACK * self);
int stack_getSize(const STACK * self);
