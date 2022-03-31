/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:56:56 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/31 17:30:05 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*i;

	i = NULL;
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*s3));
	if (!s3)
		return (NULL);
	if (s3 && s1 && s2)
	{
		i = s3;
		while (*s1 != '\0')
		{
			*s3 = (char)*s1;
			s3++;
			s1++;
		}
		while (*s2 != '\0')
		{
			*s3 = (char)*s2;
			s3++;
			s2++;
		}
	}
	*s3 = '\0';
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*st;

	st = (char *)s;
	while (*st != '\0')
	{
		if (*st == (char) c)
			return (st);
		st++;
	}
	if ((char) c == *st)
		return (st);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	e;

	i = 0;
	e = 0;
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && e < len)
		{
			substr[e] = s[i];
			e++;
		}
		i++;
	}
	substr[e] = '\0';
	return (substr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ss;

	ss = (char *)s;
	i = 0;
	while (i < n)
	{
		ss[i] = 0;
		i++;
	}
}
