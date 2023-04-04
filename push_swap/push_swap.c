#include "push_swap.h"

void    three_numbers(t_node **head)
{
    if (length(head) <= 1)
        return ;
    while (length(head) == 3)
    {
        if ((*head)->content > (*head)->nextInLine->content)
            stack_swap(head);
        if ((*head)->nextInLine->content < (*head)->content && (*head)->nextInLine->content < (*head)->prevInLine->content)
            stack_rotate(head);
        if ((*head)->content > (*head)->prevInLine->content)
            stack_reverse_rotate(head);
    }
}

void    five_numbers(t_node **head_a, t_node **head_b)
{
    int max;
    int max_prev;

    max = find_max(head_a);
    max_prev = find_max(head_a);

    push_b(head_a, head_b);
    push_b(head_a, head_b);
    three_numbers(head_a);
    push_a(head_b, head_a);
    if ((*head_a)->prevInLine->index == max && (*head_a)->content == max_prev)
    {
        reverse_rotate_a(head_a);
        push_b(head_a, head_b);
        three_numbers(head_a);
        push_a(head_b, head_a);
        rotate_a(head_a);
    }
    else if ((*head_a)->content > (*head_a)->nextInLine->content && (*head_a)->content < (*head_a)->nextInLine->nextInLine->content)
        swap_a(head_a);
    else
        rotate_a(head_a);

    push_a(head_b, head_a);
    if ((*head_a)->content > (*head_a)->nextInLine->content && (*head_a)->content < (*head_a)->nextInLine->nextInLine->content)
        swap_a(head_a);
    else if ((*head_a)->prevInLine->index == max && (*head_a)->content == max_prev)
    {
        reverse_rotate_a(head_a);
        push_b(head_a, head_b);
        rotate_a(head_a);
        push_a(head_b, head_a);
        rotate_a(head_a);
    }
    else if((*head_a)->content > (*head_a)->prevInLine->content)
        rotate_a(head_a);
}

void    hundred_numbers(t_node **head_a, t_node **head_b)
{
    int     *chunk1;
    int     chunk_size;
    int     temp1;
    int     temp2;

    chunk_size = 19;
    temp1 = scan_stack_from_top(head_a, chunk1, chunk_size);
    temp2 = scan_stack_from_bottom(head_a, chunk1, chunk_size);
    while ((*head_a)->nextInLine != *head_a)
    {
        if (temp1 < temp2)
        
    }

}







int main(int argc, char **argv)
{
    error_checker(argc,argv);
    return 0;
}