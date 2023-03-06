#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_node
{
    int ref;
    struct node *nextInLine;
} t_node;

