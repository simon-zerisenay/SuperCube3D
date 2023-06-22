#include "cub69d.h"

void	create_clr(t_clr **clr)
{
	int	i;

	i = -1;
	clr[0] = malloc(1 * sizeof(t_clr));
	if (!clr[0])
		return ;//purge 1
	(clr[0])->c_rgb = malloc(3 * sizeof(int));
	if (!(clr[0])->c_rgb)
		return ;//purge 2
	(clr[0])->f_rgb = malloc(3 * sizeof(int));
	if (!(clr[0])->c_rgb)
		return ;//purge 3
	while (++i < 3)
	{
		(clr[0])->c_rgb[i] = 0;
		(clr[0])->f_rgb[i] = 0;
	}
}

void	create_txtr(t_xtr **txt)
{
	txt[0] = malloc(1 * sizeof(t_xtr));
	if (!txt[0])
		return ;//purge
	(txt[0])->n_path = NULL;
	(txt[0])->s_path = NULL;
	(txt[0])->e_path = NULL;
	(txt[0])->w_path = NULL;
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
	elemnt[0] = malloc(1 * sizeof(t_elmnt));
	if (!elemnt[0])
		return ;//purge
	(elemnt[0])->buf = NULL;
	(elemnt[0])->clr = NULL;
	(elemnt[0])->map = NULL;
	(elemnt[0])->txtr = NULL;
	(elemnt[0])->stop = 0;
	(elemnt[0])->rd = 0;
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
		printf("<%s>\n", tmp->row);
		tmp = tmp->next;
	}
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void moves(t_able *table, int x, int y)
{
	table->x += x;
	table->y += y;
	my_mlx_pixel_put(&table->img, table->x, table->y, 0x00FF0000);
}

int key_hook(int keycode, t_able *table)
{
	// printf("%d\n", keycode);
	if (keycode == 13)
		moves(table, 0, -1);
	if (keycode == 0)
		moves(table, -1, 0);
	if (keycode == 1)
		moves(table, 0, 1);
	if (keycode == 2)
		moves(table, 1, 0);
	return (0);
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
	// print_elements(&table);
	// print_map(&table);

	table.x = 64;
	table.y = 64;
	table.mlx = mlx_init();
	table.win = mlx_new_window(table.mlx, 1920, 1080, "poopy!");
	table.img.img = mlx_new_image(table.mlx, 1920, 1080);
	table.img.addr = mlx_get_data_addr(table.img.img, &table.img.bits_per_pixel, &table.img.line_length,
								&table.img.endian);
	mlx_key_hook(table.win, key_hook,  &table);
	my_mlx_pixel_put(&table.img, table.x, table.y, 0x00FF0000);
	mlx_put_image_to_window(table.mlx, table.win, table.img.img, 0, 0);
	// my_mlx_pixel_put(&table.img, 64, 64, 0x00FF0000);
	mlx_loop(table.mlx);

	rmrf_everything(&table);
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
