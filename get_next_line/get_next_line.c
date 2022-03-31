/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:11:40 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/31 17:31:12 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*area;

	area = (char *)malloc((count * size) * sizeof(*area));
	if (area == 0)
		return (0);
	ft_bzero(area, count * size);
	return (area);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*a;
	char		*b;
	long		c;
	int			s;

	s = 0;
	if (!a)
		a = (char *)ft_calloc(BUFFER_SIZE + 1);
}
