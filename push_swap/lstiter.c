#include "push_swap.h"

void    lstiter(t_node **head, void (*f)(int *))
{
    t_node *temp;

    if (!*head)
        return ;
    temp = (*head)->nextInLine;
    f(&(*head)->content);
    while (temp != *head)
    {
        f(&temp->content);
        temp = temp->nextInLine;
    }
}