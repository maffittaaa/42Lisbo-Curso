/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:38:52 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/02 12:55:33 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	c;

	i = (long)n;
	if (i < 0)
	{
		write(fd, "-", 1);
		i *= -1;
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	else
	{	
		c = i + 48;
		write(fd, &c, 1);
	}
}
/*
int main()
{
	ft_putnbr_fd(-5, 1);
}*/
