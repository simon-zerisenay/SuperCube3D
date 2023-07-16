#include "cub69d.h"

int mapX = 8, mapY= 8, mapS = 64;
int map[] = 
{
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};

void	draw_rays(t_able	*table);

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

void fmoves(t_able *table)
{
	for (float g = 1; g < 6; g+= .5)
		my_mlx_pixel_put(&table->img, table->x + table->delx * g, table->y + table->dely * g, 0x0000FFFF);
	for (int f = 0; f <= 5; f++)
		for (int k = 0; k <= 5; k++)
			my_mlx_pixel_put(&table->img, table->x + k, table->y + f, 0x0000FFFF);
	draw_rays(table);
	mlx_put_image_to_window(table->mlx, table->win, table->img.img, 0, 0);
}

int handle_input(int keycode, t_able *table)
{
	for (float g = 1; g < 6; g+= .5)
		my_mlx_pixel_put(&table->img, table->x + table->delx * g, table->y + table->dely * g, 0x00000000);
	for (int f = 0; f <= 5; f++)
		for (int k = 0; k <= 5; k++)
			my_mlx_pixel_put(&table->img, table->x + k, table->y + f, 0x00000000);
	mlx_put_image_to_window(table->mlx, table->win, table->img.img, 0, 0);
	if (keycode == 119)//w
	{
		table->x += table->delx;
		table->y += table->dely;
		fmoves(table);
	}
	if (keycode == 97)//a
	{
		table->a -= 0.1;
		if (table->a < 0)
			table->a += 2 * PI;
		table->delx = cos(table->a) * 5;
		table->dely = sin(table->a) * 5;
		fmoves(table);
	}
	if (keycode == 115)//s
	{
		table->x -= table->delx;
		table->y -= table->dely;
		fmoves(table);
	}
	if (keycode == 100)//d //s
	{
		table->a += 0.1;
		if (table->a > 2 * PI)
			table->a -= 2 * PI;
		table->delx = cos(table->a) * 5;
		table->dely = sin(table->a) * 5;
		fmoves(table);
	}
	if (keycode == XK_Escape)
		mlx_destroy_window(table->mlx, table->win);
	return (0);
}

