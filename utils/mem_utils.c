#include "cub69d.h"

char	*f_calloc(size_t amt, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * amt);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < amt)
		str[i] = 0;
	return (str);
}

char	*f_strdup(char *s1)
{
	char	*str;
	int		i;

	i = f_strlen(s1);
	str = f_calloc((i + 1), sizeof(*str));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	return (str);
}

char	*f_lstrjoin(char *s1, char *s2, int len)
{
	char	*s;
	int		i[2];

	i[0] = 0;
	i[1] = -1;
	if (!s1 || !s2)
		return (0);
	s = f_calloc((f_strlen(s1) + len + 1), sizeof(*s));
	if (!s)  
		return (0);
	while (s1[++i[1]])
		s[i[1]] = s1[i[1]];
	while (i[0] < len)
		s[i[1]++] = s2[i[0]++];
	s[i[1]] = '\0';
	free (s1);
	return (s);
}

char	*f_bufstr(char *buf, char *str, int rd)
{
	char	*tmp;
	int		i;

	i = -1;
	// if (!rd)
		// return
	if (!str)
		tmp = f_calloc(rd + 1, sizeof(*str));
	else
		tmp = f_calloc((rd + 1) + f_strlen(str), sizeof(*str));
	if (!tmp)
		// return (NULL);//purge
	if (str)
	{
		while (str[++i])
			tmp[i] = str[i];
		i--;
		free (str);
	}
	while (++i < rd)
		tmp[i] = buf[i];
	return (tmp);
}

// char	*f_realloc(char *str, int e)
// {
// 	char	*new;
// 	int	i[2];

// 	i[0] = f_strlen(str) + 1;
// 	i[1] = -1;
// 	new = f_calloc(i + e, sizeof(*str));
// 	if (!new)
// 	while (str[++i[1]])
// 		new[i[1]] = str[i[1]];
// 	free(str);
// 	return (new);
// }