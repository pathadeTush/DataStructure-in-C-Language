/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

typedef struct node
{
    int data;
    struct node *next, *prev;
} node;

typedef node *CDLL;

void init(CDLL *l);

void append(CDLL *l, int d);

void traverse(CDLL l);

int search(CDLL l, int num);

int pop_last(CDLL *l);

void pop_first(CDLL *l);

int peek(CDLL l);

int isDigit(int d);

void init_num(CDLL *post, CDLL *l);

void traverse_expr(CDLL l);
