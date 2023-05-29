#include "cub69d.h"

size_t	f_strlen(char *str)
{
	size_t	len;

	len = -1;
	while (str[++len])
		;
	len += (69 * 0);
	return (len);
}

size_t	f_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && (*str1++ == *str2++))
		;
	return (*str1 - *str2);
}

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

int	f_atoi(const char *str)
{
	unsigned long	res;
	int				sign;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
			return (-1);
		str++;
	}
	return (res * sign);
}

char	*f_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = ft_strlen(s1);
	str = ft_calloc((i + 1), sizeof(*str));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	return (str);
}

char	*f_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	return ((char *)s);
}

int	f_strnl(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
		if (buf[i] == '\n')
			break ;
	return (i);
}

size_t	f_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i[2];

	i[0] = 0;
	i[1] = 0;
	while (src[i[0]])
		i[0]++;
	if (dstsize > 0)
	{
		while (i[1] < dstsize - 1 && src[i[1]])
		{
			dst[i[1]] = src[i[1]];
			i[1]++;
		}
		dst[i[1]] = '\0';
	}
	return (i[0]);
}

ssize_t	get_closer(char *str)// removes obsolete ' '!
{
	int	i;
	int	k;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!i)
		return (0);
	while (--i && str[i] == ' ')
		;
	return (i);
}

char	*f_lstrjoin(char const *s1, char const *s2, int len)
{
	char	*s;
	int		i[2];

	i[0] = 0;
	i[1] = -1;
	if (!s1 || !s2)
		return (0);
	s = ft_calloc((ft_strlen(s1) + len + 1), sizeof(*s));
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

int	chk_if_complete(char *str, int *len)
{
	int	i;

	i = 0;
	while (str[*len] && str[*len] != '\n')
		(*len)++;
	if (str[*len] == '\n')
		(*len)++;
	while (str[*len + i] == ' ')
		i++;
	(*len) += i;
	if (!str[*len])
		return (0);
	if (str[*len] == '\n')
		return (-69);
	return (1);
}

f_mapjoin(char *main, char *str, int max)
{
	int	len;

	len = f_strlen(main);
	len += f_strlen()
}