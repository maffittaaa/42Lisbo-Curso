#include "push_swap.h"

void stack_swap(t_node *head)
{
	t_node  *last;
    t_node  *sec;
    
    if (length(head) <= 1)
        return ;

    last = head->prevInLine;
    sec = head->nextInLine;

    sec->prevInLine = last;
    sec->nextInLine->prevInLine = head;
    head->nextInLine = sec->nextInLine;
    sec->nextInLine = head; 
    head = sec;
}

void stack_rotate(t_node *head)
{
	t_node  *sec;
   
    sec = head->nextInLine;

    head = sec;
}

void stack_reverse_rotate(t_node *head)
{
	t_node *last;

	last = head->prevInLine;

	head = last;
}