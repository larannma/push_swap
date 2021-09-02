#include "../include/push_swap.h"

void	region_equal(t_stack *stack_a, t_stack *stack_b, t_list *a_lst, \
	t_list *b_lst)
{
	if (a_lst->region == 0)
	{
		if (a_lst->count_true > b_lst->count_true)
			rotate_both_stack(stack_a, stack_b, b_lst->count_true, \
				a_lst->count_true - b_lst->count_true);
		else
			rotate_both_stack(stack_b, stack_a, a_lst->count_true, \
				b_lst->count_true - a_lst->count_true);
	}
	else
	{
		if (a_lst->count_true > b_lst->count_true)
			rev_rotate_both_stack(stack_a, stack_b, b_lst->count_true, \
				a_lst->count_true - b_lst->count_true);
		else
			rev_rotate_both_stack(stack_b, stack_a, a_lst->count_true, \
				b_lst->count_true - a_lst->count_true);
	}
}

void	region_no_equal(t_stack *stack_a, t_stack *stack_b, t_list *a_lst, \
	t_list *b_lst)
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

void	genius_function_moving(t_stack *stack_a, t_stack *stack_b, \
	t_list *a_lst, t_list *b_lst)
{
	if (a_lst->region == b_lst->region)
		region_equal(stack_a, stack_b, a_lst, b_lst);
	else
		region_no_equal(stack_a, stack_b, a_lst, b_lst);
}
