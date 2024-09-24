#include "./bsq.h"

int	parse_map(map_st *map, char **lines)
{
	int	i;
	unsigned int	len;

	i = 0;
	while (lines[i])
		i++;
	if (i != map->height)
		return (0);
	len = _strlen(lines[0]);
	i = 1;
	while (lines[i])
		if (_strlen(lines[i++]) != len)
			return (0);

	return (1);
}
