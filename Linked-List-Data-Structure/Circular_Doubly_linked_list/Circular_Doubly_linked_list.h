/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

typedef struct node{
    int data;
    struct node *next, *prev;
}node;

typedef node* CDLL;

void init(CDLL *l);

void append(CDLL *l, int d);

int pop(CDLL *l);

void traverse(CDLL l);

void insert_At(CDLL *l, int i, int d);

void Remove_At(CDLL *l, int pos);

int len(CDLL l);

void destroy(CDLL *l);

void insert_At(CDLL *l, int posn, int num);

int search(CDLL l, int num);

void Remove(CDLL *l, int num);

void pop_last(CDLL *l);

void pop_first(CDLL *l);

void reverse(CDLL *l);

void sort(CDLL *l);
