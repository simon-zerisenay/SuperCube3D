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


int	f_atoi(char *str)
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

char	*f_strchr(char *s, int c)
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

size_t	f_strlcpy(char *dst, char *src, size_t dstsize)
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

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!i)
		return (0);
	while (--i && str[i] == ' ')
		;
	return (i);
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

int	f_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1
			&& s1[i] && s2[i])
		i++;
	if (n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

int	f_isdigit(int c)
{
	while (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// f_mapjoin(char *main, char *str, int max)
// {
// 	int	len;

// 	len = f_strlen(main);
// 	len += f_strlen()
// }