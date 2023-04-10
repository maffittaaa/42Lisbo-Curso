#include "push_swap.h"

void    lstiter(t_node **head, void (*f)(void *))
{
    t_node *temp;
    t_node *temp2;

    if (!*head)
        return ;
    temp = (*head)->nextInLine;
    while (temp != *head)
    {
        temp2 = temp->nextInLine;
        f(temp);
        temp = temp2;
        temp2 = 0;
    }
    while (*head)
    {
        f(*head);
        temp = temp->prevInLine;
    }
}