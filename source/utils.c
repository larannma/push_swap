#include "../include/push_swap.h"

void	init_stack(t_list *start_list, t_stack *stack_a, \
	t_stack *stack_b, int size)
{
	stack_a->name = 'a';
	stack_b->name = 'b';
	stack_a->size = size;
	stack_b->size = 0;
	stack_a->begin = start_list;
	stack_b->begin = NULL;
}

void	ft_set_region(t_list *lst)
{
	while (lst)
	{
		lst->region = 1;
		lst = lst->next;
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

int	sorted_or_not(t_main_struct *main_struct)
{
	int	i;

	i = 0;
	while (i < main_struct->size - 1)
	{
		if (main_struct->mas[i] < main_struct->mas[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
