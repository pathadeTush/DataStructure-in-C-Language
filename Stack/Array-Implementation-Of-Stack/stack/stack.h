/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

typedef struct stack
{
    int *a;
    int size;
    int top;
} stack;

void init(stack *s, int len);
void push(stack *s, int d);
int isFull(stack s);
int isEmpty(stack s);
int pop(stack *s);
