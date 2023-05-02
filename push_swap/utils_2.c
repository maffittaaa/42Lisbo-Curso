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
    if (ft_strlen(number) > 11)
        return (0);
    if (number[i] == '-' || number[i] == '+')
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
int isDuplicate(t_node **head)
{   
    t_node *tmp;
    t_node *tmp2;

    if (*head == NULL)
        return (0);
    tmp = *head;
    while (tmp->nextInLine != *head)
    {
        tmp2 = tmp->nextInLine;
        while (tmp2->nextInLine != (*head)->nextInLine)
        {
            if (tmp->content == tmp2->content)
                return (1);
            tmp2 = tmp2->nextInLine;
        }
        tmp = tmp->nextInLine;
    }
    return (0);
}

//encontra o maximo no stack que estamos
int find_max(t_node **head)
{
    t_node *max;
    t_node *temp;

    temp = (*head)->nextInLine;
    max = *head;

    while (temp != *head)
    {
        if (temp->content > max->content)
            max = temp;
        temp = temp->nextInLine;
    }
    return (max->content);
}

//encontra o minimo no stack que estamos
int find_min(t_node **head)
{
    t_node *min;
    t_node *temp;

    temp = (*head)->nextInLine;
    min = *head;

    while (temp != *head)
    {
        if (temp->content < min->content)
            min = temp;
        temp = temp->nextInLine;
    }
    return (min->content);
            
}

//da print aos numeros
void    print_integer(int *content)
{
    printf("%d\n", *content);
}