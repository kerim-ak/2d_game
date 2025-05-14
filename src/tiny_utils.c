#include "../inc/so_long.h"

char	**malloc_error_charpp(void)
{
	print_error(1);
	return (NULL);
}

char	**free_shortcut(char **str)
{
	ft_printf("Error\nMap reading error!\n");
	free_double_arr(str);
	return (NULL);
}

int	malloc_error_int(void)
{
	print_error(1);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] != s2[i])
		return (1);
	return (0);
}

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
