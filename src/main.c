#include "../inc/so_long.h"

static int	check_extension(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i] != '.')
		i++;
	if (ft_strcmp(file_name + i, ".ber"))
	{
		print_error(3);
		return (1);
	}
	if (ft_strlen(file_name + i) == 4)
	{
		ft_printf("Error\nMap file is a hidden file!\n");
		return (1);
	}
	return (0);
}

static void	init_all(t_game *game)
{
	init_window(game);
	if (!game->win)
	{
		ft_printf("Error\nWindow cannot initialized properly\n");
		exit_game(game);
	}
	load_images(game);
	if (!game->img_collectible || !game->img_exit || !game->img_floor
		|| !game->img_player || !game->img_wall)
	{
		ft_printf("Error\nImages did not load properly!\n");
		exit_game(game);
	}
	draw_map(game);
	mlx_key_hook(game->win, handle_input, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}

static int	check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		print_error(12);
		return (1);
	}
	close(fd);
	return (0);
}

static int	game_files_check(void)
{
	if (check_file("assets/collect.xpm"))
		return (1);
	if (check_file("assets/exit.xpm"))
		return (1);
	if (check_file("assets/floor.xpm"))
		return (1);
	if (check_file("assets/player.xpm"))
		return (1);
	if (check_file("assets/wall.xpm"))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		map;

	if (argc != 2)
		return (1);
	if (game_files_check() || check_extension(argv[1]))
		return (1);
	map = open(argv[1], O_RDONLY, 0644);
	if (map == -1)
	{
		print_error(2);
		return (1);
	}
	game = NULL;
	if (init_game(&game, map, argv[1]))
		return (1);
	if (map_check(game))
		init_all(game);
	else
	{
		exit_game(game);
		return (1);
	}
	exit_game(game);
	return (0);
}
