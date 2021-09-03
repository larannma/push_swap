#include "../include/push_swap.h"

void	swap(t_stack *stack, int flag)
{
	t_list	*old_first;
	t_list	*old_second;
	t_list	*old_third;

	old_first = stack->begin;
	old_second = old_first->next;
	old_third = old_second->next;
	stack->begin = old_second;
	(stack->begin)->next = old_first;
	old_first->next = old_third;
	if (flag)
	{
		ft_putstr_fd("s", 1);
		write(1, &stack->name, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ss_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_putstr_fd("ss\n", 1);
}
