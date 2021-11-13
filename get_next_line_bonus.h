#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *s);
char		*ft_strjoin(char const *s1, char const *s2);
#endif
