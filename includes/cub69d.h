#ifndef CUB69D_H
# define CUB69D_H

# include <fcntl.h>		// For file-related functions (open, close, read, write)
# include <stdio.h>		// For standard I/O functions (printf)
# include <stdlib.h>	// For memory management functions (malloc, free, exit)
# include <errno.h>		// For error handling (perror, strerror)
# include <stdbool.h>	// For bool types
# include <unistd.h>	// For ssize_t type

# define BUFFER_SIZE 69

typedef struct s_xtr
{
	int				fd;
	char			*id;
	char			*path;
	struct s_xtr	*next;
}	t_xtr;

typedef struct s_clr
{
	char			id;
	int				rgb[3];
	struct t_clr	*next;
}	t_clr;

typedef struct s_map
{
	struct s_map	*prev;
	int				r_no;
	char			*row;
	struct	s_map	*next;
}	t_map;

typedef struct s_elmnt
{
	int		rd;
	int		fd;
	char	*buf;
	t_map	*map;
	int		map_max;
	t_xtr	*txtr;
	t_clr	*clr;
}	t_elmnt;

typedef struct s_able
{
	int		phile;
	t_elmnt	*lmnts;
}	t_able;

/* parsing */
bool		valid_args(int argc, char *argv[]);

/* utils */

//		--- utils0.c
size_t		f_strlen(char *str);
size_t		f_strcmp(char *str1, char *str2);
char		*f_calloc(size_t amt, size_t size);
int			f_atoi(const char *str);
char		*f_strdup(const char *s1);
char		*f_strchr(const char *s, int c);

//		--- err_msg.c
bool		err_msg(char *err);
int			per_ret(void);
int			free_ret(void *ptr);

# endif