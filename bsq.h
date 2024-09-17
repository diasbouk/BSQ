#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>



#define BUFFER_SIZE 1024


void	_puts(const char *str);
char	*read_file(int file);
unsigned int _strlen(const char *str);
void _bzero(void *addr, unsigned int size);
void	*ft_memcpy(void *dest, void *src, unsigned int size);
void	*ft_realloc(void *old,unsigned int old_size, unsigned int new_size);
char **_split(const char *str, const char *charset);
