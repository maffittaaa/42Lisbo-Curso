#include "push_swap.h"
#include <unistd.h>

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
void    five_numbers(t_node **head_a, t_node **head_b, int len)
{   
    int max;
    int min;

    max = find_max(head_a);
    min = find_min(head_a);
    printf("max = %d, min = %d\n", max, min);

    while (length(head_a) > 3)
        push_b(head_a, head_b);
    three_numbers(head_a);
    while (length(head_a) < len)
    {
        if ((*head_b)->content == max
            || (*head_b)->content == min
            || (*head_b)->content > find_max(head_a)
            || (*head_b)->content < find_min(head_a))
            while ((*head_a)->content != find_min(head_a))
                rotate_a(head_a);
        else
          while (!((*head_a)->content > (*head_b)->content
            && (*head_a)->prevInLine->content < (*head_b)->content))
            rotate_a(head_a);
        push_a(head_b, head_a);
    }
    while ((*head_a)->content != min)
        rotate_a(head_a);   
    lstiter(head_a, print_integer);
}

int main(int argc, char **argv)
{
    t_node *head_a = NULL;
    t_node *head_b = NULL;

    if (error_checker(argc,argv, &head_a))
        return (1);
    printf("%d is the lenght\n", length(&head_a));
    printf("%f is the mean of the nodes\n", mean_of_nodes(&head_a));
    if (length(&head_a) > 9)
        ten_or_more(&head_a, &head_b);
    else if (length(&head_a) == 3)
        three_numbers(&head_a);
    else
        five_numbers(&head_a, &head_b, length(&head_a));
    lstiter(&head_a, print_integer);

    return 0;
}