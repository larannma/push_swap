#include "../include/push_swap.h"
#include "../libs/libft/libft.h"

void	sort_array(t_main_struct *main_struct, t_list *start_list)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < main_struct->size)
	{
		j = i + 1;
		while (j < main_struct->size)
		{
			if (main_struct->mas[i] > main_struct->mas[j])
			{
				temp = main_struct->mas[i];
				main_struct->mas[i] = main_struct->mas[j];
				main_struct->mas[j] = temp;
			}
			j++;
		}
		i++;
	}
	// for (int i = 0; i < main_struct->size; i++) {     
    //     printf("%lld\n", main_struct->mas[i]);    
    // }
	i = 0;
	j = 0;
	while (start_list)
	{
		i = 0;
		while (i < main_struct->size)
		{
			if (start_list->number == main_struct->mas[i])
			{
				start_list->index = i;
				// printf("number %4d have index %4d\n", start_list->number, start_list->index);
				break ;
			}
			i++;
		}
		start_list = start_list->next;
	}
}


