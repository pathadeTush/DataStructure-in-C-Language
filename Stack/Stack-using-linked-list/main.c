/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    stack s1;   // here s1 will point to last(top) element of list
    init(&s1);
    push(&s1, 1);
    push(&s1, 2);
    //push(&s1, 3);
    //push(&s1, 4);
    traverse(s1);
    pop(&s1);
    traverse(s1);
    return 0;
}
