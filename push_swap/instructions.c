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

int   swap_a(t_node *head_a)
{
    // 0 1 2

    printf("sa\n");
    t_node  *last;
    t_node  *sec;
    
    if (length(head_a) <= 1)
        return ;

    last = head_a->prevInLine;
    sec = head_a->nextInLine;

    sec->prevInLine = last; // 0 = 2
    sec->nextInLine->prevInLine = head_a; // 1 = 2
    head_a->nextInLine = sec->nextInLine; // 0 = 2
    sec->nextInLine = head_a; // 1 = 0
    head_a = sec;
    // output =  1 0 2
}

int swap_b(t_node *head_b)
{
    printf("sb\n");
    t_node *last;
    t_node *sec;

    if (length(head_b) <= 1)
        return ;

    last = head_b->prevInLine;
    sec = head_b->nextInLine;

    sec->prevInLine = last; // 2 = 0
    sec->nextInLine->prevInLine = head_b; // 1 = 2
    head_b->nextInLine = sec->nextInLine; // 0 = 2
    sec->nextInLine = head_b; // 1 = 0
    head_b = sec;
    // output =  1 0 2
}

int both_swaps(t_node *head_a, t_node *head_b)
{
    printf("ss\n");
}

int rotate_a(t_node *head_a)
{
    // 0 1 2

    printf("ra\n");
    t_node  *sec;
   
    sec = head_a->nextInLine;

    head_a = sec;// the first element becomes the last one // 0 = 1

    // output 1 2 0
}

int rotate_b(t_node *head_b)
{
    printf("rb\n");

    t_node  *sec;
   
    sec = head_b->nextInLine;

    head_b = sec;
}

int both_rotates(t_node *head_a, t_node *head_b)
{
    printf("rr\n");
    while ((length(head_a) + length(head_b)) != NULL)
    {
        rotate_a(head_a);
        rotate_b(head_b);
    }
}

int reverse_rotate_a(t_node *head_a)
{
    // 0 1 2

    printf("rra\n");
    t_node  *last;
    last = head_a->prevInLine;

    head_a = last; // the last element becomes the first one // 2 = 0

    // output 2 0 1
}

int reverse_rotate_b(t_node *head_b)
{
    printf("rrb\n");
    t_node  *last;
    last = head_b->prevInLine;

    head_b = last;
}

int both_reverse_rotates(t_node *head_a, t_node *head_b)
{
    printf("rrr\n");
    while ((length(head_a) + length(head_b)) != NULL)
    {
        reverse_rotate_a(head_a);
        reverse_rotate_b(head_b);
    }
}

int push_a(t_node *head_a, t_node *head_b)
{
    printf("pa\n");

    t_node *last_b;
    t_node *sec_b;
    t_node *sec_a;
    t_node *last_a;

    if (head_b == NULL)
        return ;
    last_b = head_b->prevInLine;
    sec_b = head_b->nextInLine;
    last_a = head_a->prevInLine;
    sec_a = head_a->nextInLine;

    head_a->prevInLine = head_b;
    last_a->nextInLine = head_b;
    head_b->prevInLine = last_a;
    head_b->nextInLine = head_a;
    if (length(head_b) > 1) // criar funcao que calcule a length do stack
    {
        head_b = sec_b;
        last_b->nextInLine = sec_b;
        sec_b->prevInLine = last_b;
    }
    else
        head_b = 0;
}

int push_b(t_node *head_a, t_node *head_b)
{
    printf("pb\n");

    t_node *last_b;
    t_node *sec_b;
    t_node *sec_a;
    t_node *last_a;

    if (head_a == NULL)
        return ;
    last_b = head_b->prevInLine;
    sec_b = head_b->nextInLine;
    last_a = head_a->prevInLine;
    sec_a = head_a->nextInLine;

    head_b->prevInLine = head_a;
    last_b->nextInLine = head_a;
    head_a->prevInLine = last_b;
    head_a->nextInLine = head_b;
    if (length(head_a) > 1)
    {
        head_b = sec_b;
        last_b->nextInLine = sec_b;
        sec_b->prevInLine = last_b;
    }
    else
        head_a = 0;

}
