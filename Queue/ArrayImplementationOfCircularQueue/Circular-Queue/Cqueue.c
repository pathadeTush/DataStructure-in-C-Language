/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

#include<stdio.h>
#include<stdlib.h>
#include "Cqueue.h"


/* -------- init --------- */
void init(queue *q, int len){
    q->Q = (int *)malloc(sizeof(int)*len);
    q->front = -1;
    q->rear = -1;
    q->size = len;
    return;
}



/* -------- isEmpty --------- */
int isEmpty(queue q){
    if(q.front == -1)
        return 1;
    return 0;
}


/* -------- isFull --------- */
int isFull(queue q){
    if((q.rear == q.size -1 && q.front == 0) || (q.front == q.rear+1))
        return 1;
    return 0;
}


/* --------- enqueue ---------- */
void enqueue(queue *q, int d){
    if(isFull(*q)){
        printf("Queue is Full!\n");
        return;
    }
    if(isEmpty(*q))
        q->front++;

    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = d;
    return;
}


/* ------------ dequeue ----------- */
void dequeue(queue *q){
    if(isEmpty(*q)){
        printf("Queue is empty!\n");
        return;
    }
    printf("%d was the first element entered is now popped out from an queue!\n", q->Q[q->front]);
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
        return;
    }
    q->front = (q->front + 1) % q->size;
    return;
}


 /* --------- Traverse ----------- */
 void traverse(queue q){
    printf("[ ");
    while(!isEmpty(q) && q.front != q.rear){
        printf("%d ",q.Q[q.front]);
        q.front = (q.front + 1) % q.size;
        if(q.front == q.rear)
            printf("%d ",q.Q[q.front]);
    }
    printf("]\n");
    return;
 }


 /* -------- first ---------- */
 void first(queue q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    printf("%d was the first element entered in an queue!\n", q.Q[q.front]);
    return;
}


/* -------- last ---------- */
 void last(queue q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    printf("%d was the last element entered in an queue!\n", q.Q[q.rear]);
    return;
}



