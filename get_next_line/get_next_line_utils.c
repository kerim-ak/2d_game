#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_there_a_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*free_shortcut(char *str)
{
	free(str);
	return (NULL);
}

char	*free_util(char *scp)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (scp[i] && scp[i] != '\n')
		i++;
	if (scp[i] == '\0')
	{
		free(scp);
		return (NULL);
	}
	temp = malloc((ft_strlen(scp) - i) * sizeof(char));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (scp[i])
		temp[j++] = scp[i++];
	temp[j] = '\0';
	free(scp);
	if (j == 0)
		return (free_shortcut(temp));
	return (temp);
}

char	*take_line(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] == '\n')
		i++;
	temp = malloc((i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	j = -1;
	while (++j < i)
		temp[j] = str[j];
	if (j == 0)
		free(temp);
	if (j == 0)
		return (NULL);
	temp[j] = '\0';
	return (temp);
}
