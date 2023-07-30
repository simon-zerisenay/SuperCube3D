#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strnl(char *s)
{
	if (!s)
		return (0);
	while (*s != '\n' && *s)
		s++;
	return (*s);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i < (count * size))
		((char *)str)[i++] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s;
	int		i[2];

	i[0] = 0;
	i[1] = -1;
	if (!s1 || !s2)
		return (0);
	s = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(*s));
	if (!s)
		return (0);
	while (s1[++i[1]])
		s[i[1]] = s1[i[1]];
	free(s1);
	while (s2[i[0]])
		s[i[1]++] = s2[i[0]++];
	return (s);
}

char	*next_line(char *str) {
	char	*tmp;
	int		i[2];

	i[0] = -1;
	i[1] = -1;
	while (str[++i[0]] && str[i[0]] != '\n')
		;
	if (i == 0 || (!str[i[0] + 1] && str[i[0]] == '\n')) {
		free(str);
		return (NULL);
	}
	tmp = malloc(ft_strlen(str + i[0]));
	if (!tmp) {
		free(str);
		return (NULL);
	}
	while (str[i[0] + ++i[1]]) {
		tmp[i[1]] = str[i[0] + i[1]];
	}
	tmp[i[1]] = '\0';
	free(str);
	return (tmp);
}

char *input(char *str) {
	char	*tmp;
	int		i;

	i = -1;
	while (str[++i] && str[i] != '\n')
		;
	if (i == 0)
		return (NULL);
	tmp = malloc(i + 2);
	if (!tmp)
		return (NULL);
	i = -1;
	while (str[++i]) {
		if (str == '\n') {
			tmp[i] = str[i];
			break ;
		}
		tmp[i] = str[i];
	}
	tmp[++i] = '\0';
	return (tmp);
}

char	*ft_read(char *str, char *buf, int fd) {
	int	i;

	i = 1;
	while (i && !ft_strnl(str)) {
		i = read(fd, buf, BUFFER_SIZE + 1);
		if (i < 0) {
			free(buf);
			return (NULL);
		}
		buf[i] = 0;
		if (!str) {
			str = malloc(1);
			if (!str) {
				free (buf);
				return (NULL);
			}
			str[0] = 0;
		}
		str = ft_strjoin(str, buf);
	}
	free (buf);
	return (str);
}

char	*get_next_line(int fd) {
	static char *str;
	char		*buf;
	char		*lne;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read(str, buf, fd);
	if (ret < 0 || !ret)
		return (NULL);
	lne = input(str);
	str = next_line(str);
	return (lne);
}