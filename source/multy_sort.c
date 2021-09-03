#include "../include/push_swap.h"

void	foo_max_count(t_stack *stack_a)
{
	int		max;
	t_list	*max_list;
	t_list	*tmp;

	max = -2147483648;
	tmp = stack_a->begin;
	while (tmp)
	{
		if (tmp->count_true > max)
		{
			max_list = tmp;
			max = tmp->count_true;
		}
		tmp = tmp->next;
	}
	get_new_count_true(max_list, stack_a->begin);
}

void	region_equal(t_stack *stack_a, t_stack *stack_b,
	 t_list *a_lst, t_list *b_lst)
{
	if (a_lst->region == 0)
	{
		if (a_lst->count_true > b_lst->count_true)
			rotate_both_stack(stack_a, stack_b, b_lst->count_true,
				 a_lst->count_true - b_lst->count_true);
		else
			rotate_both_stack(stack_b, stack_a, a_lst->count_true,
				 b_lst->count_true - a_lst->count_true);
	}
	else
	{
		if (a_lst->count_true > b_lst->count_true)
			rev_rotate_both_stack(stack_a, stack_b, b_lst->count_true,
				 a_lst->count_true - b_lst->count_true);
		else
			rev_rotate_both_stack(stack_b, stack_a, a_lst->count_true,
				 b_lst->count_true - a_lst->count_true);
	}
}

void	region_no_equal(t_stack *stack_a, t_stack *stack_b,
	 t_list *a_lst, t_list *b_lst)
{
	if (a_lst->region == 0)
	{
		rotate_one_stack(stack_a, a_lst->count_true);
		rev_rotate_stack(stack_b, b_lst->count_true);
	}
	else
	{
		rotate_one_stack(stack_b, b_lst->count_true);
		rev_rotate_stack(stack_a, a_lst->count_true);
	}
}

void	multy_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;

	(void)stack_b;
	find_true(stack_a);
	foo_max_count(stack_a);
	transfer_to_b(stack_a, stack_b);
	while (stack_b->size > 1)
	{
		count_cmds(stack_b);
		count_cmds(stack_a);
		find_region(stack_a);
		find_region(stack_b);
		cmds_amount(stack_a, stack_b);
		tmp_b = min_count_cmds(stack_b);
		tmp_a = compare_difference(stack_a, tmp_b);
		genius_function_moving(stack_a, stack_b, tmp_a, tmp_b);
		push(stack_b, stack_a);
		clear_flags(stack_a, stack_b);
	}
	sort_one_element(stack_a, stack_b);
	moving_start(stack_a);
}
