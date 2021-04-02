/*
*     Author : Tushar Chakradhar Pathade    
*     Follow : pathadeTush @https://github.com/pathadeTush
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "queue.h"


void init(queue *q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(queue q){
    if(q.count == 0)
        return 1;
    return 0;
}

void enqueue(queue *q, int d){
    node *nn = NULL;
    nn = (node *)malloc(sizeof(node));
    if(nn){
        nn->data = d;
        nn->next = NULL;
    }
    else return;
    if(isEmpty(*q)){
        q->front = nn;
        q->rear = nn;
    }
    else{
        q->rear->next = nn;
        q->rear = nn;
    }
    q->count++;
    return;
}


void dequeue(queue *q){
    if(isEmpty(*q))
        return;
    q->count--;
    node *p = NULL;
    p = q->front;
    printf("dequeued element = %d\n", p->data);
    q->front = p->next;
    free(p);
}



void traverse(queue q){
    printf("[ ");
    node *p = q.front;
    while(q.front){
        printf("%d ", p->data);
        if(p == q.rear)
            break;
        p = p->next;
    }
    printf("]\n");
    return;
}
