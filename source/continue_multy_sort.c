#include "../include/push_swap.h"

int		ft_count_zero(t_stack *stack_a)
{
	t_list	*tmp;
	int	zero;


	tmp = stack_a->begin;
	zero = 0;
	while (tmp)
	{
		if (tmp->count_true == 0)
			zero++;
		tmp = tmp->next;
	}
	return (zero);
}

int		ft_find_position_zero(t_stack *stack_a)
{	
	t_list	*tmp;
	int	pos;

	tmp = stack_a->begin;
	pos = 1;
	while (tmp)
	{
		if (tmp->count_true == 0) 
			break ;
			tmp = tmp->next;
		pos++;
	}
	return (pos);
}

void	transfer_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	count_zero;
	int	pos;

	(void)stack_b;
	count_zero = ft_count_zero(stack_a);
	// print_list(stack_a);
	while (count_zero)
	{
		if (stack_a->begin->count_true == 0)
		{
			push(stack_a, stack_b);
			count_zero--;
			continue ;
		}
		pos = ft_find_position_zero(stack_a);
		if (pos > (int)(stack_a->size / 2))
			reverse_rotate(stack_a, 1);
		else
			rotate(stack_a, 1);
	}
}