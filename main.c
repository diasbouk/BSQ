#include "bsq.h"

int main(int ac, char **av) {
	char	*buffer;
	int i;
	point pt;
	map_st *map;

	(void)ac;
	if (av[1])
		buffer = read_file(open(av[1], O_RDWR));
	else
		buffer = read_file(STDIN_FILENO);
	if (!buffer)
		return (0);
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

	return (0);
}
