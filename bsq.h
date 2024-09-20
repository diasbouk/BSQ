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
} map_st;

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

/* Parsing funcs */
map_st	*parse_line(const char *line);
