#include "../include/push_swap.h"
#include "../libs/libft/libft.h"

void	if_one_argument(t_main_struct *main_struct, char *argv)
{
	int i;
	char	**line_mas;

	i = 0;
	line_mas = ft_split(argv, ' ');
	while (line_mas[i])
		i++;
	main_struct->size = i;
	main_struct->mas = malloc((i + 1) * sizeof(long long int));
    if (main_struct->mas == NULL)
        ft_error("Couldn't allocate enought space\n");
	check_argument(main_struct, line_mas, i + 1, 0);

}

void	convert_to_list(t_main_struct *main_struct, t_list **start_list)
{
	int i;

	i = 0;
	while (i < main_struct->size)
	{
		ft_lstadd_back(start_list, ft_lstnew(NULL, main_struct->mas[i]));
		i++;
	}
}
void	print_list(t_list *head)
{
	while(head != NULL)
	{
		printf("number: %d\n || index: %d\n", head->number, head->index);
		head = head->next;
	}
}

int	main(int argc, char **argv)
{
	t_main_struct	main_struct;
	t_list *start_list;

	if (argc == 2)
		if_one_argument(&main_struct, argv[1]);
	else
	{
		main_struct.size = argc - 1;
		init(&main_struct, argc);
		check_argument(&main_struct, argv, argc, 1);
	}
	if (sorted_or_not(&main_struct) == 1)
		ft_error("Array is sorted\n");
	convert_to_list(&main_struct, &start_list);
	sort_array(&main_struct, start_list);
	// print_list(start_list);
}
