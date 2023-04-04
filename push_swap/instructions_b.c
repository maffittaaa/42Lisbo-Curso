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
    printf("pb\n");

    t_node *last_b;
    t_node *sec_b;

    if (*head_a == NULL)
        return ;
    last_b = (*head_b)->prevInLine;
    sec_b = (*head_b)->nextInLine;

    (*head_b)->prevInLine = *head_a;
    last_b->nextInLine = *head_a;
    (*head_a)->prevInLine = last_b;
    (*head_a)->nextInLine = *head_b;
    if (length(head_a) > 1) // funcao que calcule a length do stack
    {
        *head_b = sec_b;
        last_b->nextInLine = sec_b;
        sec_b->prevInLine = last_b;
    }
    else
        *head_a = 0;

}