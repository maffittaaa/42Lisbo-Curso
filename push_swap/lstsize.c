#include "push_swap.h"

int lstsize(t_node **head)
{
    t_node *temp;
    int size;

    if (!*head)
        return (0);
    
    temp = (*head)->nextInLine;
    size = 1;
    while (temp != *head)
    {
        size++;
        temp = temp->nextInLine;
    }
    return (size);
}