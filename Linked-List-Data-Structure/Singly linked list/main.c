/*
*     Author : Tushar Chakradhar Pathade    
*     Source : https://github.com/pathadeTush
*/

#include<stdio.h>
#include"list.h"

int main(){
    list L1, L2;
    init(&L1);
    init(&L2);
    append(&L1, 1);
    append(&L1, 8);
    append(&L1, 10);
    append(&L1, 4);
    //append(&L1, 5);
    //append(&L1, 6);
   // insert_beg(&L1,7);
   // insert_at(&L1, 0 , 8);
    //insert_at(&L1, 3 , 11);
    //insert_at(&L1, 0 , 9);
    //Remove(&L1, 3);
    //Remove(&L1, 5);
    //Remove(&L1, 9);
    printf("elements of L1 : ");
    traverse(L1);
    //append(&L2, 4);
    //append(&L2, 8);
    //append(&L2, 5);
    //append(&L2, 9);
    //printf("elements of L2 : ");
    //traverse(L2);
    //list L3;
    //init(&L3);
    //L3 = Union(L1, L2);
    //traverse(L3);
    //search(L1,3)? printf("\nfound\n"):printf("\nNot Found\n");
    //Remove(&L1 , 2);
    //traverse(L1);
    //printf("\n%d\n", pop(&L1));
    //destroy(&L1);
    //printf("last ele = %d\n", pop(&L1));
    reverse(&L1);
    traverse(L1);
    sort(&L1);
    traverse(L1);
    return 0;
}

