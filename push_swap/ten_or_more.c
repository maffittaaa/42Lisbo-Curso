#include "push_swap.h"

float   mean_of_nodes(t_node **head)
{
    int sum;
    int count;
    float mean;
    t_node *current_node;

    sum = 0;
    count = length(head);
    mean = 0.0;
    current_node = *head;
    while (current_node->nextInLine != *head)
    {
        sum = sum + current_node->content;
        current_node = current_node->nextInLine;
    }
    sum = sum + current_node->content;
    mean = (double)sum / count;
    return (mean);
}

int get_best_friend(t_node **head_a, t_node **head_b)
{
    t_node *tmp;
    int counter;
    int best_friend;

    tmp = *head_b;
    counter = 0;
    best_friend = 0;
    while (length(head_a))
    {
        tmp->content = (*head_a)->content - (*head_b)->content;
        if ((*head_a)->content > tmp->content)
        {
            counter = tmp->content;
            best_friend = (*head_a)->content;
        }
        else
            (*head_a) = (*head_a)->nextInLine;
    }
    return (get_index(head_a, best_friend));
    
}

void    ten_or_more(t_node **head_a, t_node **head_b)
{
    float   mean;

    while (length(head_a) > 5)
    {
        mean = mean_of_nodes(head_a);
        if ((*head_a)->content <= mean)
            push_b(head_a, head_b);
        else if ((*head_a)->content > mean)
            rotate_a(head_a);
        printf("%f is the mean of the nodes\n", mean_of_nodes(head_a));
    }
    while (length(head_b))
    {
        
    }
            

}
