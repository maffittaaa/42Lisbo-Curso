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

// void    five_numbers(t_node **head)
// {
    
// }

int main(int argc, char **argv)
{
    t_node *head_a = NULL;

    error_checker(argc,argv, &head_a);

    //three_numbers(&head_a);
    //lstiter(&head_a, print_integer);
    printf("%d\n", find_max(&head_a));
    //five_numbers(&head_a);

    return 0;
}