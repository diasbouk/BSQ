#include "./bsq.h"

static int	is_digit(char c)
{
	if (c >= '0' && c<= '9')
		return (1);
	return (0);
}

static int	is_valid_line(const char *line)
{
	int	len;
	int	i;

	len = _strlen(line);
	if (len < 4)
		return (0);
	i = 0;
	while (i < len - 3)
	{
		if (!is_digit(line[i]))
			return (0);
		i++;
	}
	if (line[len - 1] == line[len - 2] || line[len - 1] == line[len - 3])
		return (0);
	if (line[len - 2] == line[len - 3])
		return (0);
	return (1);
}

map_st	*parse_buffer(const char *buffer)
{
	map_st *map;
	unsigned int	i;
	unsigned int	len;
	char	*line;

	map = (map_st *)malloc(sizeof(map_st));
	if (!map)
		return (NULL);
	map->lines = _split(buffer, "\n");
	line = map->lines[0];
	if (!is_valid_line(line))
		return (NULL);
	map->height = 0;
	len = _strlen(line);
	i = 0;
	while (i < len - 3)
		map->height = (map->height * 10) + (line[i++] - 48);
	map->empty = line[len - 3];
	map->obstacle = line[len - 2];
	map->full = line[len - 1];
	i = 2;
	len = _strlen(map->lines[1]);
	while (map->lines[i + 1])
	{
		if (_strlen(map->lines[i]) != len)
		{
			free_d(map->lines);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}
