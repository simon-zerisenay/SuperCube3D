#include "cub69d.h"

void	append_map(t_able *table, t_map *kid)
{
	if (!table->elements->map)
	{
		table->elements->map = kid;
		kid->r_no = 0;
	}
	else if (table->elements->map)
	{
		// table->elements->map->prev = kid;//this will turn this shit into a circular
		while (table->elements->map->next)
			table->elements->map = table->elements->map->next;
		table->elements->map->next = kid;
		kid->r_no = table->elements->map->r_no + 1;
		kid->prev = table->elements->map;
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

	while (table->elements->map)
	{
		tmp = table->elements->map->next;
		free(table->elements->map->row);
		free(table->elements->map);
		table->elements->map = tmp;
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
	table->elements->map->row = f_calloc(splt + 1, sizeof(char));
	if (!table->elements->map->row)
		return (false);
	f_strlcpy(table->elements->map->row, table->elements->buf, splt + 1);
	
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

int	join_map(t_elements *elements, int join)
{
	bool	continue;
	t_map	tmp;
	int		res;
	int		len[2];

	len[0] = 0;
	len[1] = 0;
	continue = 69;
	tmp = f_last(elements->map)->row;
	while (continue)
	{
		if (!join)
		{
			if (!map_ufacturer(elements->map))
				return (-1);
			tmp = end_of_world(elements->map);
			len[0] = get_closer(elements->buf + len[1]) + 1;
			tmp->row = f_calloc(len[0], sizeof(char));
			if (!tmp->row)
				return (-1);
			f_strlcpy(tmp->row, elements->buf + len[1], len[0]);
		}
		else
		{
			len = get_closer(elements->buf) + 1;
			elements->map = f_lstrjoin(elements->map, elements->buf, len);
		}
		res = chk_if_complete(elements->buf, &len[1]);
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
	table->elements->map = NULL;
	while (table->elements->rd)//keep the loop going until it reached \n or \0
	{
		if (f_strchr(table->elements->buf, '\n') != f_strlen(table->elements->buf))
			join = join_map(table->elements, join);//if < 0 then error
			// table->elements->map = f_strdup(table->elements->buf);
		else
			splt_rw(table, f_strnl(table->elements->buf));
		absorb_row(table);
		free(table->elements->buf);
		table->elements->rd = read(table->elements->fd, \
		table->elements->buf, BUFFER_SIZE);
	}
}
