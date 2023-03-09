#include "push_swap.h"

int error_checker(int argc, char **argv)
{
    int     i;
    long    INT_MAX;
    long    INT_MIN;

    i = 1;
    INT_MAX = 2147483647;
    INT_MIN = -2147483648;
    //enquanto nao chegar ao fim dos argumentos verificar se sao numeros ou duplicados
    if (isDuplicate(argc, argv) == 1)
        printf("Error - Duplicate numbers\n");
    while (i < argc)
    {
        if (isNumber(argv[i]) == 0)
        {
            printf("Error\n");
            return (1);
        }
        if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
        {
            printf("Error\n");
             return (1);
        }
        i++;
    }
    return (0);
}

//verificar se o argumento que esta a ser passado e um numero
//verificar cada caracter do argumento
int isNumber(char *number)
{
    int i;

    i = 0;
    if (number[i] == '-')
        i++;
    while(number[i] != 0)
    {
        if (ft_isdigit(number[i]) == 1)
            i++;
        else
            return (0);
    }
    return (1);
}

//verificar se o argumento passado e duplicado
int isDuplicate(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (!ft_strcmp(argv[i], argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}