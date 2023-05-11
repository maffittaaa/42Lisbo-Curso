/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:43:37 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/16 15:57:49 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checkvariables(int character, va_list value, int *c)
{
	if (character == 'c')
		ftprtf_putchar_fd(va_arg(value, int), 1, c);
	else if (character == 'i' || character == 'd')
		ftprtf_putnbr_fd(va_arg(value, int), 1, c);
	else if (character == 's')
		ftprtf_putstr_fd((char *)va_arg(value, int *), 1, c);
	else if (character == 'x')
		ftprtf_putnbr_hexa(va_arg(value, unsigned int), character, c);
	else if (character == 'X')
		ftprtf_putnbr_hexa(va_arg(value, unsigned int), character, c);
	else if (character == 'p')
		ftprtf_putpointer(va_arg(value, unsigned long), c);
	else if (character == 'u')
		ftprtf_putnbr_unsigned(va_arg(value, unsigned int), c);
	else if (character == '%')
		ftprtf_putstr_fd("%", 1, c);
}

int	ft_printf(const char *string, ...)
{
	va_list	value;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(value, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			checkvariables(string[i + 1], value, &counter);
			i++;
		}
		else
			ftprtf_putchar_fd(string[i], 1, &counter);
		i++;
	}
	return (counter);
}