int ft_close(t_able *table)
{
	// printf("a%d\n", keycode);
	// if (keycode == 17)
	mlx_destroy_window(table->mlx, table->win);
	// exit(0);
	return (0);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	// printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	handle_keypress(int keysym, t_able *table)
{
	handle_input(keysym, table);
}

void	draw_ray(t_able *table, float rx, float ry)
{
	int	dx = abs(rx - table->x);
	int	dy = abs(ry - table->y);
	int	sx2 = table->x < rx ? 1 : -1;
	int	sy2 = table->y < ry ? 1 : -1;
	int	sx = table->x;
	int	sy = table->y;
	int	err = (dx > dy ? dx : -dy) / 2;
	int	e2;

	int	i = 0;
	while (i++ < 100) {
		my_mlx_pixel_put(&table->img, sx, sy, 0x00696969);
		if (sx == rx && sy == ry)
			break;

		e2 = err;
		if (e2 > -dx) {
			err -= dy;
			sx += sx2;
		}
		if (e2 < dy) {
			err += dx;
			sy += sy2;
		}
	}
}
typedef struct {
	int	x;
	int	y;
}	Point;

int	abs_val(int value) {
	return (value < 0) ? -value : value;
}

// void	draw_line(t_able *table, int x2, int y2) {
// 	printf("rx = %d, ry = %d\n", x2, y2);
// 	int x1 = table->x, y1 = table->y;
// 	Point *line_coords = NULL;
// 	int num_coords = 0;
	
// 	// Calculate differences and increments
// 	int dx = abs_val(x2 - x1);
// 	int dy = abs_val(y2 - y1);
// 	int x_inc = (x2 > x1) ? 1 : -1;
// 	int y_inc = (y2 > y1) ? 1 : -1;
// 	int error = dx - dy;
	
// 	// Set initial coordinates
// 	int x = x1;
// 	int y = y1;
	
// 	// Iterate over line coordinates
// 	while (1) {
// 		line_coords = (Point *)realloc(line_coords, (num_coords + 1) * sizeof(Point));
// 		line_coords[num_coords].x = x;
// 		line_coords[num_coords].y = y;
// 		num_coords++;
		
// 		// Check if we reached the destination
// 		if (x == x2 && y == y2) {
// 			break;
// 		}
		
// 		int error_prev = error * 2;
		
// 		// Update x coordinate and error
// 		if (error_prev > -dx) {
// 			error -= dy;
// 			x += x_inc;
// 		}
		
// 		// Update y coordinate and error
// 		if (error_prev < dy) {
// 			error += dx;
// 			y += y_inc;
// 		}
// 	}
	
// 	// Print the coordinates along the line
// 	int i;
// 	for (i = 0; i < num_coords; i++) {
// 		my_mlx_pixel_put(&table->img, line_coords[i].x, line_coords[i].y, 0x00FF0F0F);
// 		// put_pixel(line_coords[i].x, line_coords[i].y);
// 	}
	
// 	// Free allocated memory
// 	printf("last pixel at x = %d, y = %d\n", line_coords[i].x, line_coords[i].y);
// 	free(line_coords);
// }


////////////////////////////////////////////////////////////////


double	dist(double ax, double ay, double bx, double by, double ang)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void draw_line_low(t_able *table, t_coords *p0, t_coords *p1)
{
	int dx = p1->x - p0->x;
	int dy = p1->y - p0->y;
	int yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int D = 2 * dy - dx;
	int y = p0->y;
	int x = p0->x;
	while ( x <= p1->x)
	{
		if (!(y >= 0 && y < 1080 && x >= 0 && x < 1920))
			break;
		my_mlx_pixel_put(&table->img, x, y, 0x00FF0f0f);
		if (D > 0)
		{
			y = y + yi;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
		x++;
	}
	printf("last pixie x-> %d, y-> %d\n", x, y);
}

void draw_line_high(t_able *table, t_coords *p0, t_coords *p1)
{
	int dx = p1->x - p0->x;
	int dy = p1->y - p0->y;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = 2 * dx - dy;
	int x = p0->x;
	int y = p0->y;
	while ( y <= p1->y)
	{
		if (!(y >= 0 && y < 1080 && x >= 0 && x < 1920))
			break;
		my_mlx_pixel_put(&table->img, x, y, 0x00FF0f0f);
		if (D > 0)
		{
			x = x + xi;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
		y++;
	}
	printf("last pixie x-> %d, y-> %d\n", x, y);
}

void draw_line(t_able *table, int rx, int ry)
{
	printf("rx -> %d, ry -> %d\n", rx, ry);
	t_coords p0;
	t_coords p1;

	p0.x = table->x;
	p0.y = table->y;
	p1.x = rx;
	p1.y = ry;
	if (fabs(p1.y - p0.y) < fabs(p1.x - p0.x))
	{
		if (p0.x >= p1.x)
			draw_line_low(table, &p1, &p0);
		else
			draw_line_low(table, &p0, &p1);
	}
	else
	{
		if (p0.y >= p1.y)
			draw_line_high(table, &p1, &p0);
		else
			draw_line_high(table, &p0, &p1);
	}
}


////////////////////////////////////////////////////////////////







void	draw_rays(t_able	*table)
{
	int		r, mx, my, mp, dof;
	float	rx, ry, ra, xo, yo;
	ra = table->a;
	for (r = 0; r < 1; r++)
	{	//horizontal ray
		dof = 0;
		float	disH = 1000000, hx = table->x, hy = table->y;
		float atan = -1/tan(ra);
		if (ra > PI)
		{
			ry = (((int)table->y >> 6) << 6) - 0.0001;
			rx = (table->y - ry) * atan + table->x;
			yo = -64;
			xo = -yo * atan;
		}
		if (ra < PI)
		{
			ry = (((int)table->y >> 6) << 6) + 64;
			rx = (table->y - ry) * atan + table->x;
			yo = 64;
			xo = -yo * atan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = table->x;
			ry = table->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(rx) >> 6;
			mp = my * mapX + mx;
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
			{
				hx = rx;
				hy = ry;
				disH = dist(table->x, table->y, hx, hy, ra);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		dof = 0;// vertical rays!!
		float	disV = 1000000, vx = table->x, vy = table->y;
		float ntan = -tan(ra);
		if (ra > P2 && ra < P3)//looking left
		{
			rx = (((int)table->x >> 6) << 6) - 0.0001;
			ry = (table->x - rx) * ntan + table->y;
			xo = -64;
			yo = -xo * ntan;
		}
		if (ra < P2 || ra > P3)//looking right
		{
			rx = (((int)table->x >> 6) << 6) + 64;
			ry = (table->x - rx) * ntan + table->y;
			xo = 64;
			yo = -xo * ntan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = table->x;
			ry = table->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(rx) >> 6;
			mp = my * mapX + mx;
			if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
			{
				vx = rx;
				vy = ry;
				disV = dist(table->x, table->y, vx, vy, ra);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		if (disV < disH)
		{
			rx = vx;
			ry = vy;
		}
		else
		{
			rx = hx;
			ry = hy;
		}
		// draw_ray(table, rx, ry);
		draw_line(table, rx, ry);
	}
}

void	draw_mp(t_able *table)
{
	int x, y = 0;
	int w, h = 0;

	while (y < mapY)
	{
		x = 0;
		h = y * 64;
		while (x < mapX)
		{
			w = x * 64;
			int p = (y * 8) + x;
			int clr;
			if (map[p] == 1)
				clr = 0x00FFFF00;
			if (map[p] == 0)
				clr = 0x00090999;
			for (int f = y * 64; f < (y + 1) * 64; f++)
				for (int k = x * 64; k < (x + 1) * 64; k++)
					my_mlx_pixel_put(&table->img, x + k, y + f, clr);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(table->mlx, table->win, table->img.img, 0, 0);
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
	quality_control(&table);
	// print_elements(&table);
	// print_map(&table);

	table.x = 64;
	table.y = 64;
	table.a = 0;
	table.delx = cos(table.a) * 5;
	table.dely = sin(table.a) * 5;
	table.mlx = mlx_init();
	table.win = mlx_new_window(table.mlx, 1920, 1080, "poopy!");
	if (!table.win)
	{
		free(table.win);
		return (1);//before that destroy everything else!
	}
	table.img.img = mlx_new_image(table.mlx, 1920, 1080);
	table.img.addr = mlx_get_data_addr(table.img.img, &table.img.bits_per_pixel, &table.img.line_length,
								&table.img.endian);
	draw_mp(&table);
	int ih = 20, iw = 10;
	mlx_loop_hook(table.mlx, &handle_no_event, &table);
	mlx_hook(table.win, KeyPress, KeyPressMask, &handle_keypress, &table); /* ADDED */
	mlx_hook(table.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &table); /* CHANGED */
	mlx_hook(table.win, 17, 0, ft_close, &table);
	mlx_loop(table.mlx);

	mlx_destroy_display(table.mlx);
	free(table.mlx);
	rmrf_everything(&table);
	return (69 * 0);
}
