#include "cub69d.h"

bool	f_alpha_under_num(char *str)
{
	if (!f_strncmp("./", str, 2))
		str += 2;
	else if (!f_strncmp("../", str, 3))
		str += 3;
	while (*str && ((*str >= 'a' && *str <= 'z') \
		|| (*str >= 'A' && *str <= 'Z') || *str == '_' \
		|| (*str >= '0' && *str <= '9') || *str == '/'))
		str++;
	return (f_strcmp(".cub", str));
}

bool	valid_args(int argc, char *argv[])
{
	size_t	i;

	if (argc != 2)
		return (err_msg("Error\nusage: ./cub3D *.cub"));
	i = f_strlen(argv[1]);
	if (i <= 4)
		return (err_msg("Error\nusage: *.cub, emphasis on the \"*\""));
	if (f_alpha_under_num(argv[1]))
		return (err_msg("Error\nusage: valid file name consist of -> "\
		"letters, numbers, under_score and ends with .cub; eg -> _xX69.cub"));
	return (true);
}