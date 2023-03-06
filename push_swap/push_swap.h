#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_node
{
    t_node *prevInLine;
    int data;
    t_node *nextInLine;
}   t_node;
