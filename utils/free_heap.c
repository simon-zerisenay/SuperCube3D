#include "cub69d.h"

void	free_map(t_elmnt *element)
{
	t_mapling	*mapling[2];

	mapling[0] = element->map->mapling;
	while (mapling[0])
	{
		mapling[1] = mapling[0]->next;
		free(mapling[0]->row);
		free(mapling[0]);
		mapling[0] = mapling[1];
	}
	free(element->map);
}

void	free_elements(t_elmnt *element)
{

	free(element->clr->c_rgb);
	free(element->clr->f_rgb);
	free(element->clr);
	free(element->txtr->n_path);
	free(element->txtr->s_path);
	free(element->txtr->e_path);
	free(element->txtr->w_path);
	free(element->txtr);
}

void	rmrf_everything(t_able *table)
{
	free_map(table->elements);
	free_elements(table->elements);
	free(table->elements);
}