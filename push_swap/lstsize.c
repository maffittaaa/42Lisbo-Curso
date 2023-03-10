#include "push_swap.h"

int lstsize(t_node *head)
{
    t_node *temp;
    int size;

    if (!head)
        return (NULL);
    
    temp = head->nextInLine;
    size = 0;
    while (temp && temp != head && temp != temp->nextInLine)
    {
        size++;
        temp = temp->nextInLine;
    }
    if (temp)
        size++;
    return (size);
}