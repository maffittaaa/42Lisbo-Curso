#include "push_swap.h"

void    lstiter(t_node *head, void (*f)(void *))
{
    t_node *last;

    while (head != NULL)
    {
        f(last->content);
        last = head;
        head = head->nextInLine;
    }
    while (last != NULL)
    {
        f(last->content);
        last = last->prevInLine;
    }
}