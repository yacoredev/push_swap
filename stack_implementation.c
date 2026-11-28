#include "push_swap.h"
#include "Libft/libft.h"
#include <stdio.h>

static t_list   *creat_fill_stack(t_list  *stack_a, int argc, char **argv)
{
    t_list  *node;
    int     *content;
    int     i;

    i = 1;
    while (i < argc)
    {
        content = malloc(sizeof(int));
        if (!content)
            return (NULL);
        *content = ft_atoi(argv[i]);
        node = ft_lstnew(content);
        if (!node)
            return (NULL);
        ft_lstadd_back(&stack_a, node);
        i++;
    }
    return (stack_a);
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    size_t  size;

    if (argc > 1)
    {
        stack_a = creat_fill_stack(NULL, argc, argv);
        if (!stack_a)
            return (1);
        stack_b = NULL;

        // swap_a(stack_a);
        // swap_b(stack_b);
        // size = stack_size(stack_a);
        
        push_b(&stack_a, &stack_b);
        push_b(&stack_a, &stack_b);
        // push_b(&stack_a, &stack_b);
        // push_a(&stack_a, &stack_b);
        // swap_b(stack_b);
        // swap_ab(stack_a, stack_b, swap_a, swap_b);

        // rotate_ab(&stack_a, &stack_b, rotate_a, rotate_b);

        // rotate_b(&stack_b);
        // rotate_a(&stack_a);
        // reverse_rotate_a(&stack_a);
        // reverse_rotate_b(&stack_b);
        reverse_rotate_ab(&stack_a, &stack_b, reverse_rotate_a, reverse_rotate_b);

        ft_putstr_fd("\n-----STACK A-----\n", 1);
        ft_lstiter(stack_a, print_stack);
        size = ft_lstsize(stack_a);
        printf("size of stack: %zu\n", size);
        ft_putstr_fd("-----------------\n", 1);
        

        ft_putstr_fd("\n-----STACK B-----\n", 1);
        ft_lstiter(stack_b, print_stack);
        size = ft_lstsize(stack_b);
        printf("size of stack: %zu\n", size);
        ft_putstr_fd("-----------------\n", 1);


        ft_lstclear(&stack_a, free_content);
    }
    else
        ft_putstr_fd("Wrong number of arguments\n", 1);
}