#include "../include/push_swap.h"

void	find_region_continue(t_list *last, t_list *next)
{
	while (next)
	{
		last = next;
		next = next->next;
		if (next->count_true > last->count_true)
		{
			last->region = 0;
			next->region = 0;
		}
		else if (next->count_true == last->count_true)
		{
			last->region = 0;
			next->region = 1;
			ft_set_region(next);
			return ;
		}
		else if (next->count_true < last->count_true)
		{
			last->region = 1;
			next->region = 1;
			ft_set_region(next);
			return ;
		}
	}	
}

void	find_region(t_stack *stack)
{
	t_list	*last;
	t_list	*next;

	if (stack->size == 2 || stack->size == 1)
	{
		stack->begin->region = 0;
		if (stack->size == 2)
			stack->begin->next->region = 1;
		return ;
	}
	next = stack->begin;
	last = NULL;
	find_region_continue(last, next);
}

void	transfer_to_a(t_stack *stack_a, t_list *tmp, t_stack *stack_b)
{
	while (tmp->count_cmds)
	{
		if (tmp->region == 0 && stack_a->begin->region == 0)
		{
			rr_reverse_rotate(stack_a, stack_b);
		}
		else
			rr_rotate(stack_a, stack_b);
	}
	push(stack_b, stack_a);
}

void	put_best(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;
	int		min_cmds;
	int		num;

	min_cmds = 2147483647;
	tmp = stack_b->begin;
	while (tmp)
	{
		if (tmp->count_cmds < min_cmds)
		{
			min_cmds = tmp->count_cmds;
			num = tmp->number;
		}
		tmp = tmp->next;
	}
	tmp = stack_b->begin;
	while (tmp)
	{
		if (tmp->number == num)
		{
			transfer_to_a(stack_a, tmp, stack_b);
			break ;
		}
		tmp = tmp->next;
	}
}
