#include "../include/push_swap.h"

void	count_true(t_list *tmp, t_list *begin)
{
	t_list	*dup;
	int		markup_head;

	dup = tmp;
	markup_head = tmp->number;
	dup->count_true++;
	if (tmp->next == NULL)
		tmp = begin;
	else
		tmp = tmp->next;
	while(tmp->number != dup->number)
	{
		if (markup_head < tmp->number)
		{
			dup->count_true++;
			markup_head = tmp->number;
		}
		if (tmp->next == NULL)
			tmp = begin;
		else
			tmp = tmp->next;
	}
}

void	find_true(t_stack *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->begin;
	while (tmp)
	{
		count_true(tmp, stack_a->begin);
		tmp = tmp->next;
	}
}

void get_new_count_true(t_list *tmp, t_list *begin)
{
	t_list	*dup;
	int		markup_head;

	dup = tmp;
	markup_head = tmp->number;
	tmp->count_true = 1;
	if (tmp->next == NULL)
		tmp = begin;
	else
		tmp = tmp->next;
	while(tmp->number != dup->number)
	{
		if (markup_head < tmp->number)
		{
			tmp->count_true = 1;
			markup_head = tmp->number;
		}
		else
			tmp->count_true = 0;
		if (tmp->next == NULL)
			tmp = begin;
		else
			tmp = tmp->next;
	}
}

void	foo_max_count(t_stack *stack_a)
{
	int		max;
	t_list	*max_list;

	max = -2147483648;
	t_list	*tmp;

	tmp = stack_a->begin;
	while (tmp)
	{
		if (tmp->count_true > max)
		{
			max_list = tmp;
			max = tmp->count_true;
		}
		tmp = tmp->next;
	}
	get_new_count_true(max_list, stack_a->begin);
}

t_list *min_count_cmds(t_stack *stack_b)
{
	t_list	*tmp;
	int		min_cmds;
	t_list	*min_list;

	min_cmds = 2147483647;
	tmp = stack_b->begin;
	while (tmp)
	{
		if (tmp->count_cmds <= min_cmds)
		{
			min_cmds = tmp->count_cmds;
			min_list = tmp;
		}
		tmp = tmp->next;
	}
	return (min_list);
}

void	rotate_both_stack(t_stack *stack_1, t_stack *stack_2, int both, int first)
{
	while(both--)
		rr_rotate(stack_1, stack_2);
	while(first--)
		rotate(stack_1, 1);
}

void	rev_rotate_both_stack(t_stack *stack_1, t_stack *stack_2, int both, int first)
{
	while(both--)
		rr_reverse_rotate(stack_1, stack_2);
	while(first--)
		reverse_rotate(stack_1, 1);
}

void	rotate_one_stack(t_stack *stack, int count)
{
	while(count--)
		rotate(stack, 1);
}

void	rev_rotate_stack(t_stack *stack, int count)
{
	while(count--)
		reverse_rotate(stack, 1);
}



void	region_equal(t_stack *stack_a, t_stack *stack_b, t_list *a_lst, t_list *b_lst)
{
	if (a_lst->region == 0)
	{
		if (a_lst->count_true > b_lst->count_true)
		{
			rotate_both_stack(stack_a, stack_b, b_lst->count_true, a_lst->count_true - b_lst->count_true);
		}
		else
		{
			rotate_both_stack(stack_b, stack_a, a_lst->count_true, b_lst->count_true - a_lst->count_true);
		}
	}
	else
	{
		if (a_lst->count_true > b_lst->count_true)
		{
			rev_rotate_both_stack(stack_a, stack_b, b_lst->count_true, a_lst->count_true - b_lst->count_true);
		}
		else
		{
			rev_rotate_both_stack(stack_b, stack_a, a_lst->count_true, b_lst->count_true - a_lst->count_true);
		}
	}
}

void	region_no_equal(t_stack *stack_a, t_stack *stack_b, t_list *a_lst, t_list *b_lst)
{
	if (a_lst->region == 0)
	{
		rotate_one_stack(stack_a, a_lst->count_true);
		rev_rotate_stack(stack_b, b_lst->count_true);
	}
	else
	{
		rotate_one_stack(stack_b, b_lst->count_true);
		rev_rotate_stack(stack_a, a_lst->count_true);
	}
}



void	genius_function_moving(t_stack *stack_a, t_stack *stack_b, t_list *a_lst, t_list *b_lst)
{
	if (a_lst->region == b_lst->region)
		region_equal(stack_a, stack_b, a_lst, b_lst);
	else 
		region_no_equal(stack_a, stack_b, a_lst, b_lst);
}

void	clear_flags(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	
	tmp_a = stack_a->begin;
	tmp_b = stack_b->begin;
	while (tmp_a)
	{
		tmp_a->count_cmds = 0;
		tmp_a->count_true = 0;
		tmp_a->region = 0;
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		tmp_b->count_cmds = 0;
		tmp_b->count_true = 0;
		tmp_b->region = 0;
		tmp_b = tmp_b->next;
	}
}

void	sort_one_element(t_stack *stack_a, t_stack *stack_b)
{
	count_cmds(stack_b);
	count_cmds(stack_a);
	find_region(stack_a);
	find_region(stack_b);
	cmds_amount(stack_a, stack_b);
	t_list *tmp_b = min_count_cmds(stack_b);
	t_list *tmp_a = compare_difference(stack_a, tmp_b);
	genius_function_moving(stack_a, stack_b, tmp_a, tmp_b);
	push(stack_b, stack_a);
}

t_list	*find_begin(t_stack *stack)
{
	t_list *begin;
	begin = stack->begin;
	while (begin)
	{
		if (begin->index == 0)
			return (begin);
		begin = begin->next;
	}
	return (NULL);
}

void	moving_start(t_stack *stack)
{
	t_list *start = find_begin(stack);
	if (start->region == 0)
	{
		while(stack->begin->index != 0)
			rotate(stack, 1);
	}
	else 
	{
		while(stack->begin->index != 0)
			reverse_rotate(stack, 1);
	}
}

void	multy_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	find_true(stack_a); 
	foo_max_count(stack_a);
	transfer_to_b(stack_a, stack_b);
	while(stack_b->size > 1)
	{
		count_cmds(stack_b);
		count_cmds(stack_a);
		find_region(stack_a);
		find_region(stack_b);
		cmds_amount(stack_a, stack_b);
		t_list *tmp_b = min_count_cmds(stack_b);
		t_list *tmp_a = compare_difference(stack_a, tmp_b);
		genius_function_moving(stack_a, stack_b, tmp_a, tmp_b);
		push(stack_b, stack_a);
		clear_flags(stack_a, stack_b);
	}
	sort_one_element(stack_a, stack_b);
	moving_start(stack_a);
}
