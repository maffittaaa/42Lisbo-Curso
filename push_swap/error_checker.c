#include "push_swap.h"

int error_checker()
{
    i = 1;
    //enquanto nao chegar ao fim dos argumentos verificar se sao numeros ou duplicados
    while (i <= argc)
    {
        if (isNumber(argv[i] == 0))
        {
            printf("Error\n");
            break;
        }
        if (argv[i] > INT_MAX || argv[i] < INT_MIN)
        {
            printf("Error\n");
            break;
        }
        if (isDuplicate(argv[i] == 1))
        {
            printf("Error\n");
            break;
        }
        i++;
    }
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
        if (ft_isdigit(number[i] == 1))
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
            if (ft_strcmp(argv[i], argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}