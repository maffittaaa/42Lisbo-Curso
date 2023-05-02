#include "push_swap.h"

void stack_swap(t_node **head)
{
	t_node  *thead;
    t_node  *sec;
    
    if (length(head) <= 1)
        return ;

    thead = (*head);
    sec = (*head)->nextInLine;
    thead->prevInLine->nextInLine = sec;
    sec->nextInLine->prevInLine = thead;
    thead->nextInLine = sec->nextInLine;
    sec->nextInLine = thead;
    sec->prevInLine = thead->prevInLine;
    thead->prevInLine = sec;
    (*head) = sec;
}

void stack_rotate(t_node **head)
{
    *head = (*head)->nextInLine;
}

void stack_reverse_rotate(t_node **head)
{
	*head = (*head)->prevInLine;
}