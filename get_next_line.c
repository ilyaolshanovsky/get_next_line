#include "get_next_line.h"

int	ft_cleaning(char **ptr, int i)
{
	free(*ptr);
	*ptr = 0;
	return (i);
}

int	ft_read_file(char **save, int fd)
{
	char	*buf;
	int		byte;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE +1);
	if (!buf)
		return (-1);
	byte = read(fd, buf, BUFFER_SIZE);
	while (byte > 0)
	{
		buf[byte] = '\0';
		tmp = *save;
		*save = ft_strjoin(*save, buf);
		if (!(*save))
		{
			ft_cleaning(&tmp, 0);
			return (ft_cleaning(&buf, -1));
		}
		ft_cleaning(&tmp, 0);
		if (ft_strchr(*save, '\n'))
			return (ft_cleaning(&buf, byte));
		byte = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_cleaning(&buf, byte));
}

int	ft_sget(char **save, char **line)
{
	char	*tmp;
	char	*check;

	check = ft_strchr(*save, '\n');
	if (check)
	{
		*check = '\0';
		tmp = *save;
		*line = ft_strdup(*save);
		if (!(*line))
			return (ft_cleaning(&tmp, -1));
		*save = ft_strdup(++check);
		if (!(*save))
			return (ft_cleaning(&tmp, -1));
		return (ft_cleaning(&tmp, 1));
	}
	*line = ft_strdup(*save);
	if (!(*line))
		return (ft_cleaning(save, -1));
	return (ft_cleaning(save, 0));
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	int			byte;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	byte = ft_read_file(&save, fd);
	if (byte < 0)
		return (-1);
	if (byte == 0 && save == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_sget(&save, line));
}
