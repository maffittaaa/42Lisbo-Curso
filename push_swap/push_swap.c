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
    // int min;

    max = find_max(head_a);
    // min = find_min(head_a);

    push_b(head_a, head_b);
    push_b(head_a, head_b);
    three_numbers(head_a);
    while ((*head_a)->nextInLine->content > (*head_a)->content && (*head_a)->nextInLine->content < (*head_a)->prevInLine->content)
    { 
        push_a(head_a, head_b);
        if (*head_a == (*head_a)->nextInLine || *head_a == (*head_a)->nextInLine->nextInLine || *head_a == (*head_a)->nextInLine->nextInLine->nextInLine)
        
    }
}

int main(int argc, char **argv)
{
    t_node *head_a = NULL;
    t_node *head_b = NULL;

    if (error_checker(argc,argv, &head_a))
        return (1);

    //three_numbers(&head_a);
    //lstiter(&head_a, print_integer);
    // printf("%d\n", find_max(&head_a));
    // printf("%d\n", find_min(&head_a)); 
    //insertion_sort(&head_a);
    printf("%d is the lenght\n", length(&head_a));
    printf("%f is the mean of the nodes\n", mean_of_nodes(&head_a));
    // printf("%d is the index of the nodes\n", get_index(&head_a, number));
    //ten_or_more(&head_a, &head_b);
    five_numbers(&head_a, &head_b);
    lstiter(&head_a, print_integer);

    //five_numbers(&head_a);

    return 0;
}