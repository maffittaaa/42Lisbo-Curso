# include "push_swap.h"

unsigned int    absolute(int number)
{
    int x;

    x = number;
    if (number < 0)
        x = -number;
    return (x);
}

void find_best_move(t_node **head_a, t_node **head_b)
{
    printf("4");
    t_node *tmp_b;
    long long int max_moves;
    int moves_a;
    int moves_b;
    int i;
    int k;
    int tmp_i;
    int number;

    max_moves = __LONG_LONG_MAX__;
    i = 0;
    k = 0;
    number = 0;
    tmp_b = *head_b;
    tmp_i = i;
    while (tmp_b->nextInLine != *head_b)
    {
        k = get_best_friend(head_a, number);
        if (k > (length(head_a) / 2))
            k = (length(head_a) - k) * (-1);
        if (i > (length(head_b) / 2))
            tmp_i = (length(head_b) - i) * (-1);
        if ((absolute(tmp_i) + absolute(k)) < max_moves)
        {
            max_moves = absolute(tmp_i) + absolute(k);
            moves_a = k;
            moves_b = tmp_i;
        }
    }
    while (moves_b > 0)
    {
        reverse_rotate_b(head_b);
        moves_b--;
    }
    while (moves_b < 0)
    {
        rotate_b(head_b);
        moves_b++;
    }
    while (moves_a > 0)
    {
        reverse_rotate_a(head_a);
        moves_a--;
    }
    while (moves_a > 0)
    {
        reverse_rotate_a(head_a);
        moves_a++;
    }
    push_a(head_a, head_b);
}

