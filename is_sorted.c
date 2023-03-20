#include "push_swap.h"

int is_sorted(t_node *head)
{
    while (head && head->nextInLine)
    {
        if (head->content > head->nextInLine->content)
            return (0);
        head = head->nextInLine;
    }
    return (1);
}