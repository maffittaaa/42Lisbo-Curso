#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
            if (!ft_strcmp(argv[i],argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int find_max(t_node **head)
{
    int min;

    min = (*head)->index;
    while ((*head)->nextInLine)
    {
        if ((*head)->index < min)
            min = (*head)->index;
    }
    return (min);
}

int find_min(t_node **head)
{
    int min;

    min = (*head)->index;
    while ((*head)->nextInLine)
    {
        if ((*head)->index < min)
            min = (*head)->index;
    }
    return (min);
    
}