#include "fdf.h"

int ft_abs(double num)
{
	return ((num < 0) ? (num *= -1) : (num *= 1));
}

void	drawhigh(t_fdf *fdf, t_coords * first, t_coords *second)
{
	int			i;

	i = 1;
	fdf->deltax = second->x - first->x;
	fdf->deltay = second->y - first->y;
	if (fdf->deltax < 0)
	{
		i *= -1;
		fdf->deltax *= -1;
	}
	fdf->dotx = first->x;
	fdf->doty = first->y - 1;
	fdf->dotz = 2 * fdf->deltax - fdf->deltay;
	while (fdf->doty < second->y)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)fdf->dotx, (int)fdf->doty, 255255255);
		if (fdf->dotz > 0)
		{
			fdf->dotx += i;
			fdf->dotz -= 2 * fdf->deltay;
		}
		fdf->dotz += 2 * fdf->deltax;
		fdf->doty++;
	}
}

void	drawlow(t_fdf *fdf, t_coords *first, t_coords *second)
{
	int			i;

	i = 1;
	fdf->deltax = second->x - first->x;
	fdf->deltay = second->y - first->y;
	if (fdf->deltay < 0)
	{
		i *= -1;
		fdf->deltay *= -1;
	}
	fdf->dotx = first->x - 1;
	fdf->doty = first->y;
	fdf->dotz = 2 * fdf->deltay - fdf->deltax;
	while (fdf->dotx < second->x)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)fdf->dotx, (int)fdf->doty, 255255255);
		if (fdf->dotz > 0)
		{
			fdf->doty += i;
			fdf->dotz -= 2 * fdf->deltax;
		}
		fdf->dotz += 2 * fdf->deltay;
		fdf->dotx++;
	}
}

void	drawline(t_fdf *fdf)
{
	if (ft_abs(fdf->second->y - fdf->first->y) < ft_abs(fdf->second->x - fdf->first->x))
		(fdf->first->x > fdf->second->x) ? drawlow(fdf, fdf->second, fdf->first) : drawlow(fdf, fdf->first, fdf->second);
	else
		(fdf->first->y > fdf->second->y) ? drawhigh(fdf, fdf->second, fdf->first) : drawhigh(fdf, fdf->first, fdf->second);
}
