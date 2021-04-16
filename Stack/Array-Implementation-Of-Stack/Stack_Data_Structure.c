/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/* This is the implementation of stack data structure using array */

typedef struct stack{
    int *a;
    int size;
    int top;
}stack;


/* -------- init --------- */
void init(stack *s, int len){
    s->a = (int *)malloc(sizeof(int)*len);
    s->size = len;
    s->top = -1;
}


/* -------- isEmpty -------- */
int isEmpty(stack s){
    if(s.top == -1)
        return 1;
    else
        return 0;
}


/* -------- isFull ----------- */
int isFull(stack s){
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}


/* ------- push ---------- */
void push(stack *s, int d){
    if(isFull(*s)){
        printf("Stack is full\n");
        return ;
    }
    else {
        s->top++;
        s->a[s->top] = d;
        return;
    }
}

/* -------- Traverse ---------- */
void traverse(stack s){
    int i = 0;
    printf("[ ");
    while(s.top != -1 && i <= s.top){
        printf("%d ", s.a[s.top - i]);
        i++;
    }
    printf("] \n");
    return;
}

/* ---------- pop ----------- */
void pop(stack *s){
    if(isEmpty(*s))
        return;
    printf("%d is popped out from stack\n", s->a[s->top]);
    s->top--;
    return;
}


/* ---------- peek ---------- */ //Function to display the top from stack without removing it
void peek(stack s){
    if(isEmpty(s))
        return;
    printf("%d is on the top of the stack\n", s.a[s.top]);
    return;
}

/* --------- sort ----------- */
void sort(stack *s){
    if(isEmpty(*s) || s->top == 0)
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


/* ---------- main ---------- */
int main(){
    stack s1;
    init(&s1, 10);
    push(&s1, 1);
    push(&s1, 0);
    push(&s1, 0);
    push(&s1, 3);
    push(&s1, 15);
    traverse(s1);
    //peek(s1);
    pop(&s1);
    pop(&s1);
   // sort(&s1);
    traverse(s1);

    return 0;
}
