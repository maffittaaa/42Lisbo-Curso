#include "push_swap.h"

void    insertion_sort(t_node **head)
{
    t_node *current_node;
    t_node *min;

    min = find_min(head);
    current_node = *head;
    if (current_node == min)
        current_node = current_node->nextInLine;
    else
        current_node = *head;
    printf ("%d here\n", current_node->content);
    while (current_node->nextInLine != *head)
    {
        if (current_node->content > current_node->nextInLine->content)
        {
            printf("%d here\n", current_node->content);
            swap_a(head);
            current_node = current_node->nextInLine;
        }
        if ((*head)->prevInLine == min)
        {
            printf("%d here\n", current_node->content);
            reverse_rotate_a(head);
        }
        if ((*head)->prevInLine > (*head)->nextInLine && (*head)->prevInLine < *head)
        {
            reverse_rotate_a(head);
            if ((*head) > (*head)->nextInLine)
                swap_a(head);
        }
        else
            return ;
    }
    
}
