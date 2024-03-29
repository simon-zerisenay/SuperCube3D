#include "cub69d.h"

void	color_init(int **clr, char *str)
{
	int	i;

	i = -1;
	str += 2;
	// printf("rgzz = ");
	while (*str && *str == ' ')
		str++;
	while (++i < 3)
	{
		*clr[i] = f_atoi(str);
		while (*str && f_isdigit(*str))
			str++;
		if (i < 2)
		{
			if (*str != ',')
				return ;//purge
		}
		else if (*str && *str != ' ')
			return ;//purge
	}
	while (*str && *str ==' ')
		str++;
	if (*str)
		return ;//purge!
	// printf("rgzz = ");
	// for (int k = 0; k < 3; k++)
	// 	printf("%d,", *clr[k]);
	// printf("\n");
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
	*txt = f_calloc(i[0] + 1, sizeof(**txt));
	if (!*txt)
		return ;//purge
	while (++i[1] < i[0])
		*txt[i[1]] = str[i[1]];
	while (str[i[0]] && str[i[0]] == ' ')
		i[0]++;
	if (str[i[0]])
		return ;//purge!!
}

void	chk_elements(t_able *table)
{
	table->pp = 69;
	if (!table->elements->txtr->n_path || !table->elements->txtr->s_path \
		|| !table->elements->txtr->e_path || !table->elements->txtr->w_path)
		return ;//purge incomplete!
	if (!table->elements->clr->c_rgb || !table->elements->clr->f_rgb)
		return ;//purge incomplete!
}

void	element_init(t_able *table, char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] == ' ')
		;
	if (!str[i])
		return ;
	printf("<%s>\n", str + i);
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
		// purge if not!!!!
}

int	fnd_line_2(char **str, t_able *table, int *i)
{
	char	*buf;

	buf = table->elements->buf;
	*str = f_bufstr(buf + i[0], *str, i[1]);//down
	// printf("cnt = %d\n", cnt);
	// printf("<%s>\n", *str);
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
	// printf("cnt = %d\n", cnt);
	// printf("<%s>\n", *str);
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

bool	chk_other_eelements(t_able *table)
{
	char	*str;
	int		cont;
	// int		end;

	cont = 0;
	// i = 69;
	// while (69)
	// {
		str = NULL;
		while (69)
		{
			table->elements->buf = f_calloc(BUFFER_SIZE, sizeof(char));
			table->elements->rd = read(table->file, table->elements->buf, BUFFER_SIZE);
			if (table->elements->rd < 0)
				break ;
				//purge
			if (!table->elements->rd && !cont)
				break ;
			if (!table->elements->rd && cont)
				break ;
				// elemnt init
			cont = find_line(&str, table, cont);
			// printf("-%s-\n", str + i);
			free(table->elements->buf);
		}
	// }
	// txt = 0;
	// rd = 69;
	// while (rd)
	// {
	// 	if (rd < 0)
	// 	{
	// 		free (buf);
	// 		return (false);// take care of previously allocated mem
	// 	}
	// 	if (!rd)
	// 		break ;
	// 	 if (!find_eelements(table, buf, rd))
	// 	 	return (false);
	// 	free (buf);
	// }
	// table->pp = 69;
	return (true);
}

void	quality_control(t_able *table)
{
	// printf("%d\n", table->pp);
	// chk_other_eelements(table);
	if (!chk_other_eelements(table))
		return ;//purge instead
	// printf("af %d\n", table->pp);
}

// bool	find_eelements(t_able *table, char *buf, ssize_t rd)
// {
// 	ssize_t	i;

// 	if (!rd)
// 		return (true);
// 	i = -1;
// 	while (++i < rd)
// 	{
// 		while (buf[i] == '\n' && i < rd)
// 			i++;
// 		while (buf[i] == ' ' && i < rd)
// 			i++;
// 		if (i == rd)
// 			break ;
// 		if (buf[i] == 'C' || buf[i] == 'F')
// 			if (!(clr_init(&buf[i], table, &i)))
// 				return (false);
// 		else if (buf[i] == 'N' || buf[i] == 'S'\/
// 		 || buf[i] == 'W' || buf[i] == 'E')
// 			if (!(txt_init(&buf[i], table)))
// 				return (false);
// 		else if (buf[i])
// 			return (err_msg("ehh"));//chk if all othr elmnt r collectd!
// 	}
// }

// bool	rgbtq(char *buf, t_clr *clr, int *l)
// {
// 	int	i;

// 	i = 0;
// 	clr->r = f_atoi(buf);
// 	while (buf[i] >= '0' && buf[i] <= '9')
// 		i++;
// 	if (buf[i] != ',')
// 		return (false);
// 	clr->g = f_atoi(buf + i);
// 	while (buf[i] >= '0' && buf[i] <= '9')
// 		i++;
// 	if (buf[i] != ',')
// 		return (false);
// 	clr->b = f_atoi(buf + i);
// 	while (buf[i] >= '0' && buf[i] <= '9')
// 		i++;
// 	*l += i;
// 	while (buf[i] == ' ' && buf[i] != '\n' && buf[i])
// 		i++;
// 	if (!buf[i])
// 		return (false);
// 	if (buf[i] == '\n')
// 		return (false);
// 	return (true);
// }

// bool	rgb_init(char *buf, t_clr *clr, int *i)
// {
// 	int	j;

// 	j = -1;
// 	while (++j < 3)
// 	{
// 		clr->rgb[j] = f_atoi(buf);
// 		if (clr->rgb[j] < 0)
// 			return (err_msg("ehh, negative?"));
// 		while (buf[*i] && (buf[*i] >= '0' && buf[*i] <= '9'))
// 			(*i)++;
// 		if (j != 2 && buf[*i] && (buf[*i] == ','))
// 			return (false);
// 		if (j == 2 && buf[*i] && (buf[*i] != ' '))
// 			return (false);
// 		if (buf[*i] == ',')
// 			(*i)++;
// 	}
// 	while (buf[*i] && buf[*i] == ' ')
// 		(*i)++;
// 	if (buf[*i])
// 		return (false);
// 	return (true);
// }

// bool	txt_init(char *buf, t_able *table, int )

// bool	clr_init(char *buf, t_able *table, int *l)
// {
// 	t_clr	*clr;
// 	int		i;

// 	i = 0;
// 	clr = f_calloc(1, sizeof(t_clr));
// 	clr->id = *buf;
// 	while (buf[++i] && buf[i] == ' ')
// 		if (!buf[i])
// 			return (free_ret(clr));
// 	if (!rgb_init(buf + i, clr, &i))
// 		return (free_ret(clr));
// }