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

void	ft_putnbr_fd(int n, int fd, int *counter)
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
		ft_putnbr_fd(i / 10, fd, counter);
		ft_putnbr_fd(i % 10, fd, counter);
	}
	else
	{
		c = i + 48;
		write(fd, &c, 1);
		*counter = *counter + 1;
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *counter)
{
	long	i;
	char	c;

	i = (long)n;
	if (i < 0)
		return ;
	if (i >= 10)
	{
		ft_putnbr_unsigned(i / 10, counter);
		ft_putnbr_unsigned(i % 10, counter);
	}
	else
	{
		c = i + 48;
		ft_putchar_fd(c, 1, counter);
	}
}

void	ft_putnbr_hexa(unsigned long number, char const count, int *counter)
{
	if (number >= 16)
	{
		ft_putnbr_hexa(number / 16, count, counter);
		ft_putnbr_hexa(number % 16, count, counter);
	}
	else
	{
		if (number <= 9)
			ft_putchar_fd((number + 48), 1, counter);
		else
		{
			if (count == 'x')
				ft_putchar_fd((number - 10 + 'a'), 1, counter);
			else if (count == 'X')
				ft_putchar_fd((number - 10 + 'A'), 1, counter);
		}
	}
}

void	ft_putpointer(unsigned long pointer, int *counter)
{
	ft_putstr_fd("0x", 1, counter);
	ft_putnbr_hexa(pointer, 'x', counter);
}
