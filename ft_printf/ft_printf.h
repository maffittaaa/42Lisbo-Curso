/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:40:07 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/03/16 15:59:50 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_putchar_fd(char c, int fd, int *counter);
void	ft_putnbr_fd(int n, int fd, int *counter);
void	ft_putnbr_hexa(unsigned long number, char const count,
			int *counter);
int		ft_printf(const char *string, ...);
void	ft_putpointer(unsigned long pointer, int *counter);
void	ft_putnbr_unsigned(unsigned int n, int *counter);
void	ft_putstr_fd(char *s, int fd, int *counter);

#endif
