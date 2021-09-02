#include "../include/push_swap.h"

void	sort_four_continue(int min_index, int min_number, \
	t_stack *stack_a, t_stack *stack_b)
{
	if (min_index == 3)
	{
		reverse_rotate(stack_a, 1);
	}
	else
	{
		while (min_number < min_index)
		{	
			rotate(stack_a, 1);
			min_number++;
		}
	}
	push(stack_a, stack_b);
	sort_three(stack_a);
	push(stack_b, stack_a);
}

void	sort_five_continue(int min_index, int min_number, \
	t_stack *stack_a, t_stack *stack_b)
{
	while (min_number < min_index)
	{	
		rotate(stack_a, 1);
		min_number++;
	}
	push(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push(stack_b, stack_a);
}
