#include "../include/push_swap.h"

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
	while(tmp->number != dup->number)
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

void get_new_count_true(t_list *tmp, t_list *begin)
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
	while(tmp->number != dup->number)
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

	max = -2147483648;
	t_list	*tmp;

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

void	multy_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	find_true(stack_a);
	foo_max_count(stack_a);
	transfer_to_b(stack_a, stack_b);
	// print_list(stack_a);
}
