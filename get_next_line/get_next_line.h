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

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *data_reader, char *buffer);
void	*ft_calloc(size_t count, size_t size);
int     buffer_cleaner(char *buffer);
char	*get_next_line(int fd);

#endif
