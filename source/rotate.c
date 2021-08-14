#include "../include/push_swap.h"

t_list     *get_pointer(t_stack *stack1, int flag)
{
    t_list  *stack;

    stack = stack1->begin;

	if (flag)
	{
		while (stack->next->next)
		{
			stack = stack->next;
		}
		return stack;
    }
    while (stack->next)
    {
        stack = stack->next;
    }
    return stack;
}

void    rotate(t_stack *stack, int flag)
{
    t_list  *old_second;
    t_list  *tmp;

    old_second = stack->begin->next;
    tmp = get_pointer(stack, 0);
    tmp->next = stack->begin;
    tmp->next->next = NULL;
    stack->begin = old_second;
	if (flag)
		printf("r%c\n", stack->name);
}

void	rr_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	printf("rr\n");
}

void	reverse_rotate(t_stack *stack, int flag)
{
	t_list	*old_begin;
	t_list	*old_end;
	t_list	*new_end;



	old_end = get_pointer(stack, 0);
	new_end = get_pointer(stack, 1);
	old_begin = stack->begin;
	stack->begin = old_end;
	stack->begin->next = old_begin;
	new_end->next = NULL;
	old_end = new_end;
	if (flag)
		printf("rr%c\n", stack->name);
}

void	rr_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	printf("rrr\n");
}