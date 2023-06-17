#include "cub69d.h"

// void	chk_line(t_map ggggggggggggggggggggggggggggggggggggggggg*map, char *str);

// void	append_map(t_able *table, t_map *kid)
// {
// 	if (!table->elements->map)
// 	{
// 		table->elements->map = kid;
// 		kid->r_no = 0;
// 	}
// 	else if (table->elements->map)
// 	{
// 		// table->elements->map->prev = kid;//this will turn this shit into a circular
// 		while (table->elements->map->next)
// 			table->elements->map = table->elements->map->next;
// 		table->elements->map->next = kid;
// 		kid->r_no = table->elements->map->r_no + 1;
// 		kid->prev = table->elements->map;
// 	}
// }

// bool	draw_map(t_map *kid, char *buff)
// {
// 	int	i;

// 	i = -1;
// 	kid->row = f_strdup(buff);
// 	if (!kid->row)
// 		return (false);
// 	while (!f_strchr("01NSEW ", kid->row[i]))
// 		i++;
// 	if (kid->row[i] == '\n')
// 		i++;
// 	if (kid->row[i])
// 		free_ret(kid->row);
// 	return (true);
// }

bool	burn_map(t_able *table)
{
	t_mapling	*tmp;

	while (table->elements->map->mapling)
	{
		tmp = table->elements->map->mapling->next;
		free(table->elements->map->mapling->row);
		free(table->elements->map->mapling);
		table->elements->map->mapling = tmp;
	}
	// free(table->elements->buf);
	return (false);
}

// bool	absorb_row(t_able *table)
// {
// 	map_ufacturer(table);
// }

// bool	splt_rw(t_able *table, int	splt)
// {
// 	table->elements->map->row = f_calloc(splt + 1, sizeof(char));
// 	if (!table->elements->map->row)
// 		return (false);
// 	f_strlcpy(table->elements->map->row, table->elements->buf, splt + 1);
	
// }

t_mapling	*end_of_world(t_mapling *mapther)//returns the last element
{
	if (mapther)
		while (mapther->next)
			mapther = mapther->next;
	return (mapther);
}

int	map_ufacturer(t_mapling **map)//creates mapling and appends it to the mapther
{
	t_mapling	*mapling;

	mapling = malloc(1 * sizeof(t_mapling));
	if (!mapling)
		return (69);
	mapling->next = NULL;
	mapling->row = NULL;
	mapling->prev = NULL;
	if (*map)
	{
		mapling->prev = end_of_world(*map);
		mapling->r_no = end_of_world(*map)->r_no + 1;
		end_of_world(*map)->next = mapling;
	}
	else
	{
		*map = mapling;
		mapling->r_no = 0;
	}
	return (0);
}

// int	join_map(t_elements *elements, int join)
// {
// 	bool	cont;
// 	t_map	tmp;
// 	int		res;
// 	int		len[2];

// 	len[0] = 0;
// 	len[1] = 0;
// 	cont = 69;
// 	tmp = f_last(elements->map)->row;
// 	while (cont)
// 	{
// 		if (!join)
// 		{
// 			if (!map_ufacturer(elements->map))
// 				return (-1);
// 			tmp = end_of_world(elements->map);
// 			len[0] = get_closer(elements->buf + len[1]) + 1;
// 			tmp->row = f_calloc(len[0], sizeof(char));
// 			if (!tmp->row)
// 				return (-1);
// 			f_strlcpy(tmp->row, elements->buf + len[1], len[0]);
// 		}
// 		else
// 		{
// 			len = get_closer(elements->buf) + 1;
// 			elements->map = f_lstrjoin(elements->map, elements->buf, len);
// 		}
// 		res = chk_if_complete(elements->buf, &len[1]);
// 		if (res < 0)//checks if the buf is empty
// 			return (-69);
// 		else if (!res)
// 			return (69);
// 	}

// }

// bool	main_map(t_able *table)
// {
// 	int	se_pos[2];
// 	int	join;

