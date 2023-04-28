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

int get_best_friend(t_node **head_a, int number)
{
    t_node *tmp;
    int best_friend_i;
    int best_diff;
    int iterator;

    best_diff = 2147483647;
    iterator = -1;
    tmp = *head_a;
    while (++iterator < length(head_a))
    {
        if (tmp->content - number > 0 && tmp->content - number < best_diff)
        {
            best_diff = tmp->content - number;
            best_friend_i = iterator;
        }
        tmp = tmp->nextInLine;
    }
    return (best_friend_i);
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
        lstiter(head_a, print_integer);
    }
    five_numbers(head_a, head_b, 5);
    while (length(head_b))
        find_best_move(head_a, head_b);
}
