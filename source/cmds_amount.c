#include "../include/push_swap.h"

void	ft_set_region(t_list *lst)
{
	while (lst)
	{
		lst->region = 1;
		lst = lst->next;
	}
}

void	find_region(t_stack *stack)
{
	t_list	*last;
	t_list	*next;

	next = stack->begin;
	while (next)
	{
		last = next;
		next =  next->next;
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

int		compare_difference(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		min;

	min = 2147483647;
	tmp_a = stack_a->begin;
	tmp_b = stack_b->begin;
	while (tmp_b)
	{
		while (tmp_a)
		{
			if (tmp_a->index - tmp_b->index < min && tmp_a->index - tmp_b->index > -1)
				min - tmp_a->index - tmp_b->index;
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
	return (min);
}

void	cmds_amount(t_stack *stack_a, t_stack *stack_b)
{
	// find_region(stack_a);
	// find_region(stack_b);
	// print_list(stack_a);
	// print_list(stack_b);

	compare_difference(stack_a, stack_b);
}