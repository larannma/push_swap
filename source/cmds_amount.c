#include "../include/push_swap.h"

void	ft_set_region(t_list *lst)
{
	while (lst)
	{
		lst->region = 1;
		lst = lst->next;
	}
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

void	cmds_amount(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;
	int		min_cmds;

	min_cmds = 2147483647;
	tmp = stack_b->begin;
	while (tmp)
	{
		compare_difference(stack_a, tmp);
		tmp = tmp->next;
	}
}
