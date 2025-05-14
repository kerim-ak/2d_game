#include "../inc/so_long.h"

int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	*remove_nl(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ret = malloc((i + 1) * sizeof(char));
	if (!ret)
	{
		print_error(1);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	free(str);
	return (ret);
}

char	**cast_map(t_game **game, int fd, char *map_name)
{
	int		i;
	int		count;
	char	**map;

	i = -1;
	count = count_lines(fd);
	fd = open(map_name, O_RDONLY, 0644);
	if (fd == -1)
		print_error(2);
	if (fd == -1)
		return (NULL);
	map = malloc((count + 1) * sizeof(char *));
	if (!map)
		return (malloc_error_charpp());
	while (++i < count)
	{
		map[i] = remove_nl(get_next_line(fd));
		if (map[i] == NULL)
			return (free_shortcut(map));
		(*game)->width = ft_strlen(map[i]);
	}
	map[i] = NULL;
	(*game)->height = i;
	close(fd);
	return (map);
}

int	screen_size_check(t_game *game)
{
	if (game->width > 60 || game->height > 32)
	{
		ft_printf("Error\nMap is too big!\n");
		return (1);
	}
	return (0);
}
