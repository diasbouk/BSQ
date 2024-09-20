#include "bsq.h"

/**
	* read_file - Read from a file descriptor
	* @file: Int fd of file
	* Return: Buffer conataining file content
*/

char	*read_file(int file)
{
	char			*buffer;
	unsigned int	size;
	unsigned int	i;

	size = BUFFER_SIZE;
	i = 0;
	if (file < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	_bzero(buffer, BUFFER_SIZE);
	while (read(file, buffer + i, 1))
	{
		if (i == size - 1)
		{
			size *= 2;
			buffer = ft_realloc(buffer, i + 1, size);
		}
		i++;
	}
	buffer = ft_realloc(buffer, i + size, i);
	return (buffer);
}
