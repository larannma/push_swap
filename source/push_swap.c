#include "../include/push_swap.h"

void	if_one_argument(t_main_struct *main_struct, char *argv)
{
	int		i;
	char	**line_mas;

	i = 0;
	line_mas = ft_split(argv, ' ');
	while (line_mas[i])
		i++;
	main_struct->size = i;
	main_struct->mas = malloc((i + 1) * sizeof(long long int));
	if (main_struct->mas == NULL)
		ft_error("Error\n");
	check_argument(main_struct, line_mas, i + 1, 0);
}

void	convert_to_list(t_main_struct *main_struct, t_list **start_list)
{
	int	i;

	i = 0;
	while (i < main_struct->size)
	{
		ft_lstadd_back(start_list, ft_lstnew(NULL, main_struct->mas[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_main_struct	main_struct;
	t_list			*start_list;
	t_stack			stack_a;
	t_stack			stack_b;

	if (argc == 1)
		exit (1);
	if (argc == 2)
		if_one_argument(&main_struct, argv[1]);
	else
	{
		main_struct.size = argc - 1;
		init(&main_struct, argc);
		check_argument(&main_struct, argv, argc, 1);
	}
	if (sorted_or_not(&main_struct) == 1)
		exit (1);
	convert_to_list(&main_struct, &start_list);
	sort_array(&main_struct, start_list);
	init_stack(start_list, &stack_a, &stack_b, main_struct.size);
	sort_stack(&stack_a, &stack_b);
}
