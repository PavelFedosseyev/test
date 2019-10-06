#include "fdf.h"

void	fillarr(t_list *list, t_fdf *fdf)
{
	int		col;
	int		row;
	int		i;
	t_list	*tmp;

	row = 0;
	tmp = list;
	while (tmp)
	{
		col = 0;
		i = 0;
		while (tmp->line[i] != '\0')
		{
			fdf->intarr[row][col] = atoi(&tmp->line[i]);
			while (tmp->line[i] != ' ' && tmp->line[i] != '\0')
				i++;
			while (tmp->line[i] == ' ' && tmp->line[i] != '\0')
				i++;
			col++;
		}
		tmp = tmp->next;
		row++;
	}
}
