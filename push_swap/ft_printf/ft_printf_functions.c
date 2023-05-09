/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:14:14 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/16 16:01:08 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftprtf_putnbr_fd(int n, int fd, int *counter)
{
	long	i;
	char	c;

	i = (long)n;
	if (i < 0)
	{
		write(fd, "-", 1);
		*counter = *counter + 1;
		i *= -1;
	}
	if (i >= 10)
	{
		ftprtf_putnbr_fd(i / 10, fd, counter);
		ftprtf_putnbr_fd(i % 10, fd, counter);
	}
	else
	{
		c = i + 48;
		write(fd, &c, 1);
		*counter = *counter + 1;
	}
}

void	ftprtf_putnbr_unsigned(unsigned int n, int *counter)
{
	long	i;
	char	c;

	i = (long)n;
	if (i < 0)
		return ;
	if (i >= 10)
	{
		ftprtf_putnbr_unsigned(i / 10, counter);
		ftprtf_putnbr_unsigned(i % 10, counter);
	}
	else
	{
		c = i + 48;
		ftprtf_putchar_fd(c, 1, counter);
	}
}

void	ftprtf_putnbr_hexa(unsigned long number, char const count, int *counter)
{
	if (number >= 16)
	{
		ftprtf_putnbr_hexa(number / 16, count, counter);
		ftprtf_putnbr_hexa(number % 16, count, counter);
	}
	else
	{
		if (number <= 9)
			ftprtf_putchar_fd((number + 48), 1, counter);
		else
		{
			if (count == 'x')
				ftprtf_putchar_fd((number - 10 + 'a'), 1, counter);
			else if (count == 'X')
				ftprtf_putchar_fd((number - 10 + 'A'), 1, counter);
		}
	}
}

void	ftprtf_putpointer(unsigned long pointer, int *counter)
{
	ftprtf_putstr_fd("0x", 1, counter);
	ftprtf_putnbr_hexa(pointer, 'x', counter);
}
