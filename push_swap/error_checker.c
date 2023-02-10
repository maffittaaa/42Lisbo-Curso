#include "push_swap.h"

t_stack *fill_the_values_of_the_stack(int argc, char **argv)
{
    int         i;
    long int    nb;
    t_stack     *stack_a;
    int         INT_MAX;
    int         INT_MIN;

    i = 1;
    nb = 0;
    stack_a = NULL;
    INT_MAX = 2147483647;
    INT_MIN = -2147483648;
    while (i < argc)
    {
        nb = ft_atoi(argv[i]);
        if (nb > INT_MAX || nb < INT_MIN)
            printf ("Error\n");

    }
}
