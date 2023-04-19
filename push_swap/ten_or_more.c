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

int get_best_friend(t_node **head_a, long number)
{
    t_node *tmp;
    long result;
    long counter;
    long bestfriend;

    tmp = *head_a;
    bestfriend = 0;
    counter = 0;

    while (tmp->nextInLine != *head_a)
    {
        result = (*head_a)->content - number;
        if ((result < counter) && ((*head_a)->content > number))
        {
            counter = result;
            bestfriend = (*head_a)->content;
            printf ("%ld sou linda", bestfriend);
        }
        (*head_a) = (*head_a)->nextInLine;
    }
    return (get_index(head_a, bestfriend));
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
    find_best_move(head_a, head_b);
            

}
