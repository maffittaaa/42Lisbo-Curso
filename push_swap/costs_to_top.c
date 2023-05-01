# include "push_swap.h"
#include <limits.h>

unsigned int    absolute(int number)
{
    if (number < 0)
        return (-number);
    return (number);
}

void find_best_move(t_node **head_a, t_node **head_b)
{
    t_node *tmp_b;
    unsigned int max_moves;
    int moves_a;
    int moves_b;
    int i;
    int k;
    int tmp_i;

    max_moves = INT_MAX;
    i = 0;
    k = 0;
    tmp_b = *head_b;
    printf("\nB\n");
    lstiter(head_b, print_integer);
    while (i < length(head_b))
    {
        tmp_i = i;
        k = get_best_friend(head_a, tmp_b->content);
        if (k > length(head_a) / 2)
            k = (length(head_a) - k ) * (-1);
        if (i > length(head_b) / 2)
            tmp_i = (length(head_b) - i) * (-1);
        printf("k = %d, tmp_i = %d\n", k, tmp_i);
        if ((absolute(tmp_i) + absolute(k)) < max_moves)
        {
            max_moves = absolute(tmp_i) + absolute(k);
            moves_a = k;
            moves_b = tmp_i;
        }
        i++;
        tmp_b = tmp_b->nextInLine;
    }
    printf("moves_a = %d, moves_b = %d\n", moves_a, moves_b);

    while (moves_b < 0)
    {
        reverse_rotate_b(head_b);
        moves_b++;
    }
    while (moves_b > 0)
    {
        rotate_b(head_b);
        moves_b--;
    }
    while (moves_a > 0)
    {
        rotate_a(head_a);
        moves_a--;
    }
    while (moves_a < 0)
    {
        reverse_rotate_a(head_a);
        moves_a++;
    }
    push_a(head_b, head_a);
    printf("\nA\n");
    lstiter(head_a, print_integer);
}

