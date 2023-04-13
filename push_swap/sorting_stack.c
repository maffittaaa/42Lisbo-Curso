#include "push_swap.h"

void    pop(t_node **head)
{
    t_node *top;
    t_node *start;

    top = 0;
    start = 0;
    if (*head == NULL)
        return ;

}


void    sorting_while_inserting(t_node **head, t_node *new_node)
{
    t_node *current_node;

    current_node = *head;
    if (current_node == NULL)
    {
        new_node->nextInLine = new_node;
        *head = new_node;
    }
    else if (current_node->content >= new_node->content) //novo node inserted antes do head node
    {
        while (current_node->nextInLine != *head)
        {
            current_node->nextInLine = new_node;
            new_node->nextInLine = *head;
            *head = new_node;
        }
    }
    else // novo node inserted algures depois da head
    {
        while (current_node->nextInLine != *head && current_node->nextInLine->content < new_node->content)
            current_node = current_node->nextInLine; //localiza o node que o novo node vai ser inserido depois de
    }
    new_node->nextInLine = current_node->nextInLine;
    current_node->nextInLine = new_node;
}