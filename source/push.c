#include "../include/push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	t_list	*dst_begin_old;
	t_list	*src_begin_old;

	dst_begin_old = dst->begin;
	src_begin_old = src->begin;
	src->begin = src_begin_old->next;
	dst->begin = src_begin_old;
	(dst->begin)->next = dst_begin_old;
	src->size--;
	dst->size++;
	ft_putstr_fd("p", 1);
	write(1, &dst->name, 1);
	write(1, "\n", 1);
}
