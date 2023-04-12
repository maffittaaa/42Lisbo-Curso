#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_node
{
    int     content;
    int     index;
    struct  s_node *prevInLine;
    struct  s_node *nextInLine;
}   t_node;

void    swap_a(t_node **head_a);
void    rotate_a(t_node **head_a);
void    reverse_rotate_a(t_node **head_a);
void    push_a(t_node **head_a, t_node **head_b);

void    swap_b(t_node **head_b);
void    rotate_b(t_node **head_b);
void    reverse_rotate_b(t_node **head_b);
void    push_b(t_node **head_a, t_node **head_b);

void    both_swaps(t_node **head);
void    both_rotates(t_node **head);
void    both_reverse_rotates(t_node **head);

void    stack_swap(t_node **head);
void    stack_rotate(t_node **head);
void    stack_reverse_rotate(t_node **head);

void    three_numbers(t_node **head);
void    five_numbers(t_node **head_a, t_node **head_b);
void    hundred_numbers(t_node **head_a, t_node **head_b);

void    lstnew(t_node **head, int number);
int     lstsize(t_node **head);
void    lstiter(t_node **head, void (*f)(int *));

long	ft_atol(const char *str);
int     length(t_node **head);
int	    ft_strcmp(char *s1, char *s2);

int     error_checker(int argc, char **argv, t_node **head_a);
int     isNumber(char *number);
int     isDuplicate(int argc, char **argv);
int     find_max(t_node **head);
int     find_min(t_node **head);

void    pop(t_node **head);
void    push(t_node **head, int num);
void    print_integer(int *content);

#endif
