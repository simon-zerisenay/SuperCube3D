#include "cub69d.h"

int	deg = 66;

//one part should become divisible by elmnt_sz so thats how u know u reached
// so for x part, the y axis should become divisible by elmnt_sz!
// for x look at what x axiz part it is in! and then the remaining amount is what it needs to reach the end!
// 5.5  

				// printf("map[%d]\n", pp);
				// printf("x -> %f\n", table->x);
				// printf("del_x -> %f\n", table->del_x);
				// printf("y -> %f\n", table->y);
				// printf("del_y -> %f\n", table->del_y);
				// printf("int accumulation of y*8 -> %d\n", ((int)((table->y + (table->del_y * g)) / table->elmnt_sz)) * 8);
				// printf("int accumulation of x -> %d\n", ((int)(table->x + (table->del_x * g)) / table->elmnt_sz));
				// printf("accumulation of y*8 -> %f\n", ((table->y + (table->del_y * g)) / table->elmnt_sz) * 8);
				// printf("accumulation of x -> %f\n", (table->x + (table->del_x * g)) / table->elmnt_sz);
				// printf("x*g => %f\n", (table->x + table->del_x * g));
				// printf("y*g => %f\n", (table->y + table->del_y * g));
				// printf("xy*g => %f\n", ((table->x + table->del_x * g) + (table->y + table->del_y * g)));

// void	le_ray_caste(t_table *table, t_cords *xy, t_cords *del, double ang) {
// 	double	angel;//angle bruh
// 	double	anx;
// 	double	any;

// 	angel = table->a - ((deg / 2) * DtR);
// 	printf("an -> %f\n", table->a);
// 	for(float f = 0; f < deg; f++) {
// 		del->x = cos(angel) * 5;
// 		del->y = sin(angel) * 5;
// 		// for (float g = 1; g; g+= .1) {
// 		// 	int pp = ((int)((xy->y + (del->y * g)) / table->elmnt_sz)) * 8;
// 		// 	pp += (int)((xy->x + (del->x * g)) / table->elmnt_sz);
// 		// 	if (table->map->map[pp] == 1)
// 		// 		break ;
// 		// 	my_mlx_pixel_put(&table->mlx->img, xy->x + del->x * g, xy->y + del->y * g, 0x00090999);
// 		// table->del_x = cos(angel) * 5;
// 		// table->del_y = sin(angel) * 5;
// 		// } for (float g = 1; g; g+= .1) {
// 		// 	int pp = ((int)((table->y + (table->del_y * g)) / table->elmnt_sz)) * 8;
// 		// 	pp += (int)((table->x + (table->del_x * g)) / table->elmnt_sz);
// 		// 	if (table->map->map[pp] == 1) {
// 		// 		break ;
// 		// 	}
// 		// 	my_mlx_pixel_put(&table->mlx->img, table->x + table->del_x * g, table->y + table->del_y * g, 0x0000FFFF);
// 		// }
// 		angel += 1 * DtR;
// 	}
// }

int kcabs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

void	draw_ray(t_table *table, double rx, double ry, int clr)
{
	int	dx = rx - table->x;
	int	dy = ry - table->y;

	int	steps = kcabs(dx) > kcabs(dy) ? kcabs(dx) : kcabs(dy);

	float	Xinc = dx / (float)steps;
	float	Yinc = dy / (float)steps;

	float	x = table->x;
	float	y = table->y;

	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(&table->mlx->img, (int)x, (int)y, clr);
		x += Xinc;
		y += Yinc;
	}
}
void	draw_rayx(t_table *table, t_cords *xy, double rx, double ry, int clr)
{
	int	dx = rx - xy->x;
	int	dy = ry - xy->y;

	int	steps = kcabs(dx) > kcabs(dy) ? kcabs(dx) : kcabs(dy);

	float	Xinc = dx / (float)steps;
	float	Yinc = dy / (float)steps;

	float	x = xy->x;
	float	y = xy->y;

	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(&table->mlx->img, (int)x, (int)y, clr);
		x += Xinc;
		y += Yinc;
	}
}

float	dist(float ax, float ay, float bx, float by, float ang)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

// need the intersection! so div by table->elmnt_sz to find if u met an intersection!

// void	le_ray_caste_angel(t_table *table, t_cords *xy, t_cords *del, double ang) {//attempt no. 96335663263696969
// 	float	xs, xn, ys, yn, ra;
// 	float	step_x, step_y, delt_x, delt_y, hypV, hypH;

