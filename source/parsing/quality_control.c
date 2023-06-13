#include "cub69d.h"

void	element_init(t_able *table, char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] == ' ')
		;
	if (!str[i])
		return ;
	if (!f_strncmp("NO ", str, 3) || !f_strncmp("SO ", str, 3)\
		|| !f_strncmp("EA ", str, 3) || !f_strncmp("WE ", str, 3))
		texture_init(table, str);
	else if (!f_strncmp("F ", str, 2) || !f_strncmp("C ", str, 2))
		color_init(table, str);
	else//purge if not !!!!!
		chk_if_map(table, str);//purge if not!!!
		// purge if not!!!!
}

int	fnd_line_2(char **str, char *buf, int *i)
{
	*str = f_bufstr(buf + i[0], *str, i[1]);//down
	// printf("cnt = %d\n", cnt);
	printf("<%s>\n", *str);
	//elemnt intit
	free(*str);
	*str = NULL;
	i[0] += i[1];
	return (0);
}

int	fnd_line_3(char **str, char *buf, int *i, int cnt)
{
	*str = f_bufstr(buf + i[0], *str, i[1]);//down
	if (cnt)
		return (cnt);
	// printf("cnt = %d\n", cnt);
	printf("<%s>\n", *str);
	//elemnt intit
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
			cnt = fnd_line_2(str, buf, i);
		while (i[0] + i[1] < rd && buf[i[0] + i[1]] != '\n')
			i[1]++;
		if (i[0] + i[1] == rd && buf[i[0] + i[1]] - 1 != '\n')
			cnt = 69;
		else
			cnt = 0;
		if (fnd_line_3(str, buf, i, cnt))
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
			// printf("-%s-\n", str);
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
	return (true);
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

void	quality_control(t_able *table)
{
	if (!chk_other_eelements(table))
		return ;//purge instead
	// return (true);
}