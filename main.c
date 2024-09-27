#include "bsq.h"

int main(int ac, char **av)
{
	char	*buffer;
	int i;
	int j;
	point pt;
	map_st *map;

	(void)ac;
	j = 1;
	if (!av[1])
	{
		buffer = read_file(STDIN_FILENO);
		map = parse_buffer(buffer);
		if (!map)
		{
			_puts("map ERROR\n");
			exit(0);
		}
		pt = solve_map(map);
		draw_solution(map, pt);
		i = 0;
		while (map->lines[i])
		{
			_puts(map->lines[i++]);
			_puts("\n");
		}
		exit(0);
	}
	else
	{
		while (av[j])
		{
			buffer = read_file(open(av[j], O_RDWR));
			if (!buffer)
			{
				_puts("map ERROR\n");
				exit(0);
			}
			map = parse_buffer(buffer);
			if (!map)
			{
				_puts("map ERROR\n");
				exit(0);
			}
			pt = solve_map(map);
			draw_solution(map, pt);
			i = 0;
			while (map->lines[i])
			{
				_puts(map->lines[i++]);
				_puts("\n");
			}
			j++;
		}
	}

	return (0);
}
