/*
*     Author : Tushar Chakradhar Pathade    
*     Follow : pathadeTush @https://github.com/pathadeTush
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "Infix2Postfix.h"

void init(CDLL *l)
{
    *l = NULL;
    return;
}

void append(CDLL *l, int d)
{
    node *nn = (node *)malloc(sizeof(node));
    if (nn)
    {
        nn->data = d;
        nn->next = nn;
        nn->prev = nn;
    }
    else
        return;
    if (*l == NULL)
    {
        *l = nn;
        return;
    }
    node *first, *last;
    first = *l;
    last = first->prev;
    first->prev = nn;
    last->next = nn;
    nn->next = first;
    nn->prev = last;
    return;
}

void traverse(CDLL l)
{
    printf("[ ");
    node *p;
    p = l;
    while (p)
    {
        if (p->data == -2)
            printf(". ");
        else
            printf("%d ", p->data);
        p = p->next;
        if (p == l)
            break;
    }
    printf("]\n");
    return;
}

void traverse_expr(CDLL l)
{
    node *p;
    p = l;
    while (p)
    {
        if (p->data == '.' - '0')
            printf(".");
        else if (p->data == '+' - '0')
            printf("+");
        else if (p->data == '-' - '0')
            printf("-");
        else if (p->data == '*' - '0')
            printf("*");
        else if (p->data == '/' - '0')
            printf("/");
        else if (p->data == '(' - '0')
            printf("(");
        else if (p->data == ')' - '0')
            printf(")");
        else if (p->data == ' ' - '0')
            printf(" ");
        else if (p->data == '\n' - '0')
            break;
        else if (p->data == '#')
            break;
        else
            printf("%d", p->data);
        p = p->next;
        if (p == l)
            break;
    }
    printf("\n");
    return;
}

/* -------- search ---------- */
int search(CDLL l, int num)
{
    node *p;
    p = l;
    while (p)
    {
        if (p->data == num)
            return 1;
        if (p->next == l)
            break;
        p = p->next;
    }
    return 0;
}

/* ------- pop_last --------- */
int pop_last(CDLL *l)
{
    if (*l == NULL)
        return INT_MIN;
    node *p = *l;
    int ele;
    ele = p->data;
    if (p->prev == p)
    {
        *l = NULL;
        free(p);
        return ele;
    }
    node *last = p->prev;
    ele = last->data;
    p->prev = last->prev;
    last->prev->next = p;
    free(last);
    return ele;
}

/* ------- pop_first --------- */
void pop_first(CDLL *l)
{
    if (*l == NULL)
        return;
    node *p = *l;
    if (p->prev == p)
    {
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

/* ------- peek --------- */
int peek(CDLL l)
{
    int ele = INT_MIN;
    if (l == NULL)
        return ele;
    ele = l->prev->data;
    return ele;
}

/* --------- isdigit -------- */
int isDigit(int d)
{
    if (d == 1 || d == 2 || d == 3 || d == 4 || d == 5 || d == 6 || d == 7 || d == 8 || d == 9 || d == 0 || d == -2)
        return 1;
    else
        return 0;
}
