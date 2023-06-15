#include "cub69d.h"

void	create_clr(t_clr **clr)
{
	int	i;

	i = -1;
	*clr = malloc(1 * sizeof(t_clr));
	if (!*clr)
		return ;//purge 1
	(*clr)->c_rgb = malloc(3 * sizeof(int));
	if (!(*clr)->c_rgb)
		return ;//purge 2
	(*clr)->f_rgb = malloc(3 * sizeof(int));
	if (!(*clr)->c_rgb)
		return ;//purge 3
	while (++i < 3)
	{
		(*clr)->c_rgb[i] = 0;
		(*clr)->f_rgb[i] = 0;
	}
}

void	create_txtr(t_xtr **txt)
{
	*txt = malloc(1 * sizeof(t_xtr));
	if (!*txt)
		return ;//purge
	(*txt)->n_path = NULL;
	(*txt)->s_path = NULL;
	(*txt)->e_path = NULL;
	(*txt)->w_path = NULL;
}

void	create_map(t_map **map)
{
	map[0] = malloc(1 * sizeof(**map));
	if (!map[0])
		return ;//purge
	map[0]->map_max = 0;
	map[0]->mapling = NULL;
	map[0]->plyr_no = 0;
	map[0]->plyr_pos = 0;
}

void	create_element(t_elmnt **elemnt)
{
	*elemnt = malloc(1 * sizeof(t_elmnt));
	if (!*elemnt)
		return ;//purge
	(*elemnt)->buf = NULL;
	(*elemnt)->clr = NULL;
	(*elemnt)->map = NULL;
	(*elemnt)->txtr = NULL;
	(*elemnt)->stop = 0;
	(*elemnt)->rd = 0;
	// (*elemnt)->map_max = 0;
}

void	print_elements(t_able *table)// made just for testing!
{
	printf("n_path - <%s>\n", table->elements->txtr->n_path);
	printf("s_path - <%s>\n", table->elements->txtr->s_path);
	printf("e_path - <%s>\n", table->elements->txtr->e_path);
	printf("w_path - <%s>\n", table->elements->txtr->w_path);
	printf("c_rgb - <%d,%d,%d>\n", table->elements->clr->c_rgb[0], table->elements->clr->c_rgb[1], table->elements->clr->c_rgb[2]);
	printf("f_rgb - <%d,%d,%d>\n", table->elements->clr->f_rgb[0], table->elements->clr->f_rgb[1], table->elements->clr->f_rgb[2]);
	// printf("n_path - <%p>\n", &table->elements->txtr->n_path);
	// printf("s_path - <%p>\n", &table->elements->txtr->s_path);
	// printf("e_path - <%p>\n", &table->elements->txtr->e_path);
	// printf("w_path - <%p>\n", &table->elements->txtr->w_path);
	// printf("c_rgb - <%p,%p,%p>\n", &table->elements->clr->c_rgb[0], &table->elements->clr->c_rgb[1], &table->elements->clr->c_rgb[2]);
	// printf("f_rgb - <%p,%p,%p>\n", &table->elements->clr->f_rgb[0], &table->elements->clr->f_rgb[1], &table->elements->clr->f_rgb[2]);
	// printf("%s\n", );
	// printf("%s\n", );
	// printf("%s\n", );
}

void	print_map(t_able *table)
{
	t_mapling	*tmp;

	printf("<-----------------map---------------->\n");
	tmp = table->elements->map->mapling;
	while (tmp)
	{
		printf("<%s\n>", tmp->row);
		tmp = tmp->next;
	}
}


int main(int argc, char *argv[])
{
	t_able	table;

	if (!valid_args(argc, argv))
		return (69);
	table.file = open(argv[1], O_RDONLY);
	if (table.file < 0)
		return (per_ret());
	create_element(&table.elements);
	create_clr(&table.elements->clr);
	create_txtr(&table.elements->txtr);
	create_map(&table.elements->map);
	// printf("\n");
	quality_control(&table);
	print_elements(&table);
	print_map(&table);
	// rmrf_everything();
	// print_elements(&table);
	    /*
        1. Create an empty window 
            => mlx_init()
        2. struct to save each texture 
        3. 

    */
	// ft_initializer(&table);
	// table.mlx = mlx_init();
	// if (!table.mlx)
	// 		// call the handle_error (freeing + return message)
	// table.win = mlx_new_window(table.mlx, table.size_x,
	// 			table.size_y, "By 69ers");
	// ft_render_next_frame(&table);//the exec big dawg!
	// 	mlx_loop(table.mlx);
	return (69 * 0);
}
