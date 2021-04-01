#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include "Circular_Doubly_linked_list.h"


void init( CDLL *l){
    *l = NULL;
    return;
}


void append(CDLL *l, int d){
    node* nn = (node *)malloc(sizeof(node));
    if(nn){
        nn->data = d;
        nn->next = nn;
        nn->prev = nn;
    }
    else
        return;
    if(*l == NULL){
        *l = nn;
        return;
    }
    node *last = NULL;
    last = (*l)->prev;
    last->next = nn;
    nn->prev = last;
    nn->next = *l;
    (*l)->prev = nn;
    return;
}

void traverse(CDLL l){
    printf("[ ");
    node *p;
    p = l;
    while(p){
        printf("%d ", p->data);
        p = p->next;
        if(p == l)
            break;
    }
    printf("]\n");
    return;
}

// returns first element
int pop(CDLL *l){
    int ele = INT_MIN;
    if(*l == NULL)
        return ele;
    node *p = NULL;
    p = *l;
    ele = p->data;
    if(p->prev == p)
        *l = NULL;
    else{
        p->prev->next = p->next;
        p->next->prev = p->prev;
        *l = p->next;
    }
    free(p);
    return ele;
}


/* ------- len -------- */
int len(CDLL l){
    int length = 0;
    node *p;
    p = l;
    while(p){
        length++;
        if(p->next == l)
            break;
        p = p->next;
    }
    return length;
}



/* ---------- isert_At --------- */
void insert_At(CDLL *l, int posn, int num){
    int length = len(*l), i = 0;
    if(*l == NULL ||  posn >= length){
        append(l, num);
        return;
    }
    node *p = NULL, *newnode;
    newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode->data = num;
        newnode->prev = newnode;
        newnode->next = newnode;
    }
    else return;
    p = *l;
    while(1){
        if(i == posn && p == *l){  // First node
            *l = newnode;
            newnode->next = p;
            newnode->prev = p->prev;
            p->prev->next = newnode;
            p->prev = newnode;
            return;
        }
        else if(i == posn){  // intermediate node
            newnode->prev = p->prev;
            newnode->next = p;
            p->prev->next = newnode;
            p->prev = newnode;
            return;
        }
        i++;
        p = p->next;
    }
}


/* -------- search ---------- */
int search(CDLL l, int num){
    node *p;
    p = l;
    while(p){
        if(p->data == num)
            return 1;
        if(p->next == l)
            break;
        p = p->next;
    }
    return 0;
}


/* ------- Remove --------- */    /* remove is keyword */
void Remove(CDLL *l, int num){
    node *p;
    p = *l;
    while(p){
     if(p->prev == p && p->data == num){  // only one node
        free(p);
        *l = NULL;
        return;
     }
     else if(p->data == num){
        if(p == *l)
            *l = p->next;
        p->next->prev = p->prev;
        p->prev->next = p->next;
        free(p);
        return;
     }
     if(p->next == *l)
        break;
     p = p->next;
    }
    return;
}


/* ------- Remove_At --------- */    /* remove is keyword */
void Remove_At(CDLL *l, int pos){
    node *p;
    p = *l;
    int i = 1;
    while(p){
        if(p->prev == p && i == pos){  // only one node
            free(p);
            *l = NULL;
            return;
        }
        else if(i == pos){
            if(p == *l)
                *l = p->next;
            p->next->prev = p->prev;
            p->prev->next = p->next;
            free(p);
            return;
        }
        if(p->next == *l)
            break;
        p = p->next;
        i++;
    }
    return;
}



/* ------- pop_last --------- */
void pop_last(CDLL *l){
    if(*l == NULL) return;
    node *p = *l;
    if(p->prev == p){
        *l = NULL;
        free(p);
        return;
    }
    node *last = p->prev;
    p->prev = last->prev;
    last->prev->next = p;
    free(last);
    return;
}


/* ------- pop_first --------- */
void pop_first(CDLL *l){
    if(*l == NULL) return;
    node *p = *l;
    if(p->prev == p){
        *l = NULL;
        free(p);
        return;
    }
    p->next->prev = p->prev;
    p->prev->next = p->next;
    *l = p->next;
    free(p);
    return;
}

/* -------- reverse -------- */
void reverse(CDLL *l){    // here l is used for pointing to the nodes (like head pointer)
    node *p = *l, *first;
    first = p;
    *l = NULL;
    while(p){
        p = p->prev;
        append(l, p->data);
        if(p == first)
            break;
    }
    return;
}


/* ------- deleting whole list (not done) -------- */
void destroy(CDLL *l){
    node *p = *l;
    *l = NULL;
    while(p){
        if(p->prev == p)
            break;
        node *q = p;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p = p->next;
        free(q);
    }
    free(p);
    return;
}


/* ------- sort ---------- */
void sort(CDLL *l){
    if(!*l || !(*l)->next)    // for sorting use extra pointer q
        return;
    node *p, *q = NULL;
    int temp;
    p = *l;
    while(p){
        while(p != *l){
            if(p->data < q->data){
                temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
            if(q->next == p)
                break;
            q = q->next;
        }
        q = *l;
        p = p->next;
        if(p == *l) break;
    }
    return;
}
