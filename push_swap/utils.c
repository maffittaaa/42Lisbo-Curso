#include "push_swap.h"

long	ft_atol(const char *str)
{
	int					neg;
	unsigned long		result;
	size_t				index;

	neg = 1;
	result = 0;
	index = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32) // se for um espaco ou um tab etc, passa a frente
		index++;
	if (str[index] == '-' || str[index] == '+') //se o numero for negativo, tornamos positivo
	{
		if (str[index++] == '-')
			neg *= -1;
	}
	while (str[index] >= '0' && str[index] <= '9') // se for um numero, str[index] = elemento que encontramos, result e a casa
	{
		result = (result * 10) + (str[index] - 48);
		index++;
	}
	return (result * neg);
}

int length(t_node **head)
{
	int i;
	t_node *temp;

	i = 1;
	if (*head == NULL)
		return (0);
	temp = *head;
	while (temp->nextInLine != *head)
	{
		temp = temp->nextInLine;
		i++;
	}
	return (i);
}

int	get_index(t_node **head, int num)
{
	int	i;

	i = 0;
	while (*head)
	{
		if ((*head)->content == num)
			return (i);
		i++;
		(*head) = (*head)->nextInLine;
	}
	return (0);
}