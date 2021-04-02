/*
*     Author : Tushar Chakradhar Pathade    
*     Follow : pathadeTush @https://github.com/pathadeTush
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

typedef node *Dll;

/* ------- init --------- */
void init(Dll *l)
{
    *l = NULL;
    return;
}

/* ------- append --------- */
void append(Dll *l, int d)
{
    node *newnode, *p = NULL;
    newnode = (node *)malloc(sizeof(node));

    if (newnode)
    {
        newnode->data = d;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else
        return;
    if (*l == NULL)
    { //.Note : l is pointer to the L1 i.e, pointer to the head pointer.
        // So *l will give the value stored by the pointer L1 i.e, address of first node.
        *l = newnode;
        return;
    }
    p = *l; // assigning address of node to which pointer L1 is pointing.
    while (p->next)
        p = p->next;

    p->next = newnode;
    newnode->prev = p;
    return;
    // after return newnode variable get destroyed as it is local. But the memory allocated by malloc function will never get destroyed. it remains fixed.
    // If we haven't used it then we have to dellocate it manually using function free(). Here these memory is used for next node of linked list.
}

/* -------- traverse -------- */
void traverse(Dll l)
{ // here l is used for pointing to the nodes (like head pointer)
    printf("[ ");
    node *p;
    p = l; // here p will store the value of pointer l that is it will point to what l is pointing to.
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("] \n");
    return;
}

/* ------- len -------- */
int len(Dll l)
{
    int length = 0;
    node *p;
    p = l;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

/* ------- deleting whole list -------- */
void destroy(Dll *l)
{
    node *p = *l;
    *l = NULL;
    while (p && p->next)
    {
        p = p->next;
        free(p->prev);
    }
    free(p);
    return;
}

/* -------- search ---------- */
int search(Dll l, int num)
{
    node *p;
    p = l;
    while (p)
    {
        if (p->data == num)
            return 1;
        p = p->next;
    }
    return 0;
}

/* ------- Remove --------- */ /* remove is keyword */
void Remove(Dll *l, int num)
{
    node *p;
    p = *l;
    while (p)
    {
        if (!p->prev && !p->next && p->data == num)
        { // only one node
            free(p);
            *l = NULL;
            return;
        }
        else if (!p->prev && p->data == num)
        { // first node
            *l = p->next;
            p->next->prev = NULL;
            free(p);
            return;
        }
        else if (p->next && p->data == num)
        { // intermediate node
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            return;
        }
        else if (!p->next && p->data == num)
        { // last node
            p->prev->next = NULL;
            free(p);
            return;
        }
        p = p->next;
    }
    return;
}

/* ------- pop_first --------- */
void pop_first(Dll *l)
{
    if (*l == NULL)
        return;
    node *p;
    p = *l;
    while (p->next)
    {
        p->next->prev = NULL;
        *l = p->next;
        printf("%d\n", p->data);
        free(p);
        return;
    }
    *l = NULL;
    printf("%d\n", p->data);
    free(p);
    return;
}

/* ---------- isert_At --------- */
void insert_At(Dll *l, int posn, int num)
{
    int length = len(*l), i = 0;

    if (*l == NULL || posn >= length)
    {
        append(l, num);
        return;
    }
    node *p, *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (newnode)
    {
        newnode->data = num;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else
        return;
    p = *l;
    while (1)
    {
        if (i == posn && !p->prev)
        { // First node
            *l = newnode;
            newnode->next = p;
            p->prev = newnode;
            return;
        }
        else if (i == posn)
        { // intermediate node
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

/* -------- sort ---------- */
void sort(Dll *l)
{
    if (!*l || !(*l)->next) // for sorting use extra pointer q
        return;
    node *p, *q = NULL;
    int temp;
    p = *l;
    while (p)
    {
        while (p != *l)
        {
            if (p->data < q->data)
            {
                temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
            if (q->next == p)
                break;
            q = q->next;
        }
        q = *l;
        p = p->next;
    }
    return;
}

/* -------- Union ---------- */
void Union(Dll l1, Dll l2)
{
    Dll L3;
    node *p, *q;
    p = l1;
    q = l2;
    while (p)
    {
        append(&L3, p->data);
        p = p->next;
    }
    while (q)
    {
        if (!search(l1, q->data))
            append(&L3, q->data);
        q = q->next;
    }
    printf("union of list1 and list2 : ");
    traverse(L3);
    L3 = NULL;
    return;
}

/* ---------- main ---------- */
int main()
{
    Dll L1, L2;
    init(&L1);
    init(&L2);
    append(&L1, 4);
    append(&L1, 5);
    append(&L1, 10);
    append(&L1, 9);
    append(&L1, 0);
    traverse(L1);
    printf("length of L1 = %d\n", len(L1));
    append(&L2, 4);
    append(&L2, 51);
    append(&L2, 10);
    append(&L2, 9);
    append(&L2, 80);
    traverse(L2);
    printf("length of L2 = %d\n", len(L2));
    //    printf("%s\n",search(L1, 4)?"found":"not found");
    //destroy(&L1);
    // traverse(L1);
    //printf("length of L1 = %d\n", len(L1));

    Remove(&L1, 10);
    //traverse(L1);
    //pop_first(&L1);
    //traverse(L1);
    //insert_At(&L1, 3, 40);
    traverse(L1);
    sort(&L1);
    traverse(L1);
    // Union(L1, L2);
    traverse(L1);

    return 0;
}
