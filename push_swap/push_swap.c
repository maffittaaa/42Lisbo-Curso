#include "push_swap.h"

int three_numbers(t_node *head)
{
    t_node *last;
    t_node *sec;

    if (length(head) <= 1)
        return ;

    sec = head->nextInLine;
    last = head->prevInLine;

    if (head > sec)
    {
        stack_swap(head);
    }
    if (sec < head && sec < last)
    {
        stack_rotate(head);
    }
    if (head > last)
    {
        stack_reverse_rotate(head);
    }
}

int main(int argc, char **argv)
{
    error_checker(argc,argv);
    return 0;
}