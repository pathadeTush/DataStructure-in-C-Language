/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

#include<stdio.h>
#include<stdlib.h>

/* ------- Implementation Of Circular Queue using Array -------- */

typedef struct queue{
    int *Q;
    int front;
    int rear;
    int size;
}queue;


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
    if((q.front == -1 && q.rear == -1)||(q.front == 0 && q.rear == -1))
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
    if(isEmpty(q)){
        printf("[ ]\n");
        return;
    }
    printf("[ ");
    if(q.front == q.rear)
        printf("%d ",q.Q[q.front]);
    while(q.front != q.rear){
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

/* -------- main ----------- */
int main(){
    queue q1;
    init(&q1, 2);
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
   // enqueue(&q1, 4);
    traverse(q1);
    first(q1);
    last(q1);
    dequeue(&q1);
    traverse(q1);
    enqueue(&q1, 5);
  /*  printf("new element 5 is entered in queue \n");
    traverse(q1);
    first(q1);
    last(q1);
*/  traverse(q1);
    return 0;
}

