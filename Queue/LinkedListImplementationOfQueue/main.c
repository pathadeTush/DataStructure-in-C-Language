/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    queue q1;
    init(&q1);
    enqueue(&q1, 10);
    //enqueue(&q1, 20);
    //enqueue(&q1, 30);
    //enqueue(&q1, 140);
    dequeue(&q1);
    traverse(q1);

    return 0;
}
