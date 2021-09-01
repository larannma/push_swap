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

	if (stack->size == 2 || stack->size == 1)
	{
		
		stack->begin->region = 0;
		if (stack->size == 2)
			stack->begin->next->region = 1;
		return ;
	}
	
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

t_list	*compare_difference(t_stack *stack_a, t_list *lst)
{
	t_list	*tmp_a;
	t_list	*lst_save;
	int		save_a;
	int		min;

	min = 2147483647;
	tmp_a = stack_a->begin;
	while (tmp_a)
	{
		if(tmp_a->index - lst->index > 0 && tmp_a->index - lst->index < min)
		{
			min = tmp_a->index - lst->index;
			save_a = tmp_a->count_true;
			lst_save = tmp_a;
		}
		tmp_a = tmp_a->next;
	}
	lst->count_cmds = lst->count_true + save_a;
	return (lst_save);
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
	int	min_cmds;

	min_cmds = 2147483647;
	tmp = stack_b->begin;
	while (tmp)
	{
		// printf("tut\n");
		// find_region(stack_a);
		// find_region(stack_b);
		compare_difference(stack_a, tmp);
		//put_best(stack_a, stack_b);
		// printf("stack b number: %4d || max commands: %4d\n", tmp->number, tmp->count_cmds);
		tmp = tmp->next;
	}
}