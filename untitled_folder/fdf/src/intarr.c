#include "fdf.h"

void	fillarr(t_line *list, t_fdf *fdf)
{
	int		col;
	int		row;
	int		i;
	t_line	*tmp;

	row = 0;
	tmp = list;
	while (tmp)
	{
		col = 0;
		i = 0;
		while (tmp->line[i] != '\0')
		{
			fdf->intarr[row][col] = ft_atoi(&(tmp->line[i]));
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

void	intarr(t_line *list, t_fdf *fdf)
{
	int		i;
	t_line	*tmp;

	i = 0;
	tmp = list;
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
	while (tmp)
	{
		fdf->row++;
		tmp = tmp->next;
	}
	i = -1;
	fdf->intarr = (int **)malloc(sizeof(int *) * (fdf->row));
	while (i++ < fdf->row)
		fdf->intarr[i] = (int *)malloc(sizeof(int) * (fdf->col));
	fdf->intarr[i] = NULL;
}
