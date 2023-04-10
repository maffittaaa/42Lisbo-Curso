#include "push_swap.h"

void    add_new_node(t_node **head, int num) 
{
    lstnew(head, num);
    *head = (*head)->prevInLine;
}

int remove_top_node(t_node **head)
{
    int content;
    t_node *last;

    if (*head == NULL)
        return (-1);
    content = (*head)->content;
    last = (*head)->prevInLine;
    *head = last;
    return (content);
}

void    see_int(void *ptr)
{
    int *value;

    value = (int*)ptr;
    printf("%d", *value);
}

void    create_stack(t_node **head, int num)
{
    add_new_node(&head, num);
    printf("The size of the stack is: %d\n", lstsize(&head));
    remove_top_node(&head);
    printf("The size of the stack is: %d\n", lstsize(&head));
    lstiter(head, see_int);
    printf("/n");

}