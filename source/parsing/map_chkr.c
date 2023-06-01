#include "cub69d.h"

// we have a doubly linked list and have to check if the 0z and NSEW is in 1z

// function to check if the map only includes elmnts required for the map! and chks if anything sus is included
int	hippity_scoppity(t_map *fuc_face)
{
	int	i[5];
	char *str;

	i[1] = 0;
	while (fuc_face)
	{
		i[0] = 0;
		str = fuc_face->row;
		while (str[i[0]])
		{
			if ((str[i[0]] == '1') || (str[i[0]] == '0'))
				i[0]++;
			else if ((str[i[0]] == 'N') || (str[i[0]] == 'S') || (str[i[0]] == 'E') || (str[i[0]] == 'W'))
			{
				i[0]++;
				i[1]++;
			}
		}
		if (str[i[0]] || i[1] > 1)
			return ();//err msg and free and end brogram!
		fuc_face = fuc_face->next;
	}
	if (!i[1])
		return ();//err msg and free and end brogram!
}

// fucntion to check if the 0z are surrounded by 1z bruh!// make sure the map linked list is a doubly linked list!
int		tundly(t_map *mundly)
{
	int i[69];
	char *str;
	t_map *prev;

	i[0] = 0;
	prev = mundly;
	while (mundly)
	{
		i[1] = 0;
		str = lmnts->map->row; // create a part in map or in lmnts to indicate the max amount of rows!
		if (!i[0] || i[0] == lmnts->map->max)
		{
			while (str[i[1]] && (str[i[1]] == '1' || str[i[1]] == ' '))
				i[1]++;
			if (str[i[1]])
				return ();//err msg and free and end brogram
		}
		else
		{
			chk_row_above(mundly->row, mundly->prev->row);
		}
		mundly = mundly->next;
	}
}

// chk_row_above_//forst chk if the line starts with a 1 and not a zero ro NSWE

int	chk_row_above(char *cur, char *perv)
{
	i[1] = f_strlen(str) - 1;
	while (str[i[0]] == ' ')
		i[0]++;
	while (str[i[1]] == ' ')
		i[1]--;
	if (str[i[0]] != '1' || str[i[1]] != '1')
		return ();//err msg and free and end brogram
	connect_the_wallz(perv, i[0], i[1]);
}
// the part here checks if the map doesnt start or end with 1z


//dep \\\\\\\\\\\/
//now find ' ' and go around them to chk if they are surrounded by 1z as we check all corners and beninging and end for 1z!


// connect the dots, go make sure the 1z connect to the other outter wallz this will make the outter wall and make life vewy vewy eawy!
// then u can go and finnd the holes in the hawts!


int	*find_the_imposter(t_map *map)
{
	int	i;
	int	cord[2];

	cord[0] = -1;
	while (map)
	{
		i = 0;
		while (map->row[i] && (map->row[i] == '1' \
		 || map->row[i] == '0' || map->row[i] == ' ')
			i++:
		if (map->row[i])
			break ;
		map = map->next;
	}
	if (!map->row)
		return (cord);
	cord[0] = map->r_no;
	cord[1] = i;
	return (cord);
}

int	connect_the_wallz(char *str, int start, int end)
{
	int	*cords;
	int	*doubly_cord;
	int	*doubly_chk;

	cords = find_the_imposter(map);
	if (cords[0] < 0)
		return (-1);
	while (map)
	{
		if (map->r_no == cords[0])
			break ;
		map = map->next;
	}
	cords = go_curse(map, cords[1]);
}

int	*go_curse(t_map *map, int x)
{
	int i[2];

	if (map->row[x + 1] && map->row[x + 1] == '1') {
		map->row[x + 1] = 0;
		go_curse(map, x + 1);
	}
	if (map->next && map->next->row[x] && map->next->row[x] == '1') {
		map->next->row[x] = 0;
		go_curse(map->next, x);
	}
	if (map->row[x - 1] && map->row[x - 1] == '1') {
		map->row[x - 1] = 0;
		go_curse(map, x - 1);
	}
	if (map->prev && map->prev[x] && map->prev[x] == '1') {
		map->prev[x] = 0;
		go_curse(map->prev, x);
	}
	i[0] = map->r_no;
	i[1] = x;
	return (i);
}