// 	//checking horizontal intersextions
// 	ra = table->a;


// 	//vertical intersexstions
// 	if (ra > PIn || ra < PIs) // looking right
// 	{
// 		delt_x = 64;
// 		delt_y = delt_x * tan(ra);
// 	}
// 	else if (ra < PIn && ra > PIs) // looking left
// 	{
// 		delt_x = -64;
// 		delt_y = delt_x * tan(ra);
// 	}
// 	else if (ra == PIn || ra == PIs) {
// 		//then just take ray from the horizontal interseggs
// 	}
// 	hypV = sqrt((delt_x * delt_x) + (delt_y * delt_y));
// 	// ys = table->elmnt_sz;
// 	// xs = ys / tan(ra);
// 	// yn = table->y - (table->y / )

// }

// void	le_ray_caste_angel(t_table *table, t_cords *xy, t_cords *del, double ang) { //complete but gae!
// 	float	rx, ry, ra, del_rx, del_ry;

// 	ra = ang;
// 	for (int r = 0; r < 10; r++) {
// 		//chk vert line!
// 		rx = xy->x;
// 		ry = xy->y;
// 		del_rx = cos(ra);
// 		del_ry = sin(ra);
// 		while (1) {
// 			rx += del_rx;
// 			ry += del_ry;
// 			int chk = (((int)(ry + del_rx) / table->elmnt_sz) * 8) + ((int)(rx + del_rx) / table->elmnt_sz);
// 			if (table->map->map[chk] == 1)
// 				break;
// 		}
// 		ra += (1 * DtR);
// 		draw_ray(table, rx, ry, 0x00090999);
// 	}
// 	for (int r = 0; r < 10; r++) {
// 		//chk vert line!
// 		rx = table->x;
// 		ry = table->y;
// 		del_rx = cos(ra);
// 		del_ry = sin(ra);
// 		while (1) {
// 			rx += del_rx;
// 			ry += del_ry;
// 			int chk = (((int)(ry + del_rx) / table->elmnt_sz) * 8) + ((int)(rx + del_rx) / table->elmnt_sz);
// 			if (table->map->map[chk] == 1)
// 				break;
// 		}
// 		ra += (1 * DtR);
// 		draw_ray(table, rx, ry, 0x0000FFFF);
// 	}
// }


