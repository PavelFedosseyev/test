#include "fdf.h"

void	countsizes(t_list *list, t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->col = 0;
	fdf->row = 0;
	while (list->line[i] != '\0')
	{
		if (list->line[i] != ' ' && list->line[i] != '\0')
		{
			fdf->col++;
			while (list->line[i] != ' ' && list->line[i] != '\0')
				i++;
			while (list->line[i] == ' ')
				i++;
		}
	}
	while (list)
	{
		fdf->row++;
		list = list->next;
	}
}
