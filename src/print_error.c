#include "../inc/so_long.h"

void	print_error(int type)
{
	ft_printf("Error\n");
	if (type == 1)
		ft_printf("Malloc error!\n");
	else if (type == 2)
		ft_printf("Unable to open a file!\n");
	else if (type == 3)
		ft_printf("Invalid map extension!\n");
	else if (type == 4)
		ft_printf("There is no collectible on the map!\n");
	else if (type == 5)
		ft_printf("Invalid exit count! There has to be only 1 exit!\n");
	else if (type == 6)
		ft_printf("Invalid player count! There has to be only 1 player!\n");
	else if (type == 7)
		ft_printf("Map is not rectangular!\n");
	else if (type == 8)
		ft_printf("Some exit(s) or collectible(s) is/are not reachable!\n");
	else if (type == 9)
		ft_printf("There is no map!\n");
	else if (type == 10)
		ft_printf("Invalid char in the map!\n");
	else if (type == 11)
		ft_printf("Map is not surrounded by walls!\n");
	else if (type == 12)
		ft_printf("Some asset files are missing or named incorrectly!\n");
}
