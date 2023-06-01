#include "cub69d.h"

bool	chk_other_eelements(t_able *table)
{
	char	*buf;
	ssize_t	rd;

	// txt = 0;
	buf = NULL;
	rd = 69;
	while (rd)
	{
		buf = f_calloc(BUFFER_SIZE, sizeof(char));
		rd = read(table->phile, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free (buf);
			return (false);// take care of previously allocated mem
		}
		if (!rd)
			break ;
		 if (!find_eelements(table, buf, rd))
		 	return (false);
		free (buf);
	}
}

bool	find_eelements(t_able *table, char *buf, ssize_t rd)
{
	ssize_t	i;

	if (!rd)
		return (true);
	i = -1;
	while (++i < rd)
	{
		while (buf[i] == '\n' && i < rd)
			i++;
		while (buf[i] == ' ' && i < rd)
			i++;
		if (i == rd)
			break ;
		if (buf[i] == 'C' || buf[i] == 'F')
			if (!(clr_init(&buf[i], table, &i)))
				return (false);
		else if (buf[i] == 'N' || buf[i] == 'S'\
		 || buf[i] == 'W' || buf[i] == 'E')
			if (!(txt_init(&buf[i], table)))
				return (false);
		else if (buf[i])
			return (err_msg("ehh"));//chk if all othr elmnt r collectd!
	}
}

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

bool	rgb_init(char *buf, t_clr *clr, int *i)
{
	int	j;

	j = -1;
	while (++j < 3)
	{
		clr->rgb[j] = f_atoi(buf);
		if (clr->rgb[j] < 0)
			return (err_msg("ehh, negative?"));
		while (buf[*i] && (buf[*i] >= '0' && buf[*i] <= '9'))
			(*i)++;
		if (j != 2 && buf[*i] && (buf[*i] == ','))
			return (false);
		if (j == 2 && buf[*i] && (buf[*i] != ' '))
			return (false);
		if (buf[*i] == ',')
			(*i)++;
	}
	while (buf[*i] && buf[*i] == ' ')
		(*i)++;
	if (buf[*i])
		return (false);
	return (true);
}

bool	txt_init(char *buf, t_able *table, int )

bool	clr_init(char *buf, t_able *table, int *l)
{
	t_clr	*clr;
	int		i;

	i = 0;
	clr = f_calloc(1, sizeof(t_clr));
	clr->id = *buf;
	while (buf[++i] && buf[i] == ' ')
		if (!buf[i])
			return (free_ret(clr));
	if (!rgb_init(buf + i, clr, &i))
		return (free_ret(clr));
}

bool	quality_control(t_able *table)
{
	if (!chk_other_eelements(table))
		return (false);
}