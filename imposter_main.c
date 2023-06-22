#include <mlx.h>
#include <stdio.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    int     x;
    int     y;
	t_data	img;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void moves(t_vars *var, int x, int y)
{
	my_mlx_pixel_put(&var->img, var->x, var->y, 0x00000000);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	var->x += x;
	var->y += y;
    printf("x = %d, y = %d\n", var->x, var->y);
	my_mlx_pixel_put(&var->img, var->x, var->y, 0x00FF0000);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}

int key_hook(int keycode, t_vars *table)
{
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


int	main(void)
{
    t_vars  var;
    var.x = 64;
    var.y = 64;
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "Hello world!");
	var.img.img = mlx_new_image(var.mlx, 1920, 1080);
	var.img.addr = mlx_get_data_addr(var.img.img, &var.img.bits_per_pixel, &var.img.line_length,
								&var.img.endian);
	my_mlx_pixel_put(&var.img, var.x, var.y, 0x00FF0000);
	mlx_put_image_to_window(var.mlx, var.win, var.img.img, 0, 0);
	mlx_key_hook(var.win, key_hook,  &var);
	mlx_loop(var.mlx);
}