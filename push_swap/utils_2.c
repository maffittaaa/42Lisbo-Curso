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

int find_max(t_node **last)
{
    int     max;

    max = (*last)->index;
    while ((*last)->prevInLine)
    {
        if ((*last)->index > max)
            max = (*last)->index;
    }
    return (max);
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

int    scan_stack_from_top(t_node **head, int *chunk, int chunk_size)
{
    t_node *temp;
    int hold_first;
    int i;

    hold_first = 0;
    temp = (*head)->top;

    while (temp->nextInLine != *head)
    {
        //scan from the top
        while (i < chunk_size)
        {
            if (temp->content == chunk[i])
                hold_first = 1;
        }
        i++;
    }
    temp = temp->prevInLine;
    if (hold_first == 0)
        printf("no number from chunk 1 inside of stack A\n");
    return (temp);
}

int   scan_stack_from_bottom(t_node **head, int *chunk, int chunk_size)
{
    t_node *temp;
    int     i;
    int     hold_second;

    hold_second = 0;
    temp = (*head)->top;

    while (temp->prevInLine != *head)
        temp = temp->prevInLine; //mover o pinter para a posicao mais em baixo do stack
    while (temp != *head)
    {
        while (i < chunk_size)
        {
            if (temp->content == chunk[i])
                hold_second = 1;
        }
        i++;
    }
    temp = temp->nextInLine;
    if (hold_second == 0)
        printf("no number from chunk 1 inside of stack A\n");
    return (temp);
}