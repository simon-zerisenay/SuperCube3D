#include "cub69d.h"

void	append_map(t_able *table, t_map *kid)
{
	if (!table->lmnts->map)
	{
		table->lmnts->map = kid;
		kid->r_no = 0;
	}
	else if (table->lmnts->map)
	{
		// table->lmnts->map->prev = kid;//this will turn this shit into a circular
		while (table->lmnts->map->next)
			table->lmnts->map = table->lmnts->map->next;
		table->lmnts->map->next = kid;
		kid->r_no = table->lmnts->map->r_no + 1;
		kid->prev = table->lmnts->map;
	}
}

bool	draw_map(t_map *kid, char *buff)
{
	int	i;

	i = -1;
	kid->row = f_strdup(buff);
	if (!kid->row)
		return (false);
	while (!f_strchr("01NSEW ", kid->row[i]))
		i++;
	if (kid->row[i] == '\n')
		i++;
	if (kid->row[i])
		free_ret(kid->row);
	return (true);
}

bool	burn_map(t_able *table)
{
	t_map	tmp;

	while (table->lmnts->map)
	{
		tmp = table->lmnts->map->next;
		free(table->lmnts->map->row);
		free(table->lmnts->map);
		table->lmnts->map = tmp;
	}
	free(table->buf);
	return (false);
}

bool	absorb_row(t_able *table)
{
	map_ufacturer(table);
}

bool	splt_rw(t_able *table, int	splt)
{
	table->lmnts->map->row = f_calloc(splt + 1, sizeof(char));
	if (!table->lmnts->map->row)
		return (false);
	f_strlcpy(table->lmnts->map->row, table->lmnts->buf, splt + 1);
	
}

t_map	*end_of_world(t_map *mapther)
{
	if (mapther)
		while (mapther->next)
			mapther = mapther->next;
	return (mapther);
}

int	map_ufacturer(t_map *map)//creates mapling and appends it to the mapther
{
	t_map	*mapling;

	mapling = f_calloc(sizeof(t_map * 1));
	if (!mapling)
		return (0);
	mapling->next = NULL;
	mapling->prev = NULL;
	if (!map)
	{
		map = mapling;
		map->r_no = 0;
	}
	else
	{
		while (map->next)
			map = map->next;
		map->next = mapling;
		mapling->prev = map;
		mapling->r_no = map->r_no + 1;
	}
	return (69);
}

int	join_map(t_lmnts *lmnts, int join)
{
	bool	continue;
	t_map	tmp;
	int		res;
	int		len[2];

	len[0] = 0;
	len[1] = 0;
	continue = 69;
	tmp = f_last(lmnts->map)->row;
	while (continue)
	{
		if (!join)
		{
			if (!map_ufacturer(lmnts->map))
				return (-1);
			tmp = end_of_world(lmnts->map);
			len[0] = get_closer(lmnts->buf + len[1]) + 1;
			tmp->row = f_calloc(len[0], sizeof(char));
			if (!tmp->row)
				return (-1);
			f_strlcpy(tmp->row, lmnts->buf + len[1], len[0]);
		}
		else
		{
			len = get_closer(lmnts->buf) + 1;
			lmnts->map = f_lstrjoin(lmnts->map, lmnts->buf, len);
		}
		res = chk_if_complete(lmnts->buf, &len[1]);
		if (res < 0)//checks if the buf is empty
			return (-69);
		else if (!res)
			return (69);
	}

}

bool	main_map(t_able *table)
{
	int	se_pos[2];
	int	join;

	join = false;
	table->lmnts->map = NULL;
	while (table->lmnts->rd)//keep the loop going until it reached \n or \0
	{
		if (f_strchr(table->lmnts->buf, '\n') != f_strlen(table->lmnts->buf))
			join = join_map(table->lmnts, join);//if < 0 then error
			// table->lmnts->map = f_strdup(table->lmnts->buf);
		else
			splt_rw(table, f_strnl(table->lmnts->buf));
		absorb_row(table);
		free(table->lmnts->buf);
		table->lmnts->rd = read(table->lmnts->fd, \
		table->lmnts->buf, BUFFER_SIZE);
	}
}
