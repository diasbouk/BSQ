#include "bsq.h"

int	check_box(char **map, int x, int y, int	max)
{
	int i, j;
	char obs = 'o';
	i = 0;
	j = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if (!map[x + i] || !map[x + i][y + j] || map[x + i][y + j] == obs)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int get_max(char **map, int x, int y)
{
	int max = 0;
	while (check_box(map, x, y, max))
		max++;
	return (max - 1);
}


void	draw_solution(map_st *map, point pt)
{
	int	i = 0;
	int	j = 0;
	while (i < pt.max)
	{
		j = 0;
		while (j < pt.max)
		{
			map->lines[pt.x + i][pt.y + j] = map->full;
			j++;
		}
		i++;
	}
}

point solve_map(map_st *map)
{
	point pt;
	int	i;
	int	j;

	i = 0;
	j = 0;
	pt.max = 0;
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j])
		{
			int max = get_max(map->lines, i, j);
			if (max > pt.max)
			{
				pt.max = max;
				pt.x = i;
				pt.y = j;
			}
			j++;
		}
		i++;
	}
	return (pt);
}
