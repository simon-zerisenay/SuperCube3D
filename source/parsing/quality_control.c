#include "cub69d.h"

void	color_init(int **clr, char *str)
{
	int	i;

	i = -1;
	str += 2;
	while (*str && *str == ' ')
		str++;
	while (++i < 3)
	{
		clr[0][i] = f_atoi(str);
		while (*str && f_isdigit(*str))
			str++;
		if (i < 2)
		{
			if (*str != ',')
				return ;//purge
			str++;
		}
		else if (*str && *str != ' ')
			return ;//purge
	}
	while (*str && *str ==' ')
		str++;
	if (*str)
		return ;//purge!
}

void	texture_init(char **txt, char *str)
{
	int	i[2];

	i[0] = -1;
	i[1] = -1;
	str += 3;
	while (*str && *str == ' ')
		str++;
	while (str[++i[0]])
		if (str[i[0]] == ' ' && str[i[0] - 1] != '\\')
			break ;
	if (!str[i[0]] && !i[0])
		return ;//purge
	txt[0] = f_calloc(i[0] + 1, sizeof(*txt));
	if (!txt)
		return ;//purge
	while (++i[1] < i[0])
		txt[0][i[1]] = str[i[1]];
	while (str[i[0]] && str[i[0]] == ' ')
		i[0]++;
	if (str[i[0]])
		return ;//purge!!
}

void	chk_elements(t_able *table)
{
	// table->pp = 69;
	table->elements->stop = 1;
	if (!table->elements->txtr->n_path || !table->elements->txtr->s_path \
		|| !table->elements->txtr->e_path || !table->elements->txtr->w_path)
		return ;//purge incomplete!
	if (!table->elements->clr->c_rgb || !table->elements->clr->f_rgb)
		return ;//purge incomplete!
	// find_mapling_3(&str, table, )
}

void	element_init(t_able *table, char *str)
{
	int	i;

	i = -1;
	if (!table->elements->stop)
	{
		while (str[++i] && str[i] == ' ')
			;
		if (!str[i])
			return ;
		if (!f_strncmp("NO ", str + i, 3))
			texture_init(&table->elements->txtr->n_path, str + i);
		else if (!f_strncmp("SO ", str + i, 3))
			texture_init(&table->elements->txtr->s_path, str + i);
		else if (!f_strncmp("EA ", str + i, 3))
			texture_init(&table->elements->txtr->e_path, str + i);
		else if (!f_strncmp("WE ", str + i, 3))
			texture_init(&table->elements->txtr->w_path, str + i);
		else if (!f_strncmp("C ", str + i, 2))
			color_init(&table->elements->clr->c_rgb, str + i);
		else if (!f_strncmp("F ", str + i, 2))
			color_init(&table->elements->clr->f_rgb, str + i);
		else//purge if not !!!!!
			chk_elements(table);//purge if not!!!
	}
	if (table->elements->stop)
		map_intits(table->elements->map, str);
}

int	fnd_line_2(char **str, t_able *table, int *i)
{
	char	*buf;

	buf = table->elements->buf;
	*str = f_bufstr(buf + i[0], *str, i[1]);//down
	element_init(table, *str);
	free(*str);
	*str = NULL;
	i[0] += i[1];
	return (0);
}

int	fnd_line_3(char **str, t_able *table, int *i, int cnt)
{
	char	*buf;

	buf = table->elements->buf;
	*str = f_bufstr(buf + i[0], *str, i[1]);//down
	if (cnt)
		return (cnt);
	element_init(table, *str);
	free(*str);
	*str = NULL;
	i[0] += i[1];
	return (0);
}

int	find_line(char **str, t_able *table, int cnt)
{
	int		i[2];
	char	*buf;
	int		rd;

	i[0] = 0;
	buf = table->elements->buf;
	rd = table->elements->rd;
	while (i[0] < rd)
	{
		i[1] = 0;
		while (i[0] < rd && buf[i[0]] == '\n')
			i[0]++;
		if (cnt && i[0])
			cnt = fnd_line_2(str, table, i);
		while (i[0] + i[1] < rd && buf[i[0] + i[1]] != '\n')
			i[1]++;
		if (i[0] + i[1] == rd && buf[i[0] + i[1] - 1] != '\n')
			cnt = 69;
		else
			cnt = 0;
		if (fnd_line_3(str, table, i, cnt))
			return (cnt);
	}
	return (0);
}

void	chk_other_eelements(t_able *table)
{
	char	*str;
	int		cont;

	cont = 0;
	str = NULL;
	while (69)
	{
		table->elements->buf = f_calloc(BUFFER_SIZE, sizeof(char));
		table->elements->rd = read(table->file, table->elements->buf, BUFFER_SIZE);
		if (table->elements->rd < 0)
			return ;//purge
		if (!table->elements->rd)
			return ;//then chk if last line has been retrieved
		cont = find_line(&str, table, cont);
		free(table->elements->buf);
	}
	return ;
}

void	quality_control(t_able *table)
{
	chk_other_eelements(table);
	// map_init(table, str);
	// map_init(table);
}
// void	map_init(t_able *table)
// {
// 	char	*str;
// 	int		cont;

// 	cont = 0;
// 	str = NULL;
// 	chk_if_map
// 	while (69)
// 	{
// 		table->elements->buf = f_calloc(BUFFER_SIZE, sizeof(char));
// 		table->elements->rd = read(table->file, table->elements->buf, BUFFER_SIZE);
// 		if (table->elements->rd < 0)
// 			break ;
// 			//purge
// 		if (!table->elements->rd && !cont)
// 			break ;
// 		if (!table->elements->rd && cont)
// 			break ;
// 		cont = find_line(&str, table, cont);
// 		free(table->elements->buf);
// 	}
// 	return (true);
// }
