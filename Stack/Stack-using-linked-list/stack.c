/*
*     Author : Tushar Chakradhar Pathade    
*     Follow : pathadeTush @https://github.com/pathadeTush
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "stack.h"

void init(stack *s){
    *s = NULL;
    return;
}

int isEmpty(stack s){
    if(s == NULL)
        return 1;
    else
        return 0;
}

void push(stack *s, int d){
    node *nn = NULL;
    nn = (node *)malloc(sizeof(node));
    if(nn){
        nn->data = d;
        nn->next = NULL;
    }
    else return;
    if(isEmpty(*s)){
        *s = nn;
        return;
    }
    nn->next = *s;
    *s = nn;
    return;
}

/* ---- pop ------ */
void pop(stack *s){
    if(*s == NULL) return;
    node *p = *s;
    int k = p->data;
    *s = p->next;
    free(p);
    printf("popped element = %d\n", k);
}


/* -------- traverse -------- */
void traverse(stack s){    // here s is used for pointing to the nodes (like head pointer)
    printf("[ ");
    node *p;
    p = s;  // here p will store the value of pointer l that is it will point to what l is pointing to.
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("] \n");
    return;
}



/* ------- len -------- */
int len(stack s){
    int length = 0;
    node *p;
    p = s;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

