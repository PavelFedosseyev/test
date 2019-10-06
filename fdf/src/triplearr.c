#include "fdf.h"

void	triplearr(t_fdf *fdf)
{
	int	col;
	int row;

	row = 0;
	if (!(fdf->triplearr = (t_coords ***)malloc(sizeof(t_coords **) * (fdf->row + 1))))
		return ;
	while (row < fdf->row)
	{
		col = 0;
		if (!(fdf->triplearr[row] = (t_coords **)malloc(sizeof(t_coords *) * (fdf->col + 1))))
			return ;
		while (col < fdf->col)
		{
			if (!(fdf->triplearr[row][col] = (t_coords *)malloc(sizeof(t_coords))))
				return ;
			fdf->triplearr[row][col]->x = (col + 1) * 30;
			fdf->triplearr[row][col]->y = (row + 1) * 30;
			fdf->triplearr[row][col]->z = fdf->intarr[row][col] * 10;
			col++;
		}
		fdf->triplearr[row][col] = NULL;
		row++;
	}
	fdf->triplearr[row] = NULL;
}
