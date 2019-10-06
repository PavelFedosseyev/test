#include "fdf.h"

void	fillzero(t_fdf *fdf)
{
	fdf->first = (t_coords *)malloc(sizeof(t_coords));
	fdf->second = (t_coords *)malloc(sizeof(t_coords));
	fdf->first->x = 0;
	fdf->first->y = 0;
	fdf->first->z = 0;
	fdf->second->x = 0;
	fdf->second->y = 0;
	fdf->second->z = 0;
	fdf->col = 0;
	fdf->row = 0;
}
