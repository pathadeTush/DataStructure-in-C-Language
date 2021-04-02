/*
*     Author : Tushar Chakradhar Pathade    
*     Follow : pathadeTush @https://github.com/pathadeTush
*/

#include <stdio.h>
#include <stdlib.h>
#include "Cqueue.h"

/* -------- main ----------- */
int main(){
    queue q1;
    init(&q1, 4);
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    traverse(q1);
    first(q1);
    last(q1);
    dequeue(&q1);
    traverse(q1);
    enqueue(&q1, 5);
    printf("new element 5 is entered in queue \n");
    traverse(q1);
    first(q1);
    last(q1);

    return 0;
}
