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

void	init(t_main_struct *main_struct, int argc);
void	check_argument(t_main_struct *main_struct, char **argv, int argc, int i);
int		check_dup(long long int *mas, int size);
int		check_argv(char *str);
void	ft_error(char *message);
void	sort_array(t_main_struct *main_struct, t_list *start_list);

#endif
