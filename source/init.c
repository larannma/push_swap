#include "../include/push_swap.h"
#include "../libs/libft/libft.h"

void	init(t_main_struct *main_struct, int argc)
{
	main_struct->mas = malloc((argc - 1) * sizeof(long long int));
	if (main_struct->mas == NULL)
		ft_error("Couldn't allocate enought space\n");
}

int	check_dup(long long int *mas, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (mas[i] == mas[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_argv(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) >= 20)
		ft_error("Error\n");
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0)
		{
			i++;
			continue ;
		}
		if (ft_isdigit(str[i]))
		{
			i++;
			continue ;
		}
		return (0);
	}
	return (1);
}

int	check_max_min_int(t_main_struct *main_struct, int a)
{
	int	i;

	i = 0;
	while (i < a)
	{
		if (main_struct->mas[i] < -2147483648 || \
			main_struct->mas[i] > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

void	check_argument(t_main_struct *main_struct, char **argv, int argc, int i)
{
	int	k;

	k = 0;
	if (i == 0)
		argc--;
	while (i < argc)
	{
		if (check_argv(argv[i]))
		{
			main_struct->mas[k++] = ft_atoi(argv[i]);
			i++;
		}
		else
			ft_error("Something is wrong with your argument\n");
	}
	if (!check_dup(main_struct->mas, argc - 1))
		ft_error("You have duplicate numbers\n");
	if (!check_max_min_int(main_struct, argc - 1))
		ft_error("The number is too big");
}
