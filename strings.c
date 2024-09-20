#include "bsq.h"

void	_puts(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}


unsigned int _strlen(const char *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *_strdup(const char *str)
{
	int	i;
	char *dup;

	if (!str)
		return (NULL);
	while (str[i])
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	is_delim(const char *charset, char delim)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == delim)
			return (1);
		i++;
	}
	return (0);
}

static char *_strdup_till(const char *str, const char *charset)
{
	int i;
	char *dup;

	i = 0;
	while (str[i] && !is_delim(charset, str[i]))
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] && !is_delim(charset, str[i]))
	{
		dup[i]  = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**allocate_list(const char *str, const char *charset)
{
	int		i;
	int		count;
	char	**list;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] &&is_delim(charset, str[i]))
			i++;
		count++;
		while (str[i] && !is_delim(charset, str[i]))
			i++;
	}
	list = (char **)malloc(sizeof(char *) * (count + 1));
	if (!list)
		return (NULL);
	return (list);
}

char	**_split(const char *str, const char *charset)
{
	int		i;
	int		count;
	char	**list;

	i = 0;
	count = 0;
	list = allocate_list(str, charset);
	if (!list)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_delim(charset, str[i]))
			i++;
		list[count] = _strdup_till(str + i, charset);
		count++;
		while (str[i] && !is_delim(charset, str[i]))
			i++;
	}
	list[count]  = NULL;
	return (list);
}
