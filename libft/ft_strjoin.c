/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:38:41 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/03 18:33:28 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

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
/*
int main()
{
	char * s = ft_strjoin("tripouille", "42");

	if (!strcmp(s, "tripouille42"))
		printf("FUCK!\n");
	if (strlen("tripouille") + strlen("42") + 1)
		printf("OH NO!\n");

	s = ft_strjoin("", "42");
	if (!strcmp(s, "42"))
		printf("IT IS WHAT IS IS!\n");
	if (strlen("42") + strlen("") + 1)
		printf("WIND!\n");

	s = ft_strjoin("", "");
	if (!strcmp(s, ""))
		printf("DONT KNOW!\n");
	if (strlen("") + strlen("") + 1)
		printf("WITHOUT ANY IDEAS\n");
}*/
