/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush

#include<stdio.h>
#include"Circular_Doubly_linked_list.h"
#include<limits.h>


int main(){
    CDLL L1;
    init(&L1);
    /*int e;
    if((e = popDLL(&L1)) == INT_MIN)
        printf("Empty List\n");
    else
        printf("%d\n",e );*/
append(&L1, 10);
append(&L1, 20);
append(&L1, 30);
append(&L1, 40);

traverse(L1);
//destroy(&L1);
// printf("\n");
//printf("%d\n", pop(&L1));
// printf("%s", search(L1, 20)? "found\n": "not found\n");
//insert_At(&L1, 6, 120);
// traverse(L1);
//Remove(&L1, 10);
// traverse(L1);
// printf("%d\n", len(L1));
//pop_last(&L1);
//destroy(&L1);
// append(&L1, 20);
reverse(&L1);
traverse(L1);
Remove_At(&L1, 1); // not index
sort(&L1);
traverse(L1);

/*
insertAt(&L1, 0, 50);
traverseDLL(L1);

 insertAt(&L1, 2, 60);
traverseDLL(L1);

 insertAt(&L1, 10, 70);
traverseDLL(L1);

 insertAt(&L1, 1, 80);
traverseDLL(L1);*/
    return 0;
}
