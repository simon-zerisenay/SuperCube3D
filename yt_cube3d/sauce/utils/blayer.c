#include "cub69d.h"

void	blayer_blacement(t_table *table) {
	int		i;

	for (i = 0; i < 64; i++)
		if (ft_strchr("NSEW", table->map->map[i]))
			break ;
	int	iy = i / 8;
	int	ix = i - (8 * iy);
	table->x = ((double)ix * table->elmnt_sz) + (table->elmnt_sz / 2);
	table->y = ((double)iy * table->elmnt_sz) + (table->elmnt_sz / 2);
	printf("x => %f\n", table->x);
	printf("y => %f\n", table->y);
	table->a = (table->map->map[i] == 69) ? 0 : (table->map->map[i] == 83) ? \
	PIs : (table->map->map[i] == 87) ? PIw : PIn;
	table->del_x = cos(table->a) * 5;
	table->del_y = sin(table->a) * 5;
	for (double v = table->y - 2; v <= (table->y + 2); v++) {
		if (v == table->y - 2 || v == table->y + 2)
			for (double w = table->x - 1; w <= table->x + 1; w++)
				my_mlx_pixel_put(&table->mlx->img, w, v, 0x00FFFFFF);
		else
			for (double w = table->x - 2; w <= table->x + 2; w++)
				my_mlx_pixel_put(&table->mlx->img, w, v, 0x00FFFFFF);
	}
	// for (float g = 1; g < 6; g+= .1){
	// 	my_mlx_pixel_put(&table->mlx->img, table->x + table->del_x * g, \
	// 	table->y + table->del_y * g, 0x0000FFFF);
	// }
	mlx_put_image_to_window(table->mlx->mlx, table->mlx->win, table->mlx->img.img, 0, 0);
}

void	blayer_movement(t_table *table, t_cords *xy, t_cords *del_xy, double ang) {
	le_ray_caste_angel(table, xy, del_xy, ang);
	for (double v = xy->y - 2; v <= (xy->y + 2); v++) {
		if (v == xy->y - 2 || v == xy->y + 2)
			for (double w = xy->x - 1; w <= xy->x + 1; w++)
				my_mlx_pixel_put(&table->mlx->img, w, v, 0x00090999);
		else
			for (double w = xy->x - 2; w <= xy->x + 2; w++)
				my_mlx_pixel_put(&table->mlx->img, w, v, 0x00090999);
	}
	for (double v = table->y - 2; v <= (table->y + 2); v++) {
		if (v == table->y - 2 || v == table->y + 2)
			for (double w = table->x - 1; w <= table->x + 1; w++)
				my_mlx_pixel_put(&table->mlx->img, w, v, 0x00FFFFFF);
		else
			for (double w = table->x - 2; w <= table->x + 2; w++)
				my_mlx_pixel_put(&table->mlx->img, w, v, 0x00FFFFFF);
	}
}

// void	pp_therapy(t_table *table, t_cords *xy, t_cords *del) {
// 	for (float g = 1; g; g+= .2) {
// 		int pp = ((int)((xy->y + (del->y * g)) / table->elmnt_sz)) * 8;
// 		pp += (int)((xy->x + (del->x * g)) / table->elmnt_sz);
// 		if (table->map->map[pp] == 1)
// 			break ;
// 		my_mlx_pixel_put(&table->mlx->img, xy->x + del->x * g, xy->y + del->y * g, 0x00090999);
// 	} for (float g = 1; g; g+= .2) {
// 		int pp = ((int)((table->y + (table->del_y * g)) / table->elmnt_sz)) * 8;
// 		pp += (int)((table->x + (table->del_x * g)) / table->elmnt_sz);
// 		if (table->map->map[pp] == 1)
// 			break ;
// 		my_mlx_pixel_put(&table->mlx->img, table->x + table->del_x * g, table->y + table->del_y * g, 0x0000FFFF);
// 	}
// }

// void	blayer_angle(t_table *table, t_cords *xy, t_cords *del) {
// 	for (float g = 1; g < 6; g+= .2) {
// 		int pp = ((int)((xy->y + (del->y * g)) / table->elmnt_sz)) * 8;
// 		pp += (int)((xy->x + (del->x * g)) / table->elmnt_sz);
// 		if (table->map->map[pp] == 1) {
// 			my_mlx_pixel_put(&table->mlx->img, xy->x + del->x * g, xy->y + del->y * g, 0x00FFFF00);
// 			continue ;
// 		}
// 		my_mlx_pixel_put(&table->mlx->img, xy->x + del->x * g, xy->y + del->y * g, 0x00090999);
// 	} for (float g = 1; g < 6; g+= .2) {
// 		int pp = ((int)((table->y + (table->del_y * g)) / table->elmnt_sz)) * 8;
// 		pp += (int)((table->x + (table->del_x * g)) / table->elmnt_sz);
// 		if (table->map->map[pp] == 1) {
// 			my_mlx_pixel_put(&table->mlx->img, table->x + table->del_x * g, table->y + table->del_y * g, 0x00FF0101);
// 			continue ;
// 		}
// 		my_mlx_pixel_put(&table->mlx->img, table->x + table->del_x * g, table->y + table->del_y * g, 0x0000FFFF);
// 	}
// 	pp_therapy(table, xy, del);
// 	le_ray_caste(table, xy, del);
// }