#include "cub69d.h"

bool	err_msg(char *err)
{
	printf("%s\n", err);
	return (false);
}

int	per_ret(void)
{
	perror("Error opening phile");
	return (1);
}

int	free_ret(void *ptr)
{
	free (ptr);
	return (false);
}