void	le_ray_caste_angel(t_table *table, t_cords *xy, t_cords *del, double ang) {
	int		r, mx, my, mp, dof;
	float	rx, ry, ra, xo, yo;

	printf("ang -> %f\n", ang);
	printf("a -> %f\n", table->a);
	ra = ang;
	for (int r = 0; r < 20; r++) {
		//checking horizontal line!
		ssize_t distH = 69696969696969, hx = xy->x, hy = xy->y;
		dof = 0;
		float	atan = -1 / tan(ra);
		if (ra > PIw)//looking down
		{	//
			ry = (((int)xy->y >> 6) << 6) - 0.0001;// round it to the nearest 64, and subtract a smol amount for accuracy!
			rx = ((xy->y - ry) * atan) + xy->x;//the rx val is the distance between the plyy and the ry's pos * atan + plyx!
			//the above two will determine the first hit pos!
			// the below r for the next offset!
			yo =-64;
			xo =-yo * atan;
		}
		if (ra < PIw)//looking up
		{	//
			ry = (((int)xy->y >> 6) << 6) + 64;// round it to the nearest 64, and subtract a smol amount for accuracy!
			rx = ((xy->y - ry) * atan) + xy->x;//the rx val is the distance between the plyy and the ry's pos * atan + plyx!
			//the above two will determine the first hit pos!
			// the below r for the next offset!
			yo = 64;
			xo =-yo * atan;
		}
		if (ra == 0 || ra == PIw)
		{
			rx = xy->x;
			ry = xy->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;//divide by 64!, same shit!
			my = (int)(ry) >> 6;
			mp = my * table->map->mapX + mx;
			if (mp > 0 && mp < table->map->mapX * table->map->mapY && table->map->map[mp] == 1)// contact with wall!
			{
				hx = (ssize_t)rx;
				hy = (ssize_t)ry;
				distH = (ssize_t)dist(xy->x, xy->y, hx, hy, ang);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		//vertical line
		ssize_t distV = 66969969696969, vx = xy->x, vy = xy->y;
		dof = 0;
		float	ntan = -tan(ra);
		if (ra > PIs && ra < PIn)//looking left
		{	//
			rx = (((int)xy->x >> 6) << 6) - 0.0001;// round it to the nearest 64, and subtract a smol amount for accuracx!
			ry = ((xy->x - rx) * ntan) + xy->y;//the rx val is the distance between the plx and the rx's pos * ntan + plxx!
			//the above two will determine the first hit pos!
			// the below r for the next offset!
			xo =-64;
			yo =-xo * ntan;
		}
		if (ra < PIs || ra > PIn)//looking right
		{	//
			rx = (((int)xy->x >> 6) << 6) + 64;// round it to the nearest 64, and subtract a smol amount for accuracx!
			ry = ((xy->x - rx) * ntan) + xy->y;//the rx val is the distance between the plx and the rx's pos * ntan + plxx!
			//the above two will determine the first hit pos!
			// the below r for the next offset!
			xo = 64;
			yo =-xo * ntan;
		}
		if (ra == 0 || ra == PIw)//up or down!
		{
			rx = xy->x;
			ry = xy->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;//divide by 64!, same shit!
			my = (int)(ry) >> 6;
			mp = my * table->map->mapX + mx;
			if (mp > 0 && mp < table->map->mapX * table->map->mapY && table->map->map[mp] == 1)// contact with wall!
			{
				vx = (ssize_t)rx;
				vy = (ssize_t)ry;
				distV = (ssize_t)dist(xy->x, xy->y, vx, vy, ang);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		printf("dish -> %zd\n", distH);
		printf("disv -> %zd\n", distV);
		if (distH > distV) {
			rx = (ssize_t)vx;
			ry = (ssize_t)vy;
		} else {
			rx = (ssize_t)hx;
			ry = (ssize_t)hy;
		}
		draw_rayx(table, xy, rx, ry, 0x00090999);
		ra += DtR;
	}




//new bois


	ra = table->a;
	for (int r = 0; r < 20; r++) {
		//checking horizontal line!
		ssize_t distH = 69696969696969, hx = table->x, hy = table->y;
		dof = 0;
		float	atan = -1 / tan(ra);
		if (ra > PIw)//looking down
		{	//
			ry = (((int)table->y >> 6) << 6) - 0.0001;// round it to the nearest 64, and subtract a smol amount for accuracy!
			rx = ((table->y - ry) * atan) + table->x;//the rx val is the distance between the plyy and the ry's pos * atan + plyx!
			//the above two will determine the first hit pos!
			// the below r for the next offset!
			yo =-64;
			xo =-yo * atan;
		}
		if (ra < PIw)//looking up
		{	//
			ry = (((int)table->y >> 6) << 6) + 64;// round it to the nearest 64, and subtract a smol amount for accuracy!
			rx = ((table->y - ry) * atan) + table->x;//the rx val is the distance between the plyy and the ry's pos * atan + plyx!
			//the above two will determine the first hit pos!
			// the below r for the next offset!
			yo = 64;
			xo =-yo * atan;
		}
		if (ra == 0 || ra == PIw)
		{
			rx = table->x;
			ry = table->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;//divide by 64!, same shit!
			my = (int)(ry) >> 6;
			mp = my * table->map->mapX + mx;
			if (mp > 0 && mp < table->map->mapX * table->map->mapY && table->map->map[mp] == 1)// contact with wall!
			{
				hx = (ssize_t)rx;
				hy = (ssize_t)ry;
				distH = (ssize_t)dist(table->x, table->y, hx, hy, table->a);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		//vertical line
		ssize_t distV = 66969969696969, vx = table->x, vy = table->y;
		dof = 0;
		float	ntan = -tan(ra);
		if (ra > PIs && ra < PIn)//looking left
		{	//
			rx = (((int)table->x >> 6) << 6) - 0.0001;// round it to the nearest 64, and subtract a smol amount for accuracx!
			ry = ((table->x - rx) * ntan) + table->y;//the rx val is the distance between the plx and the rx's pos * ntan + plxx!
			//the above two will determine the first hit pos!
			// the below r for the next offset!
			xo =-64;
			yo =-xo * ntan;
		}
		if (ra < PIs || ra > PIn)//looking right
		{	//
			rx = (((int)table->x >> 6) << 6) + 64;// round it to the nearest 64, and subtract a smol amount for accuracx!
			ry = ((table->x - rx) * ntan) + table->y;//the rx val is the distance between the plx and the rx's pos * ntan + plxx!
			//the above two will determine the first hit pos!
			// the below r for the next offset!
			xo = 64;
			yo =-xo * ntan;
		}
		if (ra == 0 || ra == PIw)//up or down!
		{
			rx = table->x;
			ry = table->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;//divide by 64!, same shit!
			my = (int)(ry) >> 6;
			mp = my * table->map->mapX + mx;
			if (mp > 0 && mp < table->map->mapX * table->map->mapY && table->map->map[mp] == 1)// contact with wall!
			{
				vx = (ssize_t)rx;
				vy = (ssize_t)ry;
				distV = (ssize_t)dist(table->x, table->y, vx, vy, table->a);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		printf("dish -> %zd\n", distH);
		printf("disv -> %zd\n", distV);
		if (distH > distV) {
			rx = (ssize_t)vx;
			ry = (ssize_t)vy;
		} else {
			rx = (ssize_t)hx;
			ry = (ssize_t)hy;
		}
		draw_ray(table, rx, ry, 0x0000FFFF);
		ra += DtR;
	}
}


// old and shit version!
// void	le_ray_caste_angel(t_table *table, t_cords *xy, t_cords *del, double ang) {
// 	double	angel;//angle bruh
// 	double	prev_an;
// 	double	anx;
// 	double	any;

// 	// printf("an -> %f\n", table->a);
// 	angel = table->a + (deg / 2) * DtR;
// 	for(float f = 0; f < deg; f++) {
// 		anx = cos(ang) * 5;
// 		any = sin(ang) * 5;
// 		for (float g = 1; g; g+= .1) {
// 			int pp = ((int)((table->y + (any * g)) / table->elmnt_sz)) * 8;
// 			pp += (int)((table->x + (anx * g)) / table->elmnt_sz);
// 			if (table->map->map[pp] == 1)
// 				break ;
// 			if (g == 1) {
// 				printf("bx*g => %f\n", (table->x + anx * g));
// 				printf("by*g => %f\n", (table->y + any * g));
// 			}
// 			my_mlx_pixel_put(&table->mlx->img, table->x + anx * g, table->y + any * g, 0x00090999);
// 		}
// 		ang += 1 * DtR;
// 	}
// 	for(float f = 0; f < deg; f++) {
// 		anx = cos(angel) * 5;
// 		any = sin(angel) * 5;
// 		for (float g = 1; g; g+= .1) {
// 			int pp = ((int)((table->y + (any * g)) / table->elmnt_sz)) * 8;
// 			pp += (int)((table->x + (anx * g)) / table->elmnt_sz);
// 			if (table->map->map[pp] == 1)
// 				break ;
// 			if (g == 1) {
// 				printf("ax*g => %f\n", (table->x + anx * g));
// 				printf("ay*g => %f\n", (table->y + any * g));
// 			}
// 			my_mlx_pixel_put(&table->mlx->img, table->x + anx * g, table->y + any * g, 0x0000FFFF);
// 		}
// 		angel += 1 * DtR;
// 	}
// }

/* ol one good for havin furn! */
// void	le_ray_caste(t_table *table, t_cords *xy, t_cords *del) {
// 	double	angel;//angle bruh
// 	double	anx;
// 	double	any;

// 	angel = table->a - (deg / 2) * DtR;
// 	for(float f = 0; f < deg; f++) {
// 		del->x = cos(angel) * 5;
// 		del->y = sin(angel) * 5;
// 		for (float g = 1; g; g+= .2) {
// 			int pp = ((int)((xy->y + (del->y * g)) / table->elmnt_sz)) * 8;
// 			pp += (int)((xy->x + (del->x * g)) / table->elmnt_sz);
// 			if (table->map->map[pp] == 1)
// 				break ;
// 			my_mlx_pixel_put(&table->mlx->img, xy->x + del->x * g, xy->y + del->y * g, 0x00090999);
// 		table->del_x = cos(angel) * 5;
// 		table->del_y = sin(angel) * 5;
// 		} for (float g = 1; g; g+= .2) {
// 			int pp = ((int)((table->y + (table->del_y * g)) / table->elmnt_sz)) * 8;
// 			pp += (int)((table->x + (table->del_x * g)) / table->elmnt_sz);
// 			if (table->map->map[pp] == 1)
// 				break ;
// 			my_mlx_pixel_put(&table->mlx->img, table->x + table->del_x * g, table->y + table->del_y * g, 0x0000FFFF);
// 		}
// 		angel += 1 * DtR;
// 	}
