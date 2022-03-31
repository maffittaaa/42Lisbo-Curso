/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:09:05 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/31 17:30:01 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif
