/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

#include<stdio.h>
#include "stack.h"
#include<limits.h>

int main() {
    stack s1, s2;
    init(&s1,100);
    init(&s2, 10);
    int item;
    while(1){
        item = fgetc(stdin);
        if(item == '\n')
            break;
        if(item != ' ')
            push(&s1, item - '0');
    }
    printf("Stack 1\n");
    while((item = pop(&s1))!= INT_MIN)
        printf("%d\n", item);
    return 0;
}

