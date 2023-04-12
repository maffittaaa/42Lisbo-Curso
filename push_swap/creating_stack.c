#include "push_swap.h"

// void    push(t_node **head, int num) 
// {
//     lstnew(head, num);
//     *head = (*head)->prevInLine;
// }

// void    pop(t_node **head)
// {
//     t_node *temp;

//     if (*head == NULL)
//         return ;
//     temp = *head;
//     *head = (*head)->nextInLine;
//     (*head)->prevInLine = temp->prevInLine;
// }

void    print_integer(int *content)
{
    printf("%d\n", *content);
}