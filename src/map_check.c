#include "../inc/so_long.h"

static void	count_map_len(int *row, int *col, char **map)
{
	int	i;
	int	j;
	int	j_max;

	i = 0;
	j = 0;
	j_max = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j++;
			if (j > j_max)
				j_max = j;
		}
		j = 0;
		i++;
	}
	*row = i;
	*col = j_max;
}

static void	map_copy(char **map, char **copy)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			copy[x][y] = map[x][y];
			y++;
		}
		copy[x][y] = '\0';
		x++;
	}
	copy[x] = NULL;
}

char	**map_alloc_copy(char **map)
{
	int		i;
	int		j;
	int		k;
	char	**copy;

	i = 0;
	j = 0;
	k = -1;
	count_map_len(&i, &j, map);
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (++k < i)
	{
		copy[k] = malloc((j + 1) * sizeof(char));
		if (!copy[k])
		{
			free_double_arr(copy);
			return (NULL);
		}
	}
	map_copy(map, copy);
	return (copy);
}

int	check_map_index(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				print_error(8);
				return (0);
			}
		}
	}
	return (1);
}

int	check_item_counts(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				game->c_count++;
			if (game->map[i][j] == 'E')
				game->e_count++;
		}
	}
	if (game->c_count <= 0)
		print_error(4);
	if (game->e_count != 1)
		print_error(5);
	if (game->p_count != 1)
		print_error(6);
	if (game->c_count <= 0 || (game->e_count != 1) || (game->p_count != 1))
		return (0);
	return (1);
}
