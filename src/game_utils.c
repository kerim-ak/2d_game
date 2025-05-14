#include "../inc/so_long.h"

int	exit_game(t_game *game)
{
	if (game->mlx && game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->mlx && game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->mlx && game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->mlx && game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->mlx && game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->map)
		free_double_arr(game->map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game)
		free(game);
	exit(0);
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->x + dx;
	new_y = game->y + dy;
	tile = game->map[new_y][new_x];
	if (tile == '1')
		return ;
	if (tile == 'C')
	{
		game->c_count--;
		game->map[new_y][new_x] = '0';
	}
	if (tile == 'E' && game->c_count == 0)
	{
		game->move_count++;
		ft_printf("Moves: %d\n", game->move_count);
		exit_game(game);
	}
	game->x = new_x;
	game->y = new_y;
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
	render_map(game);
}

int	handle_input(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

void	init_game_var(t_game **game)
{
	(*game)->c_count = 0;
	(*game)->e_count = 0;
	(*game)->height = 0;
	(*game)->img_collectible = NULL;
	(*game)->img_exit = NULL;
	(*game)->img_floor = NULL;
	(*game)->img_player = NULL;
	(*game)->img_wall = NULL;
	(*game)->map = NULL;
	(*game)->mlx = NULL;
	(*game)->move_count = 0;
	(*game)->p_count = 0;
	(*game)->width = 0;
	(*game)->win = NULL;
	(*game)->x = 0;
	(*game)->y = 0;
}

int	init_game(t_game **game, int fd, char *map_name)
{
	int	y;
	int	x;

	y = -1;
	*game = malloc(1 * sizeof(t_game));
	if (!(*game))
		return (malloc_error_int());
	init_game_var(game);
	(*game)->map = cast_map(game, fd, map_name);
	if ((*game)->map == NULL)
		return (1);
	while ((*game)->map[++y])
	{
		x = -1;
		while ((*game)->map[y][++x])
		{
			if ((*game)->map[y][x] == 'P')
			{
				(*game)->p_count++;
				(*game)->x = x;
				(*game)->y = y;
			}
		}
	}
	return (0);
}
