#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


/* Macros */
#define BUFFER_SIZE 1024

/* Structures */
typedef struct map_st {
	int	height;
	char obstacle;
	char empty;
	char full;
	char **lines;
} map_st;

typedef struct solution_st
{
	int	x;
	int y;
	int max;
	char full;
} solution_st;

typedef struct point
{
	int x;
	int y;
	int max;
} point;

/* Strings funcs */
void	_puts(const char *str);
unsigned int _strlen(const char *str);
char **_split(const char *str, const char *charset);

/* Files funcs */
char	*read_file(int file);

/* Memory funcs */
void _bzero(void *addr, unsigned int size);
void	*ft_memcpy(void *dest, void *src, unsigned int size);
void	*ft_realloc(void *old,unsigned int old_size, unsigned int new_size);
void free_d(char **list);

/* Parsing funcs */
map_st	*parse_buffer(const char *line);
point solve_map(map_st *map);
void	draw_solution(map_st *map, point pt);
int	check_box(char **map, int x, int y, int	max);
int get_max(char **map, int x, int y);
