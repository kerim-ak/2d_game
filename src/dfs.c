#include "../inc/so_long.h"

static void	dfs(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	dfs(map, game, x + 1, y);
	dfs(map, game, x - 1, y);
	dfs(map, game, x, y + 1);
	dfs(map, game, x, y - 1);
}

static int	wall_check(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			print_error(11);
			return (1);
		}
	}
	i = -1;
	while (++i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			print_error(11);
			return (1);
		}
	}
	return (0);
}

static int	check_rectangular(char **map)
{
	int	i;
	int	j;
	int	max_width;

	i = -1;
	max_width = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i == 0)
			max_width = j;
		if (j != max_width)
		{
			print_error(7);
			return (0);
		}
	}
	if (max_width == 0)
	{
		print_error(9);
		return (0);
	}
	return (1);
}

static int	check_map_objects(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != '0')
			{
				print_error(10);
				return (0);
			}
		}
	}
	return (1);
}

int	map_check(t_game *game)
{
	char	**copy;

	copy = map_alloc_copy(game->map);
	if (!copy)
		return (0);
	if (!check_map_objects(copy) || !check_rectangular(copy)
		|| wall_check(game) || screen_size_check(game))
	{
		free_double_arr(copy);
		return (0);
	}
	dfs(copy, game, game->x, game->y);
	if (!check_map_index(copy) || !check_item_counts(game))
	{
		free_double_arr(copy);
		return (0);
	}
	free_double_arr(copy);
	return (1);
}
