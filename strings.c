#include "bsq.h"

void	_puts(const char *str) {
	int	i;

	i = 0;
	while(str[i]) {
		write(1, &str[i], 1);
		i++;
	}
}


unsigned int _strlen(const char *str) {
	unsigned int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *_strdup(const char *str) {
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
	while (str[i]) {
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	is_delim(const char *charset, char delim) {
	int	i;

	i = 0;
	while (charset[i]) {
		if (charset[i] == delim)
			return (0);
		i++;
	}
	return (1);
}

char *_strdup_till(const char *str, int (*func)(char)) {
	int i;
	char *dup;

	i = 0;
	while (str[i] && func(str[i]))
		i++;
	i = 0;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	while (str[i] && func(str[i])) {
		dup[i]  = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
