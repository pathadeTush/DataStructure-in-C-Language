/*
*     Author : Tushar Chakradhar Pathade    
*     Follow : pathadeTush @https://github.com/pathadeTush
*/

/*
Algorithm to convert infix expression to postfix:

1. Declare a char Stack and initialize it
2. Read the infix expression from L-R char by char
3. if operand is encountered - append it to output string
4. if '(' is encountered - push it in the stack
5. if ')' pop all characters and apppend to output string till
    '(' is encountered. DO not append ')'
6. if operator is encountered pop all operators of higher or equal precedence and append to o/p
    or till stack is not empty or ')' is encountered. drop ')'
7. push the operator of step 6.
8  repeat 2 - 6 till end of expression
9 pop all characters and append.
*/

/*

Note: We can use stack and array to convert infix expression to postfix expression. But In c every data types has some limitations. Because of that we couldn't take input of any length. Hence to make sure that program can run for input of any length(even infinte length), I have use linked list data structure. As linked list is Dynamic data structure and do not have limitation with length.

Aim: To take input of infinite length and perform operation same.

*/

#include <stdio.h>
#include <ctype.h>
#include "Infix2Postfix.h"

int precedence(int c)
{
    if (c == '+' - '0')
        return 10;
    else if (c == '-' - '0')
        return 10;
    else if (c == '*' - '0')
        return 20;
    else if (c == '/' - '0')
        return 20;
    else if (c == '%' - '0')
        return 20;
    else if (c == '^' - '0')
        return 30;
    else if (c == '(' - '0')
        return 5;
    return 0;
}

int main()
{
    CDLL in, post, s; // in stores the input expression, post stores the postfix expression which is output and s is used for intermediate operation.
    init(&in);
    init(&post);
    init(&s);
    int num1;

    printf("Enter a expression : ");
    while (1)
    {
        num1 = fgetc(stdin);
        append(&in, num1 - '0');
        // printf("%d ", num1-'0');
        if (num1 == '\n')
            break;
    }
    // use this to see the all the characters present in a list
    // You can use this for debugging purpose
    // traverse(in);
    // traverse_expr(in);

    int c;
    while (in->data != '\n' - '0')
    {
        c = in->data;
        // printf("%d  ", c);
        if (isDigit(c))
        {
            append(&post, c);
            if (!isDigit(in->next->data) && in->next->data != '.' - '0')
                append(&post, ' ' - '0');
        }
        else if (c == '(' - '0')
            append(&s, '(' - '0');
        else if (c == ')' - '0')
        {
            while (s && peek(s) != '(' - '0')
            {
                append(&post, pop_last(&s));
                append(&post, ' ' - '0');
            }
            if (peek(s) == '(' - '0')
                pop_last(&s);
        }
        else
        {
            if (c == '+' - '0' || c == '-' - '0' || c == '*' - '0' || c == '/' - '0')
            {
                if (!s)
                    append(&s, c);
                else
                {
                    while (s && precedence(peek(s)) >= precedence(c))
                    {
                        append(&post, pop_last(&s));
                        append(&post, ' ' - '0');
                    }
                    append(&s, c);
                }
            }
        }
        in = in->next;
    }

    while (s)
    {
        append(&post, pop_last(&s));
        append(&post, ' ' - '0');
    }
    append(&post, '#'); // '#' is used as terminator character  or end of postfix expression
    // traverse(post);          // use this to see the all the characters present in a list
    traverse_expr(post);

    return 0;
}
