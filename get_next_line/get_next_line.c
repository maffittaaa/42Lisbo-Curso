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

char	*get_next_line(int fd)
{
    int             answer;
    static char     buffer[BUFFER_SIZE + 1];
    char            *data_reader;

    data_reader = 0;
    if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    answer = 1;
    while (answer > 0)
    {
        if (!*buffer)
            answer = read(fd, buffer, BUFFER_SIZE);
        if (answer > 0)
            data_reader = ft_strjoin(data_reader, buffer);
        if (buffer_cleaner(buffer) || answer < 1)
            break ;
    }
    return (data_reader);
}







