#include "push_swap.h"

void    free_content(void *value)
{
    free(value);
}

void    print_stack(void *content)
{
    int nbr;

    if (!content)
        return ;
    ft_putchar_fd('\t', 1);
    nbr = *((int *)content);
    ft_putnbr_fd(nbr, 1);
    ft_putchar_fd('\n', 1);
}