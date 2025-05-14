#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define TILE_SIZE 64
# define KEY_W        119
# define KEY_A        97
# define KEY_S        115
# define KEY_D        100
# define KEY_ESC      65307
# define KEY_UP       65362
# define KEY_LEFT     65361
# define KEY_DOWN     65364
# define KEY_RIGHT    65363

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	char	**map;
	int		x;
	int		y;
	int		height;
	int		width;
	int		c_count;
	int		e_count;
	int		p_count;
	int		move_count;
}			t_game;

//dfs.c
int		map_check(t_game *game);

//game_utils.c
int		exit_game(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		handle_input(int keycode, void *param);
void	init_game_var(t_game **game);
int		init_game(t_game **game, int fd, char *map_name);

//map_cast.c
int		count_lines(int fd);
char	*remove_nl(char *str);
char	**cast_map(t_game **game, int fd, char *map_name);
int		screen_size_check(t_game *game);

//map_check.c
char	**map_alloc_copy(char **map);
int		check_map_index(char **map);
int		check_item_counts(t_game *game);

//mlx.c
void	load_images(t_game *game);
void	draw_tile(t_game *game, void *img, int x, int y);
void	draw_map(t_game *game);
void	init_window(t_game *game);
void	render_map(t_game *game);

//print_error.c
void	print_error(int type);

//tiny_utils.c
char	**malloc_error_charpp(void);
char	**free_shortcut(char **str);
int		malloc_error_int(void);
int		ft_strcmp(char *s1, char *s2);
void	free_double_arr(char **arr);

#endif