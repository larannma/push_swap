#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include "../libs/libft/libft.h"

typedef struct s_main_struct
{
	long long int	*mas;
	int				size;
}				t_main_struct;

typedef struct s_stack
{
	size_t	size;
	t_list	*begin;
	char	name;
}			t_stack;

void	init(t_main_struct *main_struct, int argc);
void	check_argument(t_main_struct *main_struct, \
	char **argv, int argc, int i);
int		check_dup(long long int *mas, int size);
int		check_argv(char *str);
void	ft_error(char *message);
void	sort_array(t_main_struct *main_struct, t_list *start_list);
int		sorted_or_not(t_main_struct *main_struct);
void	init_stack(t_list *start_list, t_stack *stack_a, \
	t_stack *stack_b, int size);
void	swap(t_stack *stack, int flag);
void	ss_swap(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *src, t_stack *dst);
void	rotate(t_stack *stack, int flag);
void	print_list(t_stack *head);
void	reverse_rotate(t_stack *stack, int flag);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	multy_sort(t_stack *stack_a, t_stack *stack_b);
void	transfer_to_b(t_stack *stack_a, t_stack *stack_b);
void	count_cmds(t_stack *stack);
void	cmds_amount(t_stack *stack_a, t_stack *stack_b);
void	rr_rotate(t_stack *stack_a, t_stack *stack_b);
void	rr_reverse_rotate(t_stack *stack_a, t_stack *stack_b);
void	find_region(t_stack *stack);
t_list	*compare_difference(t_stack *stack_a, t_list *lst);
void	ft_set_region(t_list *lst);
t_list	*compare_difference(t_stack *stack_a, t_list *lst);
void	cmds_amount(t_stack *stack_a, t_stack *stack_b);
int		sorted_or_not(t_main_struct *main_struct);
void	find_true(t_stack *stack_a);
void	get_new_count_true(t_list *tmp, t_list *begin);
void	foo_max_count(t_stack *stack_a);
t_list	*min_count_cmds(t_stack *stack_b);
void	count_true(t_list *tmp, t_list *begin);
void	rotate_both_stack(t_stack *stack_1, t_stack *stack_2, \
	int both, int first);
void	rev_rotate_both_stack(t_stack *stack_1, t_stack *stack_2, \
	int both, int first);
void	rotate_one_stack(t_stack *stack, int count);
void	rev_rotate_stack(t_stack *stack, int count);
void	clear_flags(t_stack *stack_a, t_stack *stack_b);
void	region_equal(t_stack *stack_a, t_stack *stack_b, \
	t_list *a_lst, t_list *b_lst);
void	region_no_equal(t_stack *stack_a, t_stack *stack_b, \
	t_list *a_lst, t_list *b_lst);
void	genius_function_moving(t_stack *stack_a, t_stack *stack_b, \
	t_list *a_lst, t_list *b_lst);
void	sort_four_continue(int min_index, int min_number, \
	t_stack *stack_a, t_stack *stack_b);
void	sort_five_continue(int min_index, int min_number, \
	t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);

#endif
