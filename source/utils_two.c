#include "../include/push_swap.h"

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

void	count_true(t_list *tmp, t_list *begin)
{
	t_list	*dup;
	int		markup_head;

	dup = tmp;
	markup_head = tmp->number;
	dup->count_true++;
	if (tmp->next == NULL)
		tmp = begin;
	else
		tmp = tmp->next;
	while (tmp->number != dup->number)
	{
		if (markup_head < tmp->number)
		{
			dup->count_true++;
			markup_head = tmp->number;
		}
		if (tmp->next == NULL)
			tmp = begin;
		else
			tmp = tmp->next;
	}
}