// 	join = false;
// 	table->elements->map = NULL;
// 	while (table->elements->rd)//keep the loop going until it reached \n or \0
// 	{
// 		if (f_strchr(table->elements->buf, '\n') != f_strlen(table->elements->buf))
// 			join = join_map(table->elements, join);//if < 0 then error
// 			// table->elements->map = f_strdup(table->elements->buf);
// 		else
// 			splt_rw(table, f_strnl(table->elements->buf));
// 		absorb_row(table);
// 		free(table->elements->buf);
// 		table->elements->rd = read(table->elements->fd, \/
// 		table->elements->buf, BUFFER_SIZE);
// 	}
// }

void	chk_line(t_map *map, char *str)
{
	int	i;

	i = -1;
	// printf("map -> %s\n", str);
	while (str[++i] && f_strchr("01 NSEW", str[i]))
		if (f_strchr("NSEW", str[i]))
			map->plyr_no++;
	if (str[i])
		return ;//purge!!
}

void	map_intits(t_map *map, char *str)
{
	t_mapling	*tmp;

	tmp = NULL;
	chk_line(map, str);
	if (map_ufacturer(&map->mapling))
		return ;//purge!
	tmp = end_of_world(map->mapling);
	tmp->row = f_strdup(str);
	if (!tmp->row)
		return ;//purge!
}

// int	fnd_mapling_2(char **str, t_able *table, int *i)
// {
// 	char	*buf;

// 	buf = table->elements->buf;
// 	*str = f_bufstr(buf + i[0], *str, i[1]);//down
// 	map_intits(table->elements->map, *str);
// 	if (!table->elements->stop)
// 	free(*str);
// 	*str = NULL;
// 	i[0] += i[1];
// 	return (0);
// }

// int	fnd_mapling_3(char **str, t_able *table, int *i, int cnt)
// {
// 	char	*buf;

// 	buf = table->elements->buf;
// 	*str = f_bufstr(buf + i[0], *str, i[1]);//down
// 	if (cnt)
// 		return (cnt);
// 	map_intits(table->elements->map, *str);
// 	free(*str);
// 	*str = NULL;
// 	i[0] += i[1];
// 	return (0);
// }

// int	find_mapling(char **str, t_able *table, int cnt)
// {
// 	int		i[2];
// 	char	*buf;
// 	int		rd;

// 	i[0] = 0;
// 	buf = table->elements->buf;
// 	rd = table->elements->rd;
// 	while (i[0] < rd)
// 	{
// 		i[1] = 0;
// 		while (i[0] < rd && buf[i[0]] == '\n')
// 			i[0]++;
// 		if (cnt && i[0])
// 			cnt = fnd_mapling_2(str, table, i);
// 		while (i[0] + i[1] < rd && buf[i[0] + i[1]] != '\n')
// 			i[1]++;
// 		if (i[0] + i[1] == rd && buf[i[0] + i[1] - 1] != '\n')
// 			cnt = 69;
// 		else
// 			cnt = 0;
// 		if (fnd_mapling_3(str, table, i, cnt))
// 			return (cnt);
// 	}
// 	return (0);
// }

// void	map_init(t_able *table, char *str)
// {
// 	int	cont;

// 	// chk_line(table->elements->map, str);
// 	// map_intits(table->elements->map, str);// create the first mapling with the given str;
// 	// free(str);
// 	// str = NULL;
// 	printf("<%s>\n", str);
// 	cont = 0;
// 	while (69)
// 	{
// 		// printf("a\n");
// 		cont = find_mapling(&str, table, cont);
// 		free (table->elements->buf);
// 		table->elements->buf = f_calloc(BUFFER_SIZE + 1, sizeof(char));
// 		table->elements->rd = read(table->file, table->elements->buf, BUFFER_SIZE);
// 		if (table->elements->rd < 0)
// 			return ;//purge
// 		if (!table->elements->rd && cont)
// 		{
// 			//collect last mapling ig bruhhhhh! poop poopy cookie!
// 			break ;//reached the end, and if cont just finish the last line
// 		}
// 		if (!table->elements->rd)
// 			break ;// reached end without need to continue
// 	}
// 	// print_map(table);
// }