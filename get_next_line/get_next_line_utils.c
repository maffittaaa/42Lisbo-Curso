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

size_t	ft_strlen(const char *str)
{
    size_t	i;

    i = 0;
    while (str && str[i] != '\0')
    {
        if (str[i] == '\n')
            return (i + 1); // saber a posicao do \0
        i++;
    }
    return (i);
}

char	*ft_strjoin(char *data_reader, char *buffer)
{
    int     a;
    int     b;
    char    *holder;

    a = 0;
    holder = malloc(ft_strlen(data_reader) + ft_strlen(buffer) + 1); //aloca memoria do tamanho do data_reader e do buffer + \0
    if (holder == NULL)
        return (NULL);
    while (data_reader && data_reader[a]) //os bytes que o data_reader leu vao ser guardados no holder para poderem ser passados depois para o buffer;
    {
        holder[a] = data_reader[a];
        a++;
    }
    b = 0;
    while (buffer[b] != '\0')
    {
        holder[a] = buffer[b];
        a++;
        if (buffer[b++] == '\n')// se for \n da break para o programa perceber que encontrou o fim da linha;
            break ;

    }
    holder[a] = '\0';
    if (data_reader)
        free(data_reader);
    return (holder);
}

int     buffer_cleaner(char *buffer)
{
    int a;
    int b;
    int check;

    a = -1;
    b = -1;
    check = 0;
   while (buffer[++a])
    {
        if (check)
            buffer[++b] = buffer[a];
        if (buffer[a] == '\n')
            check = 1;
        buffer[a] = 0;
    }
    return (check);
}