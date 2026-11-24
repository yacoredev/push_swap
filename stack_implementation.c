#include "push_swap.h"

static t_stack *stack_new()
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = 0;
    node->next = NULL;
    return (node);
}

static void stack_add_back(t_stack **head, t_stack *node)
{
    if (!(*head))
    {
        (*head) = node;
        return ;
    }
    while ((*head)->next)
        (*head) = (*head)->next;
    (*head)->next = node;
}

static size_t  stack_size(t_stack head)
{
    size_t count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

static t_stack  stack_last(t_stack *head)
{
    while (head->next)
        head = head->next;
    return (head);
}

static void stack_clear(t_stack **head)
{
    while (head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    head = NULL;
}

int main(int argc, char **argv)
{
    t_stack *head = NULL;
    t_stack *node;
    size_t  size;

    // stack_new() — create node.
    node = stack_new();

    // stack_add_back() — add node.
    stack_add_back(&head, node);

    // stack_size() — count nodes.
    size = stack_size(head);

    // stack_last() — get last node.
    node = stack_last(head);

    // stack_clear() — free stack.
    stack_clear(&head);
}