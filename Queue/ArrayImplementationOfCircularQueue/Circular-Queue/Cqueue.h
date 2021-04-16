/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

typedef struct queue{
    int *Q;
    int front;
    int rear;
    int size;
}queue;

void init(queue *q, int len);

int isEmpty(queue q);

int isFull(queue q);

void enqueue(queue *q, int d);

void dequeue(queue *q);

void traverse(queue q);

void first(queue q);

void last(queue q);
