NAME = so_long
MLX = ./minilibx-linux
MLX_LIB = $(MLX)/libmlx_Linux.a
MLX_FLAGS = -lXext -lX11 -lm -lbsd
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
FT_PRINTF = ft_printf/libftprintf.a

FT_PRINTF_SRCS = \
	ft_printf/ft_printf.c \
	ft_printf/ft_printf_utils.c

SRC = \
	src/dfs.c \
	src/game_utils.c \
	src/main.c \
	src/map_cast.c \
	src/map_check.c \
	src/mlx.c \
	src/print_error.c \
	src/tiny_utils.c

MLX_SRCS = \
	$(MLX)/mlx_clear_window.c \
	$(MLX)/mlx_destroy_display.c \
	$(MLX)/mlx_destroy_image.c \
	$(MLX)/mlx_destroy_window.c \
	$(MLX)/mlx_expose_hook.c \
	$(MLX)/mlx_ext_randr.c \
	$(MLX)/mlx_flush_event.c \
	$(MLX)/mlx_get_color_value.c \
	$(MLX)/mlx_get_data_addr.c \
	$(MLX)/mlx_hook.c \
	$(MLX)/mlx_init.c \
	$(MLX)/mlx_int_anti_resize_win.c \
	$(MLX)/mlx_int_do_nothing.c \
	$(MLX)/mlx_int_get_visual.c \
	$(MLX)/mlx_int_param_event.c \
	$(MLX)/mlx_int_set_win_event_mask.c \
	$(MLX)/mlx_int_str_to_wordtab.c \
	$(MLX)/mlx_int_wait_first_expose.c \
	$(MLX)/mlx_key_hook.c \
	$(MLX)/mlx_lib_xpm.c \
	$(MLX)/mlx_loop_hook.c \
	$(MLX)/mlx_loop.c \
	$(MLX)/mlx_mouse_hook.c \
	$(MLX)/mlx_mouse.c \
	$(MLX)/mlx_new_image.c \
	$(MLX)/mlx_new_window.c \
	$(MLX)/mlx_pixel_put.c \
	$(MLX)/mlx_put_image_to_window.c \
	$(MLX)/mlx_rgb.c \
	$(MLX)/mlx_screen_size.c \
	$(MLX)/mlx_set_font.c \
	$(MLX)/mlx_string_put.c \
	$(MLX)/mlx_xpm.c



OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) -I$(MLX) $(MLX_LIB) $(MLX_FLAGS) $(GNL) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF): $(FT_PRINTF_SRCS)
	make -C ft_printf

$(MLX_LIB): $(MLX_SRCS)
	make -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

clean:
	make -C $(MLX) clean
	make -C ft_printf clean
	rm -f $(OBJ)

fclean: clean
	make -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re