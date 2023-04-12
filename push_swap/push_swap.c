#include "push_swap.h"

void    three_numbers(t_node **head)
{
    if (length(head) <= 1)
        return ;
    if ((*head)->content < (*head)->nextInLine->content && (*head)->content < (*head)->prevInLine->content && (*head)->nextInLine->content < (*head)->prevInLine->content)
        return ;
    else if ((*head)->content < (*head)->prevInLine->content && (*head)->content < (*head)->nextInLine->content)
    {
        swap_a(head);
        rotate_a(head);
    }
    else if ((*head)->content < (*head)->prevInLine->content && (*head)->content > (*head)->nextInLine->content)
        swap_a(head);
    else if ((*head)->content > (*head)->prevInLine->content && (*head)->content < (*head)->nextInLine->content)
        reverse_rotate_a(head);
    else if ((*head)->nextInLine->content > (*head)->prevInLine->content && (*head)->nextInLine->content < (*head)->content)
    {
        swap_a(head);
        reverse_rotate_a(head);
    }
    else if ((*head)->nextInLine->content < (*head)->prevInLine->content && (*head)->nextInLine->content < (*head)->content)
        rotate_a(head);
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

void    five_numbers(t_node **head_a, t_node **head_b)
{
    int min; //dar set amanha
    int max; //dar set amanha
    int max_prev; //dar set amanha
    push_b(head_a, head_b);
    push_b(head_a, head_b);
    three_numbers(head_a);
    if ((*head_b) == max)
    {
        push_a(head_b, head_a);
        rotate_a(head_a);
    }
    else if ((*head_b) == max_prev)
    {
        push_a(head_b, head_a);
        reverse_rotate_a(head_a);
        push_b(head_a, head_b);
        rotate_a(head_a);
        push_a(head_b, head_a);
        rotate_a(head_a);
        push_a(head_b, head_a);
    }
    else if ()
    
}

// void    hundred_numbers(t_node **head_a, t_node **head_b)
// // {

// // }







int main(int argc, char **argv)
{
    t_node *head_a = NULL;
    t_node *head_b = NULL;

    error_checker(argc,argv, &head_a);

    three_numbers(&head_a);
    five_numbers(&head_a, &head_b);

    return 0;
}