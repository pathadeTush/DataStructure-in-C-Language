/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

typedef struct node{
    int data;
    struct node *next;
}node;

typedef node* stack;

void init(stack *s);

int isEmpty(stack s);

void push(stack *s, int d);

void traverse(stack s);

int len(stack s);

void pop(stack *s);
