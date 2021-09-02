#include "../include/push_swap.h"

void	sort_one_element(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;

	tmp_b = min_count_cmds(stack_b);
	tmp_a = compare_difference(stack_a, tmp_b);
	count_cmds(stack_b);
	count_cmds(stack_a);
	find_region(stack_a);
	find_region(stack_b);
	cmds_amount(stack_a, stack_b);
	genius_function_moving(stack_a, stack_b, tmp_a, tmp_b);
	push(stack_b, stack_a);
}

t_list	*find_begin(t_stack *stack)
{
	t_list	*begin;

	begin = stack->begin;
	while (begin)
	{
		if (begin->index == 0)
			return (begin);
		begin = begin->next;
	}
	return (NULL);
}

void	moving_start(t_stack *stack)
{
	t_list	*start;

	start = find_begin(stack);
	if (start->region == 0)
	{
		while (stack->begin->index != 0)
			rotate(stack, 1);
	}
	else
	{
		while (stack->begin->index != 0)
			reverse_rotate(stack, 1);
	}
}

void	multy_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;

	find_true(stack_a);
	foo_max_count(stack_a);
	transfer_to_b(stack_a, stack_b);
	while (stack_b->size > 1)
	{
		tmp_b = min_count_cmds(stack_b);
		tmp_a = compare_difference(stack_a, tmp_b);
		count_cmds(stack_b);
		count_cmds(stack_a);
		find_region(stack_a);
		find_region(stack_b);
		cmds_amount(stack_a, stack_b);
		genius_function_moving(stack_a, stack_b, tmp_a, tmp_b);
		push(stack_b, stack_a);
		clear_flags(stack_a, stack_b);
	}
	sort_one_element(stack_a, stack_b);
	moving_start(stack_a);
}
