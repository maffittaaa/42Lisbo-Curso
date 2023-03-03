#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "push_swap.h"
//#include "libft.h"

struct node
{
    int ref;
    struct node *nextInLine;
};

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

struct node *last = NULL; // pointer para o ultimo node na lista

int   swap_a(t_n *head)
{
    printf("sa\n");
    t_n temp;
    temp = *head;
    head->nextInLine = head->nextInLine->nextInLine;
    temp.nextInLine->nextInLine = head;
}

int main()
{
    swap_a(10);
    swap_a(20);

    return (0);
}



//    if (last == NULL) // se o novo node for o unico na lista
//    {
//        temp->ref = data;
//        temp->nextInLine = temp;
//        last = temp;
//    }
//    else //se o ultimo node tiver a referencia do novo node e o novo node tiver a referencia do anterior primeiro node
//    {
//        temp->ref = data;
//        temp->nextInLine = last->nextInLine;
//        last ->nextInLine = temp; // ultimo node tem a referencia do novo node temp
//    }