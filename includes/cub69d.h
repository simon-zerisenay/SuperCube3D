#ifndef CUB69D_H
# define CUB69D_H

# include <fcntl.h>		// For file-related functions (open, close, read, write)
# include <stdio.h>		// For standard I/O functions (printf)
# include <stdlib.h>	// For memory management functions (malloc, free, exit)
# include <errno.h>		// For error handling (perror, strerror)
# include <stdbool.h>	// For bool types
# include <unistd.h>	// For ssize_t type
// # include <GLFW/glfw3.h>
// # include "../mlx/mlx.h"       // add path in makefile, compile mlx lib and bring the little .a here
# include <mlx.h>

# define BUFFER_SIZE 69

typedef struct s_xtr// just turn the variable, into an array! only 4var
{//just fix the intakes
	char			*n_path;
	char			*s_path;
	char			*e_path;
	char			*w_path;
}	t_xtr;

typedef struct s_clr// just create an array with just the two colors
{//just fix the intakes!
	int				*c_rgb;
	int				*f_rgb;
}	t_clr;

typedef struct s_mapling
{
	int					r_no;
	struct s_mapling	*prev;
	char				*row;
	struct s_mapling	*next;
}	t_mapling;

typedef struct s_map
{
	t_mapling	*mapling;
	int			map_max;
	int			plyr_no;
	char		plyr_pos;
}	t_map;


typedef struct s_elmnt
{
	int		rd;
	int		stop;
	// int		fd;
	char	*buf;
	t_map	*map;
	t_xtr	*txtr;
	t_clr	*clr;
}	t_elmnt;

typedef struct s_able// table of contents!
{
	// int pp;
	void	*mlx;
	void 	*win;
	int		size_x;
	int 	size_y;
	int		file;
	t_elmnt	*elements;
}	t_able;


void	print_elements(t_able *table);// made just for testing!
void	print_map(t_able *table);
int		find_mapling(char **str, t_able *table, int cnt);
void	map_intits(t_map *map, char *str);

/* parsing */
bool		valid_args(int argc, char *argv[]);

void	quality_control(t_able *table);
int		find_line(char **str, t_able *table, int cnt);

void	map_init(t_able *table, char *str);

void	rmrf_everything(t_able *table);


/* utils */

//		--- utils0.c
size_t		f_strlen(char *str);
size_t		f_strcmp(char *str1, char *str2);
int			f_atoi(char *str);
char		*f_strchr(char *s, int c);
int			f_strncmp(char *s1, char *s2, size_t n);
int			f_isdigit(int c);

//		---mem_utils.c
char		*f_calloc(size_t amt, size_t size);
char		*f_strdup(char *s1);
char		*f_lstrjoin(char *s1, char *s2, int len);
char		*f_bufstr(char *buf, char *str, int rd);

//		--- err_msg.c
bool		err_msg(char *err);
int			per_ret(void);
int			free_ret(void *ptr);

# endif