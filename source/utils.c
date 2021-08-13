#include "../include/push_swap.h"

void	init_stack(t_list *start_list, t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->name = 'a';
	stack_b->name = 'b';
	stack_a->size = size;
	stack_b->size = 0;
	stack_a->begin = start_list;
	stack_b->begin = NULL;
}