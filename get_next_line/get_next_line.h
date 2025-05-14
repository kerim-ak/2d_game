#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		is_there_a_line(char *str);
char	*free_util(char *scp);
char	*take_line(char *str);
char	*get_next_line(int fd);

#endif