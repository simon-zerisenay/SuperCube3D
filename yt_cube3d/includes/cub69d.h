#ifndef CUB69D_H
# define CUB69D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define PIw 3.1415926536
# define DtR PIw / 180
# define PIe PIw * 2
# define PIs PIw / 2
# define PIn (3 * PIw) / 2

typedef struct s_cords {
	double	x;
	double	y;
}				t_cords;

typedef struct	s_map {
	int	mapX;
	int	mapY;
	int	mapS;
	int	*map;
}					t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_data;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
	t_data	img;
}					t_mlx;


typedef struct	s_table {
	t_mlx	*mlx;
	t_map	*map;

	int		elmnt_sz;
	double	mv_speed;
	int		ray_sz;
	double	del_x;
	double	del_y;
	int		keys[4];
	double	a;
	double	x;
	double	y;
}					t_table;

/* main.c */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* utils */
/* map_maker.c */
void	map_init(t_map *map);
void	draw_map(t_table *table);

/* blayer.c */
void	blayer_blacement(t_table *table);
void	blayer_angle(t_table *table, t_cords *xy, t_cords *del);
void	blayer_movement(t_table *table, t_cords *xy, t_cords *del_xy, double ang);

/* ray_casta.d */
void	le_ray_caste(t_table *table, t_cords *xy, t_cords *del, double ang);
void	le_ray_caste_angel(t_table *table, t_cords *xy, t_cords *del, double ang);

/* utils0.c */
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);

void	draw_ray(t_table *table, double rx, double ry, int clr);

#endif