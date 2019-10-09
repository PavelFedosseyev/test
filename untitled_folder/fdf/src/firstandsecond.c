#include "fdf.h"

void	pointscontinue(t_fdf *fdf, int *row, int *col, int flag)
{
	if (flag == 1)
	{
		fdf->first->x = fdf->tripleiso[*row][*col]->x;
		fdf->first->y = fdf->tripleiso[*row][*col]->y;
		fdf->first->z = fdf->tripleiso[*row][*col]->z;
		fdf->second->x = fdf->tripleiso[*row + 1][*col]->x;
		fdf->second->y = fdf->tripleiso[*row + 1][*col]->y;
		fdf->second->z = fdf->tripleiso[*row + 1][*col]->z;
	}
	if (flag == 2)
	{
		fdf->second->x = fdf->tripleiso[*row][*col + 1]->x;
		fdf->second->y = fdf->tripleiso[*row][*col + 1]->y;
		fdf->second->z = fdf->tripleiso[*row][*col + 1]->z;
	}
	if (flag == 3)
	{
		fdf->first->x = fdf->tripleiso[*row][fdf->col - 1]->x;
		fdf->first->y = fdf->tripleiso[*row][fdf->col - 1]->y;
		fdf->first->z = fdf->tripleiso[*row][fdf->col - 1]->z;
		fdf->second->x = fdf->tripleiso[*row + 1][fdf->col - 1]->x;
		fdf->second->y = fdf->tripleiso[*row + 1][fdf->col - 1]->y;
		fdf->second->z = fdf->tripleiso[*row + 1][fdf->col - 1]->z;
	}
	if (flag == 4)
	{
		fdf->first->x = fdf->tripleiso[fdf->row - 1][*col]->x;
		fdf->first->y = fdf->tripleiso[fdf->row - 1][*col]->y;
		fdf->first->z = fdf->tripleiso[fdf->row - 1][*col]->z;
		fdf->second->x = fdf->tripleiso[fdf->row - 1][*col + 1]->x;
		fdf->second->y = fdf->tripleiso[fdf->row - 1][*col + 1]->y;
		fdf->second->z = fdf->tripleiso[fdf->row -1][*col + 1]->z;
	}
}

void	firstandsecond(t_fdf *fdf)
{
	int col;
	int row;

	row = 0;
	while (row < fdf->row - 1)
	{
		col = 0;
		while (col < fdf->col - 1)
		{
			pointscontinue(fdf, &row, &col, 1);
			drawline(fdf);
			pointscontinue(fdf, &row, &col, 2);
			drawline(fdf);
			col++;
		}
		row++;
	}
	row = 0;
	while (row < fdf->row - 1)
	{
		pointscontinue(fdf, &row, &col, 3);
		drawline(fdf);
		row ++;
	}
	col = 0;
	while (col < fdf->col - 1)
	{
		pointscontinue(fdf, &row, &col, 4);
		drawline(fdf);
		col++;
	}
}
