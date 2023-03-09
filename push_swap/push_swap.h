#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_node
{
    t_node *prevInLine;
    int     content;
    t_node *nextInLine;
}   t_node;

int   swap_a(t_node *head_a);
int rotate_a(t_node *head_a);
int reverse_rotate_a(t_node *head_a);
int push_a(t_node *head_a, t_node *head_b);

int swap_b(t_node *head_b);
int rotate_b(t_node *head_b);
int reverse_rotate_b(t_node *head_b);
int push_b(t_node *head_a, t_node *head_b);

int both_swaps(t_node *head_a, t_node *head_b);
int both_rotates(t_node *head_a, t_node *head_b);
int both_reverse_rotates(t_node *head_a, t_node *head_b);

int stack_swap(t_node *head);
int stack_rotate(t_node *head);
int stack_reverse_rotate(t_node *head);

long	ft_atoi(const char *str);
int length(t_node *head);

int error_checker(int argc, char **argv);
int isNumber(char *number);
int isDuplicate(int argc, char **argv);

#endif
