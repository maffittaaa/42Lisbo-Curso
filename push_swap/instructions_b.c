#include "push_swap.h"

void swap_b(t_node **head_b)
{
    printf("sb\n");
    stack_swap(head_b);
}

void rotate_b(t_node **head_b)
{
    printf("rb\n");
    stack_rotate(head_b);
}

void reverse_rotate_b(t_node **head_b)
{
    printf("rrb\n");
    stack_reverse_rotate(head_b);
}

void push_b(t_node **head_a, t_node **head_b)
{
    t_node *tmp;

    printf("pb\n");
    if (*head_a == NULL)
        return ;
    tmp = *head_a;
    if (length(head_a) > 1)
    {
        (*head_a)->prevInLine->nextInLine = (*head_a)->nextInLine;
        (*head_a)->nextInLine->prevInLine = (*head_a)->prevInLine;
        *head_a = tmp->nextInLine;
    }
    else
        *head_a = 0;
    if (length(head_b) > 0)
    {
        tmp->nextInLine = *head_b;
        tmp->prevInLine = (*head_b)->prevInLine;
        (*head_b)->prevInLine->nextInLine = tmp;
        (*head_b)->prevInLine = tmp;
        *head_b = tmp;
    }
    else
    {
        *head_b = tmp;
        tmp->nextInLine = tmp;
        tmp->prevInLine = tmp;
    }
}