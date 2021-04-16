/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "list.h"

void init(list *l) {
    *l = NULL;
    return;
}

int isempty(list l){
    if(l == NULL)
        return 1;
    else
        return 0;
 }

void append(list *l, int d){
    node *p, *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    if(*l == NULL){
        *l = newnode;
        return;
    }
    p = *l;
    while(p -> next) {
       p = p->next;
    }
    p->next = newnode;
    return;
}

int length(list l){
    int len = 0;
    node* p  = l;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void destroy(list *l){
    node *p = *l, *q = NULL;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    *l = NULL;
    return ;
}
void traverse(list l){
    printf("[");
    node *p;
    p = l;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}

int search(list l, int d) {
    node *p ;
    p = l;

    while(p) {
        if(p->data == d)
            return 1;
        p = p->next;
    }
    return 0;
}

void Remove(list *l, int d){
    node *p = *l, *q = *l;
    while(p){
        if(p->data == d){
            if(p == q){
                p = p->next;
                *l = p;
                free(q);
                return;
            }
            q->next = p->next;
            free(p);
            return;
        }
        q = p;
        p = p->next;
    }
    return;
}

/*
void Remove(list *l , int d){
    node *p = *l, *q;
    while(p && p->data != d){
        q = p;
        p = p->next;
    }
    if(p && *l == p){        // 1st node gets deleted
        *l = p->next;
        free(p);
        return;
    }
    if(p){
        q->next = p->next;
        free(p);
        return;
    }
}
*/
int peek(list *l){ //removes and returns first element
    node *p = *l;
    if(!p)
        return INT_MAX;
    int k = p->data;
    *l = p->next;
    free(p);
    return k;
}

//removes and returns last element
int pop(list *l){
    int k = INT_MIN;
    node *p = *l, *q = NULL;
    while(p){
        if(p->next == NULL){
            k = p->data;
            if(q == NULL)
                *l = p->next;
            else
                q->next = NULL;
            free(p);
            return k;
        }
        q = p;
        p = p->next;
    }
    return k;
}

void insert_beg(list *l, int d){
    node  *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    newnode->next = *l;
    *l = newnode;
    return;
}

void reverse(list *l){
    list n = NULL;
    while(*l)
        append(&n, pop(l));
    *l = n;
    return;
}



void insert_at(list *l, int i, int d){
    node  *newnode = NULL;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;

    if( i == 0){
        insert_beg(l,d);
        return;
    }

    int s = length(*l);
    if(i >= s){
        append(l,d);
        return;
    }
    node *p = *l;
    int j = 0;
    while(j < i-1) {
        p = p->next;
        j++;
    }
    newnode->next = p->next;
    p->next = newnode;
    return;
}


void sort(list *l){
    if(*l == NULL || (*l)->next == NULL)
        return;
    int temp;
    node *p = *l, *q = NULL;
    while(p){
        while(p != *l){
            if(p->data < q->data){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            if(q->next == p)
                break;
            q = q->next;
        }
        q = *l;
        p = p->next;
    }
}
/*
list Union(list L1, list L2){

}
*/

