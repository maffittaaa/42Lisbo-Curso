#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void ft_putstr(char *str)
{
    if (!str)
        write(1, "(null)", 6);
    else
        while (*str != '\0')
            write(1, str++, 1);
}

static void	clean_temp(char *temp)
{
    int	i;

    i = -1;
    while (++i < 31)
        temp[i] = '\0';
}

int	output_index_generator(long long n_l, int neg, char *temp)
{
    int	i;

    clean_temp(temp);
    temp[31] = '\0';
    i = 30;
    while (n_l != 0 && i >= 0)
    {
        temp[i] = "0123456789"[n_l % 10];
        i--;
        n_l = n_l / 10;
    }
    if (neg == 1)
        temp[i] = '-';
    else
        i++;
    return (i);
}



void	ft_putnbr(long n)
{
    long long	n_l;
    int		i;
    char	temp[32];
    int		neg;

    n_l = (long long)n;
    neg = 0;
    if (n_l < 0)
    {
        neg = 1;
        n_l = -n_l;
    }
    if (n_l == 0)
        ft_putstr("0");
    else
    {
        i = 0;
        i = output_index_generator(n_l, neg, temp);
        ft_putstr(&temp[i]);
    }
}


int main(void)
{
    int fd = open("test_no_nl.txt", O_RDONLY);
    //fd = 5000;
    //ft_putstr("fd = %d\n", fd);
    ft_putstr("No \\n\n\n");
    char *c = get_next_line(fd);
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);
    ft_putstr(c);
    free(c);
    ft_putstr("\n\n");
    fd =  open("test.txt", O_RDONLY);
    ft_putstr("With \\n\n\n");
    c = get_next_line(fd);//
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);//
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);//
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);//
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);//
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);//
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);
    ft_putstr(c);
    free(c);
    ft_putstr("\n\n");
    ft_putstr("From stdin\n\n");
    ft_putstr("Type something: ");
    c = get_next_line(0);//
    ft_putstr(c);
    free(c);
    ft_putstr("\n\n");
    ft_putstr("with \\0\n\n");
    fd =  open("test_slash_0.txt", O_RDONLY);
    c = get_next_line(fd);
    ft_putstr(c);
    free(c);
    ft_putstr("  |  ");
    c = get_next_line(fd);
    ft_putstr(c);
    free(c);
    ft_putstr("\n\n");
    ft_putstr("with mixed \\n\n\n");
    fd =  open("test_mixed_nl.txt", O_RDONLY);
    c = get_next_line(fd);
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);
    ft_putstr(c);
    free(c);
    c = get_next_line(fd);
    ft_putstr(c);
    free(c);



}