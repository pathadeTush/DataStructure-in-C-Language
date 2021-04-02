/*
*     Author : Tushar Chakradhar Pathade    
*     Follow : pathadeTush @https://github.com/pathadeTush
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef node* list;  // here list is a data type (which is used for creating pointer to the node)

/*  list *p ; here p is pointer of data type list or pointer of data type node pointer. It is used to create pointer to the nodes.(like head pointers)
    node *q;  here q is pointer of data type node and not node pointer. It is used to create new node.

*/


/* ------- init --------- */
void init(list *l){
   *l = NULL;
    return;
}


/* ------- append --------- */
void append(list *l, int d){
    node *newnode, *counter = NULL;
    newnode = (node *)malloc(sizeof(node));

    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else
        return;
    if(*l == NULL){     //.Note : l is pointer to the L1 i.e, pointer to the head pointer.
                        // So *l will give the value stored by the pointer L1 i.e, address of first node.
        *l = newnode;
        return;
    }
    counter = *l;   // assigning address of node to which pointer L1 is pointing.
    while(counter->next){
        counter = counter->next;
    };
    counter->next = newnode;
    return;
    // after return newnode variable get destroyed as it is local. But the memory allocated by malloc function will never get destroyed. it remains fixed.
    // If we haven't used it then we have to dellocate it manually using function free(). Here these memory is used for next node of linked list.
}

/* -------- traverse -------- */
void traverse(list l){    // here l is used for pointing to the nodes (like head pointer)
    printf("[ ");
    node *p;
    p = l;  // here p will store the value of pointer l that is it will point to what l is pointing to.
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("] \n");
    return;
}



/* ------- len -------- */
int len(list l){
    int length = 0;
    node *p;
    p = l;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

/* ------- deleting whole list -------- */

void destroy(list *l){
    node *p = *l;
    *l = NULL;
    node *q = NULL;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    return;
}

/* -------- search ---------- */
int search(list l, int num){
    node *p;
    p = l;
    while(p){
        if(p->data == num)
            return 1;
        p = p->next;
    }
    return 0;
}

/* ------- Remove --------- */    /* remove is keyword */
void Remove(list *l, int num){
    node *p, *q = NULL;
    p = *l;
    while(p){
     if(q && p->data == num){
        q->next = p->next;
        free(p);
        return;
     }
     else if(p->data == num){
        *l = p->next;
        free(p);
        return;
     }
     q = p;
     p = p->next;
    }
    return;
}


/* ------- pop_last --------- */
void pop_last(list *l){
    if(*l == NULL) return;
    node *p, *q = NULL;
    p = *l;
    while(p->next){
        q = p;
        p = p->next;
    }
    if(q){
        printf("last element : %d\n", p->data);
        free(p);
        q->next = NULL;
        return;
    }
    else{
        printf("last element : %d\n", p->data);
        free(p);
        *l = NULL;
        return;
    }
}


/* ---------- isert_At --------- */
void insert_At(list *l, int posn, int num){
    int length = len(*l), i = 1;

    if(*l == NULL ||  posn > length){
        append(l, num);
        return;
    }
    node *p, *q = NULL, *newnode;
    newnode = (node *)malloc(sizeof(node));
    if(newnode){
        newnode->data = num;
        newnode->next = NULL;
    }
    else return;
    p = *l;
    while(1){
        if(posn == i && q){
            q->next = newnode;
            newnode->next = p;
            return;
        }
        else if(posn == i){
            newnode->next = p;
            *l = newnode;
            return;
        }
        q = p;
        i++;
        p = p->next;
    }
}


/* -------- sort ---------- */
void sort(list *l){
    if(!*l || !(*l)->next)
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
    }
    return;
}


/* -------- Union ---------- */
void Union(list l1, list l2){
    list L3;
    node *p, *q;
    p = l1;
    q = l2;
    while(p){
        append(&L3, p->data);
        p = p->next;
    }
    while(q){
        if(!search(l1, q->data))
            append(&L3, q->data);
        q = q->next;
    }
    printf("union of list1 and list2 : ");
    traverse(L3);
    return;
}



int main(){
    list L1, L2;  // here L1 and L2 are pointers created for pointing to the nodes of linked list(like head pointer).
    init(&L1);    // before using pointers L1 and L2 they are intialized to NULL else it will cause seg fault.
    init(&L2);
      // we are using '&' symbol to assign the address of nodes(1st node) to which these pointers are pointing.
    append(&L1, 1);
   // pop(&L1);
    append(&L1, 2);
    append(&L1, 3);
    append(&L1, 4);
    append(&L1, 5);
    traverse(L1);

  //  destroy(&L1);
  //  printf("-> List L1   Length = %d\n", traverse(L1));

    append(&L2, 8);
    append(&L2, 400);
    append(&L2, 1);
    append(&L2, 11);
    append(&L2, 10);
    sort(&L2);
    traverse(L2);

    //printf("%s\n",search(L1, 4)?"found":"not found");
   // Remove(&L1, 1);
    //pop_last(&L1);

   // printf("length of L1 = %d\n", len(L1));
    insert_At(&L1, 1, 8);
  //  printf("-> List L1   Length = %d\n", traverse(L1));



     traverse(L1);
   // destroy(&L2);
   //printf("-> List L2   Length = %d\n", traverse(L2));

  // Union(L1, L2);
   //printf("%s\n",search(L1, 4)?"found":"not found");

    return 0;
}
