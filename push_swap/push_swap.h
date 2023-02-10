#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_stack
{
    int     *array;
    size_t  size;
    size_t  max_size;
}t_stack;

typedef struct s_operations
{
    char    *line;
    void    *next;
    void    *prev;
}t_operations;


typedef struct s_program
{
    t_stack stack_a;
    t_stack stack_b;
    t_operations *operat;
}t_program;