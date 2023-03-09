#include "push_swap.h"

t_node *new_stack(t_node *head, int number)
{
    t_stack *stack;
    t_node *node;


 	stack = (t_node *)malloc(sizeof(t_node)); //alocar memoria do stack

    head->stack = 0; // stack esta vazio
 	stack->node->content = number; // conteudo do stack vai ser um numero
    stack->size = 0;
}