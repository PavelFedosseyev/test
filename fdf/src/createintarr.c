#include "fdf.h"

void	createintarr(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (!(fdf->intarr = (int **)malloc(sizeof(int *) * (fdf->row))))
		return ;
	while (i < fdf->row)
	{
		if (!(fdf->intarr[i] = (int *)malloc(sizeof(int) * (fdf->col))))
			return ;
		i++;
	}
}
