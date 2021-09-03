#include "../include/push_swap.h"

void	rotate_both_stack(t_stack *stack_1, t_stack *stack_2,
	 int both, int first)
{
	while (both--)
		rr_rotate(stack_1, stack_2);
	while (first--)
		rotate(stack_1, 1);
}

void	rev_rotate_both_stack(t_stack *stack_1, t_stack *stack_2,
	int both, int first)
{
	while (both--)
		rr_reverse_rotate(stack_1, stack_2);
	while (first--)
		reverse_rotate(stack_1, 1);
}

void	rotate_one_stack(t_stack *stack, int count)
{
	while (count--)
		rotate(stack, 1);
}

void	rev_rotate_stack(t_stack *stack, int count)
{
	while (count--)
		reverse_rotate(stack, 1);
}
