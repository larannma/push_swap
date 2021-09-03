#include "../include/push_swap.h"

void	get_index(t_stack *stack)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = stack->begin;
	while (index < ((int)((stack->size / 2) + stack->size % 2)))
	{
		tmp->count_true = index;
		tmp = tmp->next;
		index++;
	}
	if (stack->size % 2)
		index--;
	while (tmp)
	{
		tmp->count_true = index;
		tmp = tmp->next;
		index--;
	}
}

void	count_cmds(t_stack *stack)
{
	get_index(stack);
}
