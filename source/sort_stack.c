#include "../include/push_swap.h"

void	sort_two(t_stack *stack_a)
{
	swap(stack_a, 1);
	// print_list(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	if (stack_a->begin->number > stack_a->begin->next->next->number && \
		stack_a->begin->number < stack_a->begin->next->number)
		reverse_rotate(stack_a, 1);
	else if (stack_a->begin->number < stack_a->begin->next->next->number && \
		stack_a->begin->number > stack_a->begin->next->number)
			swap(stack_a, 1);
	else if (stack_a->begin->number > stack_a->begin->next->number && \
		stack_a->begin->next->number > stack_a->begin->next->next->number)
		{
			swap(stack_a, 1);
			reverse_rotate(stack_a, 1);
		}
	else if (stack_a->begin->number > stack_a->begin->next->number && \
		stack_a->begin->next->number < stack_a->begin->next->next->number)
		rotate(stack_a, 1);
	else if (stack_a->begin->number < stack_a->begin->next->number && \
		stack_a->begin->next->number > stack_a->begin->next->next->number)
		{
			swap(stack_a, 1);
			rotate(stack_a, 1);
		}
	// print_list(stack_a);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_number;
	t_list	*head;
	int min_index;
	int	i = 0;

	head = stack_a->begin;
	min_number = INT_MAX;
	while (head)
	{
		if (head->number < min_number)
		{
			min_number = head->number;
			min_index = i;
		}
		i++;
		head = head->next;
	}
	min_number = 0;
	if (min_index == 3)
	{
		reverse_rotate(stack_a, 1);
	}
	else 
	{
		while(min_number < min_index)
		{	
			rotate(stack_a, 1);
			min_number++;
		}
	}
	push(stack_a, stack_b);
	sort_three(stack_a);
	push(stack_b, stack_a);
	// print_list(stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_number;
	t_list	*head;
	int min_index;
	int	i = 0;

	head = stack_a->begin;
	min_number = INT_MAX;
	while (head)
	{
		if (head->number < min_number)
		{
			min_number = head->number;
			min_index = i;
		}
		i++;
		head = head->next;
	}
	min_number = 0;
	while(min_number < min_index)
	{	
		rotate(stack_a, 1);
		min_number++;
	}
	push(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push(stack_b, stack_a);
	// print_list(stack_a);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{


	// if (stack_a->size == 2)
	// 	sort_two(stack_a);
	// if (stack_a->size == 3)
	// 	sort_three(stack_a);
	// if (stack_a->size == 4)
	// 	sort_four(stack_a, stack_b);
	// if (stack_a->size == 5)
	// 	sort_five(stack_a, stack_b);
	// if (stack_a->size > 5)
		multy_sort(stack_a, stack_b);
}