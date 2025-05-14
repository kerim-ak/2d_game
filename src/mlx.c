#include "../inc/so_long.h"

void	load_images(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &game->width, &game->height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &game->width, &game->height);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &game->width, &game->height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &game->width, &game->height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collect.xpm", &game->width, &game->height);
}

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				draw_tile(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				draw_tile(game, game->img_floor, x, y);
			else if (game->map[y][x] == 'P')
				draw_tile(game, game->img_player, x, y);
			else if (game->map[y][x] == 'E')
				draw_tile(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'C')
				draw_tile(game, game->img_collectible, x, y);
		}
	}
	game->move_count = 0;
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nmlx_init failed!\n");
		exit_game(game);
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
}

void	render_map(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			c = game->map[y][x];
			if (c == '1')
				draw_tile(game, game->img_wall, x, y);
			else
				draw_tile(game, game->img_floor, x, y);
			if (c == 'C')
				draw_tile(game, game->img_collectible, x, y);
			else if (c == 'E')
				draw_tile(game, game->img_exit, x, y);
		}
	}
	draw_tile(game, game->img_player, game->x, game->y);
}
