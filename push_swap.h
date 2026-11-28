#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "Libft/libft.h"

#include <stdlib.h>

/******************** OPERATIONS *********************************/
void    swap_a(t_list *first_node);
void    swap_b(t_list *first_node);
void    swap_ab(t_list *stack_a, t_list *stack_b,
    void (*swap_a)(t_list *), void (*swap_b)(t_list *));

void    push_a(t_list **stack_a, t_list **stack_b);
void    push_b(t_list **stack_a, t_list **stack_b);

void    rotate_a(t_list **first);
void    rotate_b(t_list **first);
void    rotate_ab(t_list **stack_a, t_list **stack_b,
    void (*rotate_a)(t_list **), void (*rotate_b)(t_list **));

void    reverse_rotate_a(t_list **first);
void    reverse_rotate_b(t_list **stack_b);
void    reverse_rotate_ab(t_list **stack_a, t_list **stack_b,
    void (*reverse_rotate_a)(t_list **), void (*reverse_rotate_b)(t_list **));
/*******************************************************************/

void    free_content(void *value);
void    print_stack(void *content);

#endif