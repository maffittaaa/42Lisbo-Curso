#include "push_swap.h"

int   swap_a(t_node *head_a)
{
    printf("sa\n");
    stack_swap(head_a);
}

int rotate_a(t_node *head_a)
{
    printf("ra\n");
    stack_rotate(head_a);
}

int reverse_rotate_a(t_node *head_a)
{
    printf("rra\n");
    stack_reverse_rotate(head_a);
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
    if (length(head_b) > 1) // funcao que calcule a length do stack
    {
        head_b = sec_b;
        last_b->nextInLine = sec_b;
        sec_b->prevInLine = last_b;
    }
    else
        head_b = 0;
}