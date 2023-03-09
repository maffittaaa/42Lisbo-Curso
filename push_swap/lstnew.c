#include "push_swap.h"

void   lstnew(t_node *head, int number)
{
   t_node *new_node;

   new_node = (t_node *)malloc(sizeof(t_node));
   if (!new_node)
      return ;
   new_node->content = number;
   new_node->prevInLine = head->prevInLine;
   new_node->nextInLine = head;
   head->prevInLine = new_node;
}