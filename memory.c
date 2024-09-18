#include "bsq.h"

void _bzero(void *addr, unsigned int size) {
  char			*ptr;
  unsigned int	i;

  if (!addr)
    return;
  ptr = (char *)addr;
  i = 0;
  while (i < size) {
    ptr[i++] = '\0';
  }
}


void	*ft_memcpy(void *dest, void *src, unsigned int size)
{
        unsigned long   i;
        unsigned char   *dst;
        unsigned char   *sc;

        if (!src || !dest)
                return (0);
        i = 0;
        dst = (unsigned char *)dest;
        sc = (unsigned char *)src;
        while (i < size)
        {
                dst[i] = sc[i];
                i++;
        }
        return (dest);
}

static unsigned int	ft_min(unsigned int a, unsigned int b) {
	if (a < b)
		return (a);
	return (b);
}

void	*ft_realloc(void *old,unsigned int old_size, unsigned int new_size) {

	void	*new;

	if (!old)
		return (NULL);
	if (new_size == 0) {
		free(old);
		return (NULL);
	}
	new = malloc(new_size + 1);
	if (!new)
		return (NULL);
	_bzero(new, new_size + 1);
	ft_memcpy(new, old, ft_min(new_size, old_size));
	free(old);
	return (new);
}
