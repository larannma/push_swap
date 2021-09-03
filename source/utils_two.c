#include "../include/push_swap.h"

void	genius_function_moving(t_stack *stack_a, t_stack *stack_b,
	 t_list *a_lst, t_list *b_lst)
{
	if (a_lst->region == b_lst->region)
		region_equal(stack_a, stack_b, a_lst, b_lst);
	else
		region_no_equal(stack_a, stack_b, a_lst, b_lst);
}

t_list	*min_count_cmds(t_stack *stack_b)
{
	t_list	*tmp;
	int		min_cmds;
	t_list	*min_list;

	min_cmds = 2147483647;
	tmp = stack_b->begin;
	while (tmp)
	{
		if (tmp->count_cmds <= min_cmds)
		{
			min_cmds = tmp->count_cmds;
			min_list = tmp;
		}
		tmp = tmp->next;
	}
	return (min_list);
}

void	find_true(t_stack *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->begin;
	while (tmp)
	{
		count_true(tmp, stack_a->begin);
		tmp = tmp->next;
	}
}

void	clear_flags(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stack_a->begin;
	tmp_b = stack_b->begin;
	while (tmp_a)
	{
		tmp_a->count_cmds = 0;
		tmp_a->count_true = 0;
		tmp_a->region = 0;
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		tmp_b->count_cmds = 0;
		tmp_b->count_true = 0;
		tmp_b->region = 0;
		tmp_b = tmp_b->next;
	}
}

void	get_new_count_true(t_list *tmp, t_list *begin)
{
	t_list	*dup;
	int		markup_head;

	dup = tmp;
	markup_head = tmp->number;
	tmp->count_true = 1;
	if (tmp->next == NULL)
		tmp = begin;
	else
		tmp = tmp->next;
	while (tmp->number != dup->number)
	{
		if (markup_head < tmp->number)
		{
			tmp->count_true = 1;
			markup_head = tmp->number;
		}
		else
			tmp->count_true = 0;
		if (tmp->next == NULL)
			tmp = begin;
		else
			tmp = tmp->next;
	}
}
