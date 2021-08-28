#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include "../libs/libft/libft.h"

typedef struct s_main_struct
{
	long long int *mas;
	int				size;
}				t_main_struct;

typedef struct  s_stack
{
	size_t	size;
	t_list	*begin;
	char	name;
}			t_stack;


void	init(t_main_struct *main_struct, int argc);
void	check_argument(t_main_struct *main_struct, char **argv, int argc, int i);
int		check_dup(long long int *mas, int size);
int		check_argv(char *str);
void	ft_error(char *message);
void	sort_array(t_main_struct *main_struct, t_list *start_list);
int		sorted_or_not(t_main_struct *main_struct);
void	init_stack(t_list *start_list, t_stack *stack_a, t_stack *stack_b, int size);
void	swap(t_stack *stack, int flag);
void	ss_swap(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *src, t_stack *dst);
void    rotate(t_stack *stack, int flag);
void	print_list(t_stack *head);
void	reverse_rotate(t_stack *stack, int flag);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	multy_sort(t_stack *stack_a, t_stack *stack_b);
void    transfer_to_b(t_stack *stack_a, t_stack *stack_b);

#endif
