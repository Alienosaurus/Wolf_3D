#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>

#include "sgt_map.h"

static void		s_comb_first_end(char **line, int len_lines)
{
	char	*new_line;

	new_line = ft_strnew(len_lines + 3);
	ft_memset(new_line, '1', len_lines + 2);
	*line = new_line;
}

static void		s_comb(char **line, int len_lines)
{
	char	*new_line;

	new_line = ft_strnew(len_lines + 3);
	ft_memset(new_line, '1', len_lines + 2);
	ft_memcpy(new_line + 1, *line, ft_strlen(*line));
	ft_strdel(line);
	*line = new_line;
}

static int		s_stock_map(char *name, int count_lines, size_t max_len_lines)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (-1);
	if ((map = malloc(sizeof(char *) * (count_lines + 1))) == NULL)
		return (-1);
	i = 0;
	s_comb_first_end(&map[i++], max_len_lines);
	while (ft_get_next_line(fd, &line) > 0)
	{
		s_comb(&line, max_len_lines);
		map[i++] = line;
	}
	s_comb_first_end(&map[i++], max_len_lines);
	map[i] = NULL;
	if (close(fd) == -1 || count_lines <= 0)
		return (-1);
	sgt_map(map);
	return (0);
}

int				open_map(char *name)
{
	char	*line;
	int		fd;
	int		count_lines;
	size_t	max_len_lines;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (-1);
	line = NULL;
	count_lines = 0;
	max_len_lines = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		++count_lines;
		if (max_len_lines < ft_strlen(line))
			max_len_lines = ft_strlen(line);
		ft_strdel(&line);
	}
	if (close(fd) == -1 || count_lines <= 0 || max_len_lines <= 0)
		return (-1);
	return (s_stock_map(name, count_lines + 2, max_len_lines));
}
