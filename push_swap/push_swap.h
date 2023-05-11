/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:18:46 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:18:48 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define INT_MAX  __INT_MAX__
# define INT_MIN -2147483648

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*previnline;
	struct s_node	*nextinline;
}	t_node;

void			swap_a(t_node **head_a);
void			rotate_a(t_node **head_a);
void			reverse_rotate_a(t_node **head_a);
void			push_a(t_node **head_b, t_node **head_a);
void			complement_to_push_a(t_node **head_a, t_node *tmp);
void			swap_b(t_node **head_b);
void			rotate_b(t_node **head_b);
void			reverse_rotate_b(t_node **head_b);
void			push_b(t_node **head_a, t_node **head_b);
void			complement_to_push_b(t_node **head_b, t_node *tmp);
void			both_swaps(t_node **head);
void			both_rotates(t_node **head);
void			both_reverse_rotates(t_node **head);
void			stack_swap(t_node **head);
void			stack_rotate(t_node **head);
void			stack_reverse_rotate(t_node **head);
void			three_numbers(t_node **head);
void			five_numbers(t_node **head_a, t_node **head_b, int len);
void			hundred_numbers(t_node **head_a, t_node **head_b);
void			lstnew(t_node **head, int number);
int				lstsize(t_node **head);
void			lstiter(t_node **head, void (*f)(int *));
void			lstiter_node(t_node **head, void (*f)(void *));
long			ft_atol(const char *str);
int				length(t_node **head);
int				error_checker(int argc, char **argv, t_node **head_a);
int				isnumber(char *number);
int				isduplicate(t_node **head);
int				find_max(t_node **head);
int				find_min(t_node **head);
void			print_integer(int *content);
float			mean_of_nodes(t_node **head);
void			ten_or_more(t_node **head_a, t_node **head_b);
int				get_best_friend(t_node **head_a, int number);
void			find_best_move(t_node **head_a, t_node **head_b,
					int *moves_a, int *moves_b);
void			rest_of_cost_to_top(t_node **head_a, t_node **head_b,
					int *moves_a, int *moves_b);
unsigned int	absolute(int number);
void			min_up(t_node **head_a);
int				is_sorted(t_node **head);

#endif
