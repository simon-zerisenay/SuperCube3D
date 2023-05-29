#include "cub69d.h"

// int main(int argc, char *argv[])
// {
// 	t_able	table;

// 	if (!valid_args(argc, argv))
// 		return (69);
// 	if (table.phile = open(argv[1], O_RDONLY) < 0)
// 		return (per_ret());
// 	if (!quality_control(&table))
// 		return (69);
//// ->>>>execution!
// 	return (69 * 0);
// }
 

int main(int ac, char **av)
{
	t_able	table;

    /*
        1. Create an empty window 
            => mlx_init()
        2. struct to save each texture 
        3. 

    */
   ft_initializer(&table);
   table.mlx = mlx_init();
   if (!table.mlx)
        // call the handle_error (freeing + return message)
   table.win = mlx_new_window(table.mlx, table.size_x,
			table.size_y, "By 69ers");
   ft_render_next_frame(&table);//the exec big dawg!
    mlx_loop(table.mlx);
}



int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	// window_size(&data, argv);
	// check_filename(argv[1]);
	// map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	// if (!map.map)
		// calloc_failure("Error\ncalloc failed\n");
	// ft_initializer(&data, &map);
	// validate_input(&data, argv, argc);
	// check_path(&data);
	etab.mlx = mlx_init();
	// if (!data.mlx)
	// {
	// 	perror("Error\nprogram initialization failed\n");
	// 	exit(EXIT_FAILURE);
	// }
	// data.win = mlx_new_window(data.mlx, data.size_x,
	// 		data.size_y, "By Simon Zerisenay");
	// ft_render_next_frame(&data);
	// mlx_loop(data.mlx);
	// perror("Error\nProgramme failed to loop\n");
	// exit(EXIT_FAILURE);

}


static void	ft_initializer_help(t_data *data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./textures/ship_left.xpm";
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./textures/ship_down.xpm";
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./textures/ship_right.xpm";
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->player_left || !data->img->player_down)
		handle_error(data, "Error\nOne of Player files not found", 1);
	if (!data->img->player_right)
		handle_error(data, "Error\nPlayer right file not found", 1);
	relative_path = "./textures/background.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->background)
		handle_error(data, "Error\nbackground file not found", 1);
}

void	ft_initializer(t_data *data, t_map *map)// barsing!
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	t_img	*img;

	// data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error\nmalloc failed\n");
		exit(EXIT_FAILURE);
	}
	data->img = img;
	relative_path = "textures/ship_up.xpm";
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	if (!data->img->player_up)
		handle_error(data, "Error\nPlayer up file not found", 1);
	ft_initializer_help(data);
	data->counter = 0;
	data->collected = 0;
}
