#include "push_swap.h"

static int	index_node(t_list *stack, int number)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (*((int *)(stack->content)) == number)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}	

void	selection_sort(t_list **stack, int size)
{
	t_list *tmp;
	t_list *tmp2;
	int	hold;
	int	value;
	int	index;
	int	i;
	int	j;

	tmp = *stack;
	tmp2 = *stack;
	i = 0;
	while (i < size)
	{
		index = 0;
		hold = *((int *)(tmp2->content));
		tmp = tmp2;
		j = 0;
		while (j < size - 1)
		{
			// 1. find min + position
			value = *((int *)((tmp->next)->content));
			if (value < hold)
			{
				hold = value;
				index = j + 1;
			}
			tmp = tmp->next;
			j++;
		}
		// 2. rotate A until min is top
		rotate_a(stack);

		// 3. pb
		push_b(stack);

		tmp2 = (tmp2)->next;
		i++;
	}
}

#include <stdio.h>
int main()
{
	int	arr[] = {4, 8, 5};
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	selection_sort(arr, size);
	printf("\n");

	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}