#include "../include/push_swap.h"

void	find_region_continue(t_stack *stack, t_list *last, t_list *next)
{
	next = stack->begin;
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

	last = NULL;
	next = NULL;
	if (stack->size == 2 || stack->size == 1)
	{
		stack->begin->region = 0;
		if (stack->size == 2)
			stack->begin->next->region = 1;
		return ;
	}
	find_region_continue(stack, last, next);
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
		if (tmp_a->index - lst->index > 0 && tmp_a->index - lst->index < min)
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

int	sorted_or_not(t_main_struct *main_struct)
{
	int	i;

	i = 0;
	while (i < main_struct->size - 1)
	{
		if (main_struct->mas[i] < main_struct->mas[i + 1])
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

void	sort_two(t_stack *stack_a)
{
	swap(stack_a, 1);
}
