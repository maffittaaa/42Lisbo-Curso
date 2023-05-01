#include "push_swap.h"

int error_checker(int argc, char **argv, t_node **head_a)
{
    int     i;
    long    INT_MAX;
    long    INT_MIN;

    i = 1;
    INT_MAX = 2147483647;
    INT_MIN = -2147483648;

    //enquanto nao chegar ao fim dos argumentos verificar se sao numeros ou duplicados
    if (isDuplicate(head_a) == 1)
        printf("Error - Duplicate numbers\n");
    while (i < argc)
    {
        if (isNumber(argv[i]) == 0)
        {
            printf("Error - Not a number\n");
            return (1);
        }
        if (ft_atol(argv[i]) > INT_MAX)
        {
            printf("Error - big number\n");
            return (1);
        }
        if (ft_atol(argv[i]) < INT_MIN)
        {
            printf("Error - small number\n");
            return (1);
        }

        i++;
    }
    i = 0;
    while (++i < argc)
        lstnew(head_a, ft_atoi(argv[i]));
    return (0);
}