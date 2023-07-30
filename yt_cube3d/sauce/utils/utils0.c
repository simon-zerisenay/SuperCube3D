#include "cub69d.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (*s)
		return ((char *)s);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}