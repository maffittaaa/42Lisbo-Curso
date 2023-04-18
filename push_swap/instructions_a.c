#include "push_swap.h"

void   swap_a(t_node **head_a)
{
    printf("sa\n");
    stack_swap(head_a);
}

void rotate_a(t_node **head_a)
{
    printf("ra\n");
    stack_rotate(head_a);
}

void reverse_rotate_a(t_node **head_a)
{
    printf("rra\n");
    stack_reverse_rotate(head_a);
}

void push_a(t_node **head_b, t_node **head_a)
{
    printf("pa\n");
    t_node *tmp;

    if (*head_b == NULL)
        return ;
    tmp = *head_b;
    if (length(head_b) > 1)
    {
        (*head_b)->prevInLine->nextInLine = (*head_b)->nextInLine;
        (*head_b)->nextInLine->prevInLine = (*head_b)->prevInLine;
        *head_b = tmp->nextInLine;
    }
    else
        *head_b = 0;
    if (length(head_a) > 0)
    {    
        tmp->nextInLine = *head_a;
        (*head_a)->prevInLine->nextInLine = tmp;
        (*head_a)->prevInLine = tmp;
        *head_a = tmp;
    } 
    else
    {
        *head_a = tmp;
        tmp->nextInLine = tmp;
        tmp->prevInLine = tmp;
    }
}