#include "push_swap.h"

void   lstnew(t_node **head, int number)
{
   t_node *new_node;

   new_node = (t_node *)malloc(sizeof(t_node));
   if (!new_node)
      return ;
   new_node->content = number;
   if(!*head)
   {
      (*head) = new_node;
      new_node->prevInLine = new_node;
      new_node->nextInLine = new_node;
   }
   else
   {
      new_node->prevInLine = (*head)->prevInLine;
      (*head)->prevInLine->nextInLine = new_node;
      (*head)->prevInLine = new_node;
      new_node->nextInLine = *head;
   }
}

