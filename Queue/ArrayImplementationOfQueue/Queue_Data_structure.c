/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

#include<stdio.h>
#include<stdlib.h>


/* front is storing the index of first element entered i.e, 0 but front will incremented to 1 if first element is deleted
   rear stores the index of last element entered  rear will incremented if new element is added */

/* ------- Array implementation Of Queue -------- */

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
    if(q.rear == -1)
        return 1;
    return 0;
}


/* -------- isFull --------- */
int isFull(queue q){
    if(q.rear == q.size -1)
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

    q->rear++;
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
    q->front++;
    if(q->front > q->rear){ // queue is empty (front and rear were pointing to same number)
        q->front = -1;
        q->rear = -1;
    }
    return;
}


 /* --------- Traverse ----------- */
 void traverse(queue q){
    printf("[ ");
    while(!isEmpty(q) && q.front-1 != q.rear)
        printf("%d ",q.Q[q.front++]);
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

/* --------- sort -----------
void sort(queue *q){
    if(isEmpty(*q) || q->front == 0)
        return;
    int i = 0, j, temp;
    while(i <= s->top){
        while(i){
            if(s->a[i] < s->a[j]){
                temp = s->a[j];
                s->a[j] = s->a[i];
                s->a[i] = temp;
            }
            if(j+1 == i)
                break;
            j++;
        }
        j = 0;
        i++;
    }
    return;
}
*/


/* -------- main ----------- */
int main(){
    queue q1;
    init(&q1, 10);
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 13);
    first(q1);
    last(q1);
    dequeue(&q1);
    traverse(q1);

    return 0;
}


/*
Complexity Analysis:

Time Complexity:
 Operations              Complexity
 Enque(insertion)           O(1)
 Deque(deletion)            O(1)
 Front(Get front)           O(1)
 Rear(Get Rear)             O(1)

Auxiliary Space: O(N).
 N is the size of array for storing elements.

Pros of Array Implementation:
 Easy to implement.

Cons of Array Implementation:
 Static Data Structure, fixed size.
 If the queue has a large number of enqueue and dequeue operations,
 at some point we may not we able to insert elements in the queue
 even if the queue is empty (this problem is avoided by using circular queue).
 */
