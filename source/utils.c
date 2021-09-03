#include "../include/push_swap.h"

void	init_stack(t_list *start_list, t_stack *stack_a,
	 t_stack *stack_b, int size)
{
	stack_a->name = 'a';
	stack_b->name = 'b';
	stack_a->size = size;
	stack_b->size = 0;
	stack_a->begin = start_list;
	stack_b->begin = NULL;
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
