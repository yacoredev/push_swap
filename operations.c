#include "push_swap.h"

void    swap_a(t_list *first_node)
{
    t_list  *next_node;
    void    *tmp;

    if (!first_node)
        return ;
    if (first_node->next == NULL)
        return ;
    next_node = first_node->next;

    tmp = first_node->content;
    first_node->content = next_node->content;
    next_node->content = tmp; 
}

void    swap_b(t_list *first_node)
{
    swap_a(first_node);
}

void    swap_ab(t_list *stack_a, t_list *stack_b,
    void (*swap_a)(t_list *), void (*swap_b)(t_list *))
{
    swap_a(stack_a);
    swap_b(stack_b);
}

void    push_a(t_list **stack_a, t_list **stack_b)
{
    t_list  *next_node;

    next_node = (*stack_b)->next;

    (*stack_b)->next = *stack_a;
    *stack_a = *stack_b;
    *stack_b = next_node;
}
void    push_b(t_list **stack_a, t_list **stack_b)
{
    push_a(stack_b, stack_a);
}

void    rotate_a(t_list **first)
{
    t_list  *last;
    t_list  *tmp;

    if (!*first || !((*first)->next))
        return ;
    tmp = *first;
    last = ft_lstlast(*first);
    last->next = *first;
    *first = (*first)->next;
    tmp->next = NULL;
}

void    rotate_b(t_list **first)
{
    rotate_a(first);
}

void    rotate_ab(t_list **stack_a, t_list **stack_b,
    void (*rotate_a)(t_list **), void (*rotate_b)(t_list **))
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}

void    reverse_rotate_a(t_list **first)
{
    t_list  *prev_last;
    t_list  *last;
    t_list  *tmp;

    if (!*first || !((*first)->next))
        return ;
    tmp = *first;
    while ((tmp->next)->next)
    {
        tmp = tmp->next;
    }
    prev_last = tmp;
    last = tmp->next;
    last->next = *first;
    tmp->next = NULL;
    *first = last;
}

void    reverse_rotate_b(t_list **stack_b)
{
    reverse_rotate_a(stack_b);
}

void    reverse_rotate_ab(t_list **stack_a, t_list **stack_b,
    void (*reverse_rotate_a)(t_list **), void (*reverse_rotate_b)(t_list **))
{
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
}