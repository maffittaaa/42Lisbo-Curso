//#include "push_swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_node
{
    t_node *prevInLine;
    int data;
    t_node *nextInLine;
}   t_node;

int   swap_a(t_node *head)
{
    // 0 1 2

    printf("sa\n");
    t_node  *last;
    t_node  *sec;
   
   last = head->prevInLine;
   sec = head->nextInLine;

    sec->prevInLine = last; // 2 = 0
    sec->nextInLine->prevInLine = head; // 1 = 2
    head->nextInLine = sec->nextInLine; // 0 = 2
    sec->nextInLine = head; // 1 = 0
    head = sec;
    // output =  1 0 2
}

int rotate_a(t_node *head)
{
    // 0 1 2

    printf("ra\n");
    t_node  *sec;
   
    sec = head->nextInLine;

    head = sec;// the first element becomes the last one // 0 = 1

    // output 1 2 0
}

int reverse_rotate_a(t_node *head)
{
    // 0 1 2

    printf("rra\n");
    t_node  *last;
    last = head->prevInLine;

    head = last; // the last element becomes the first one // 2 = 0

    // output 2 0 1
}


