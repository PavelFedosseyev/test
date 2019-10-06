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
			fdf->tripleiso[row][col]->x = 400 + (fdf->triplearr[row][col]->x - fdf->triplearr[row][col]->y) * cos(0.5233);
			fdf->tripleiso[row][col]->y = 150 + ((fdf->triplearr[row][col]->x + fdf->triplearr[row][col]->y) * sin(0.5233)\
					- fdf->triplearr[row][col]->z);
			fdf->tripleiso[row][col]->z = fdf->triplearr[row][col]->z;
			col++;
		}
		fdf->tripleiso[row][col] = NULL;
		row++;
	}
	fdf->tripleiso[row] = NULL;
}
