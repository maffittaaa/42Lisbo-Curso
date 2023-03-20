#include "push_swap.h"

void    three_numbers(t_node *head)
{
    t_node *last;
    t_node *sec;

    if (length(head) <= 1)
        return ;

    sec = head->nextInLine;
    last = head->prevInLine;
    
    while (length(head) == 3)
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

void    five_numbers(t_node *head_a, t_node *head_b)
{
    t_node *last_b;
    t_node *sec_b;
    t_node *last_a;
    t_node *sec_a;
    int max;
    int max_prev;
    int min;
    int min_next;

    last_b = head_b->prevInLine;
    sec_b = head_b->nextInLine;
    last_a = head_a->prevInLine;
    sec_a = head_a->nextInLine;
    max = find_max(head_a, max);
    max_prev = find_max(head_a, max_prev);
    min = find_min(head_a, min);
    min_next = find_min(head_a, min_next);

    while (length(head_a) >= 4)
        push_b(head_a, head_b);
    while (length(head_a) == 3)
    {
        three_numbers(head_a);
        if (length(head_b) == 2)
        {
            push_a(head_b, head_a);
            if (last_a->index == max && head_a == max_prev)
            {
                reverse_rotate_a(head_a);
                push_b(head_a, head_b);
                three_numbers(head_a);
                push_a(head_b, head_a);
                rotate_a(head_a);
            }
            if (head_a > sec_a && head_a < sec_a->nextInLine)
                swap_a(head_a);
            else
                rotate_a;
        }
        if (length(head_b) == 1)
        {
            if (head_a->index == min)
                push_a(head_b, head_a);
            if (head_a > sec_a && head_a < sec_a->nextInLine)
                swap_a(head_a);
            
            

    }       
}

void    hundred_numbers(t_node *head)
{

}







int main(int argc, char **argv)
{
    error_checker(argc,argv);
    return 0;
}