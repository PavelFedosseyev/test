#include "fdf.h"

void	tripleiso(t_fdf *fdf)
{
	int col;
	int row;

	row = 0;
	if (!(fdf->tripleiso = (t_coords ***)malloc(sizeof(t_coords **) * (fdf->row + 1))))
		return ;
	while (row < fdf->row)
	{
		col = 0;
		if (!(fdf->tripleiso[row] = (t_coords **)malloc(sizeof(t_coords *) * (fdf->col + 1))))
			return ;
		while (col < fdf->col)
		{
			if (!(fdf->tripleiso[row][col] = (t_coords *)malloc(sizeof(t_coords))))
				return ;
			fdf->tripleiso[row][col]->x = 450 + (((col + 1) * 30) - ((row + 1) * 30)) * 0.86602529158;
			fdf->tripleiso[row][col]->y = 200 + (((col + 1) * 30) + ((row + 1) * 30)) * 0.50000019433\
					- (fdf->intarr[row][col] * 10);
			fdf->tripleiso[row][col]->z = (fdf->intarr[row][col] * 10);
			col++;
		}
		fdf->tripleiso[row][col] = NULL;
		row++;
	}
	fdf->tripleiso[row] = NULL;
}
