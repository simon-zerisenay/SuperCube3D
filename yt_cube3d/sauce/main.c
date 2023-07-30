#include "cub69d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

// int	plr_adj(t_table *table, int pp) {

// }

int	handle_no_event(t_table *table)//2.0
{
	/* This function needs to exist, but it is useless for the moment */
	t_cords	xy;
	t_cords	del_xy;
	double	ang;

	xy.x = table->x;
	xy.y = table->y;
	del_xy.x = table->del_x;
	del_xy.y = table->del_y;
	ang = table->a;
	if (table->keys[3] && table->keys[0]) {
		table->a -= 0.1;
		if (table->a < 0)
			table->a += PIe;
		table->del_x = cos(table->a);
		table->del_y = sin(table->a);
		int pp = (int)((table->y + table->del_y) / table->elmnt_sz);
		pp *= 8;
		pp += (int)((table->x + table->del_x) / table->elmnt_sz);
		if (table->map->map[pp] == 1)
			return (69);
		table->x += table->del_x * table->mv_speed;
		table->y += table->del_y * table->mv_speed;
		blayer_movement(table, &xy, &del_xy, ang);
	} else if (table->keys[3] && table->keys[2]) {
		table->a += 0.1;
		if (table->a > PIe)
			table->a -= PIe;
		table->del_x = cos(table->a);
		table->del_y = sin(table->a);
		int pp = (int)((table->y + table->del_y) / table->elmnt_sz);
		pp *= 8;
		pp += (int)((table->x + table->del_x) / table->elmnt_sz);
		if (table->map->map[pp] == 1)
			return (69);
		table->x += table->del_x * table->mv_speed;
		table->y += table->del_y * table->mv_speed;
		blayer_movement(table, &xy, &del_xy, ang);
	} else if (table->keys[1] && table->keys[0]) {
		table->a -= 0.1;
		if (table->a < 0)
			table->a += PIe;
		table->del_x = cos(table->a);
		table->del_y = sin(table->a);
		int pp = (int)((table->y - table->del_y) / table->elmnt_sz);
		pp *= 8;
		pp += (int)((table->x - table->del_x) / table->elmnt_sz);
		if (table->map->map[pp] == 1)
			return (69);
		table->x -= table->del_x * table->mv_speed;
		table->y -= table->del_y * table->mv_speed;
		blayer_movement(table, &xy, &del_xy, ang);
	} else if (table->keys[1] && table->keys[2]) {
		table->a += 0.1;
		if (table->a > PIe)
			table->a -= PIe;
		table->del_x = cos(table->a);
		table->del_y = sin(table->a);
		int pp = (int)((table->y - table->del_y) / table->elmnt_sz);
		pp *= 8;
		pp += (int)((table->x - table->del_x) / table->elmnt_sz);
		if (table->map->map[pp] == 1)
			return (69);
		table->x -= table->del_x * table->mv_speed;
		table->y -= table->del_y * table->mv_speed;
		blayer_movement(table, &xy, &del_xy, ang);
	} else if (table->keys[3]) {//w
		int pp = (int)((table->y + table->del_y) / table->elmnt_sz);
		pp *= 8;
		pp += (int)((table->x + table->del_x) / table->elmnt_sz);
		// pp = plr_adj(table, pp);
		if (table->map->map[pp] == 1)
			return (69);
		table->x += table->del_x * table->mv_speed;
		table->y += table->del_y * table->mv_speed;
		blayer_movement(table, &xy, &del_xy, ang);
	} else if (table->keys[0]) {//a
		table->a -= 0.1;
		if (table->a < 0)
			table->a += PIe;
		table->del_x = cos(table->a);
		table->del_y = sin(table->a);
		le_ray_caste_angel(table, &xy, &del_xy, ang);
	} else if (table->keys[1]) {//s
		int pp = (int)((table->y - table->del_y) / table->elmnt_sz);
		pp *= 8;
		pp += (int)((table->x - table->del_x) / table->elmnt_sz);
		if (table->map->map[pp] == 1)
			return (69);
		table->x -= table->del_x * table->mv_speed;
		table->y -= table->del_y * table->mv_speed;
		blayer_movement(table, &xy, &del_xy, ang);
	} else if (table->keys[2]) {//d
		table->a += 0.1;
		if (table->a > PIe)
			table->a -= PIe;
		table->del_x = cos(table->a);
		table->del_y = sin(table->a);
		le_ray_caste_angel(table, &xy, &del_xy, ang);
	}
	mlx_put_image_to_window(table->mlx->mlx, table->mlx->win, table->mlx->img.img, 0, 0);

	return (69);
}

int	handle_keyrelease(int keysym, t_table *table)
{
	if (keysym == 0)
		table->keys[0] = 0;
	else if (keysym == 1)
		table->keys[1] = 0;
	else if (keysym == 2)
		table->keys[2] = 0;
	else if (keysym == 13)
		table->keys[3] = 0;
	return (0);
}

int	handle_keypress(int keysym, t_table *table)
{
	if (keysym == 53)
		mlx_destroy_window(table->mlx->mlx, table->mlx->win);
	else if (keysym == 0)
		table->keys[0] = 1;
	else if (keysym == 1)
		table->keys[1] = 1;
	else if (keysym == 2)
		table->keys[2] = 1;
	else if (keysym == 13)
		table->keys[3] = 1;
	// handle_input(keysym, table);
	return (0);
}

int main() {
	t_table	table;
	t_mlx	mlx;
	t_map	map;
	
	table.mlx = &mlx;
	table.map = &map;
	table.keys[0] = 0;
	table.keys[1] = 0;
	table.keys[2] = 0;
	table.keys[3] = 0;
	table.elmnt_sz = 64;
	table.mv_speed = 2.69;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 512, 512, "poopy!");
	if (!mlx.win)
	{
		free(mlx.win);
		return (1);//before that destroy everything else!
	}
	mlx.img.img = mlx_new_image(mlx.mlx, 512, 512);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length,
								&mlx.img.endian);
	map_init(&map);
	draw_map(&table);
	blayer_blacement(&table);
	mlx_loop_hook(mlx.mlx, (int (*)(void *))handle_no_event, &table);
	// mlx_loop_hook(data.mlx_ptr, (int (*)(void *))handle_no_event, &table);
	mlx_hook(mlx.win, 02, 1L<<0, &handle_keypress, &table); /* ADDED */
	mlx_hook(mlx.win, 03, 1L<<1, &handle_keyrelease, &table); /* CHANGED */
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.mlx);
}