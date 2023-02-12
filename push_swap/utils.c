#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int					neg;
	unsigned long int	result;
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

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
