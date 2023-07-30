#include "cub69d.h"
//using calloc!!!!


/* the ternary below is == to this!
// if (y == 0 || y == 7)
// 	map->map[(y * 8) + x] = 1;
// else if (x == 0 || x == 7)
// 	map->map[(y * 8) + x] = 1;
// else
// 	map->map[(y * 8) + x] = 0;
 */
void	map_init(t_map *map)
{
	map->mapX = 8;
	map->mapY = 8;
	map->mapS = 64;
	map->map = calloc(64, sizeof(int));
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			map->map[(y * 8) + x] = (y == 0 || y == 7 || x == 0 || x == 7) ? 1 : 0;
	map->map[25] = 83;//S = 83, N = 78, W = 87, E = 69
	// map->map[10] = 1;
	// map->map[18] = 1;
	// map->map[26] = 1;
	// for (int k = 0; k < 64; k++) {
	// 	printf("map[%d] => %d\n", k, map->map[k]);
	// }
}

void	draw_map(t_table *table)
{
	t_map	*mp = table->map;
	t_mlx	*mx = table->mlx;
	int x, y = 0;
	int w, h = 0;
	int clr;

	while (y < mp->mapY)
	{
		x = 0;
		h = y * table->elmnt_sz;
		while (x < mp->mapX)
		{
			w = x * table->elmnt_sz;
			int p = (y * 8) + x;
			if (mp->map[p] == 1)
				clr = 0x00FFFF00;
			else
				clr = 0x00090999;
			for (int f = h; f < (y + 1) * table->elmnt_sz; f++)
				for (int k = w; k < (x + 1) * table->elmnt_sz; k++) {
					// if (y == mp->mapY - 1 && x == mp->mapX - 1 && f == ((y + 1) * table->elmnt_sz) - 1 && (k == ((x + 1) * table->elmnt_sz) - 1)) {
					// if (y == mp->mapY - 1 && x == mp->mapX - 1) {
					// 	if (f == ((y + 1) * table->elmnt_sz) - 1 && (k == ((x + 1) * table->elmnt_sz) - 1)) {
					// 		printf("totla sz -> %d\n", table->elmnt_sz);
					// 		printf("totla x -> %d\n", x);
					// 		printf("totla k -> %d\n", k);
					// 		printf("totla y -> %d\n", y);
					// 		printf("totla f -> %d\n", f);
					// 	}
					// }
					// my_mlx_pixel_put(&mx->img, x + k, y + f, clr);
					my_mlx_pixel_put(&mx->img, k, f, clr);
				}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mx->mlx, mx->win, mx->img.img, 0, 0);
}
