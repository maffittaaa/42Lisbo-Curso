#include "push_swap.h"

void    lstiter(t_node **head, void (*f)(int *))
{
    t_node *temp;
    t_node *next;

    if (!*head)
        return ;
    next = (*head)->nextInLine;
    f(&(*head)->content);
    temp = next;
    while (temp != *head)
    {
        next = temp->nextInLine;
        f(&temp->content);
        temp = next;
    }
}

//dar free aos nodes todos
void    lstiter_node(t_node **head, void (*k)(void *))
{
    t_node *temp;
    t_node *next;

    if (!*head)
        return ;
    next = (*head)->nextInLine;
    k((*head));
    temp = next;
    while (temp != *head)
    {
        next = temp->nextInLine;
        k(temp);
        temp = next;
    }
}