/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functionspt2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:47:33 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/16 16:02:42 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd, int *counter)
{
	write(fd, &c, 1);
	*counter = *counter + 1;
}

void	ft_putstr_fd(char *s, int fd, int *counter)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd, counter);
			i++;
		}
	}
	else
		ft_putstr_fd("(null)", 1, counter);
}
