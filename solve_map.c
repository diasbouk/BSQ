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

void	draw_solution(char **map, int x, int y, char full, int max)
{
	int	i = 0;
	int	j = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			map[x + i][y + j] = full;
			j++;
		}
		i++;
	}
}

int get_max(char **map, int x, int y)
{
	int max = 0;
	while (check_box(map, x, y, max))
		max++;
	return (max - 1);
}
