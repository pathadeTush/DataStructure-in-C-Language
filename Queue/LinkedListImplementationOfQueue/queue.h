/*
*     Author : Tushar Chakradhar Pathade    
*     Follow : pathadeTush @https://github.com/pathadeTush
*/

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct queue{
    int count;
    node *front, *rear;
}queue;

void init(queue *q);

int isEmpty(queue q);

void enqueue(queue *q, int d);

void dequeue(queue *q);

void traverse(queue q);
