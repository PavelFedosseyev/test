#include "fdf.h"

int ft_abs(double num)
{
	return ((num < 0) ? (num *= -1) : (num *= 1));
}

void	drawhigh(t_fdf *fdf, t_coords * first, t_coords *second)
{
	t_coords	*delta;
	t_coords	*dot;
	int			i;

	i = 1;
	delta = (t_coords *)malloc(sizeof(t_coords));
	dot = (t_coords *)malloc(sizeof(t_coords));
	delta->x = second->x - first->x;
	delta->y = second->y - first->y;
	delta->z = (second->z > first->z) ? (second->z - first->z) : (first->z - second->z);
	if (delta->x < 0)
	{
		i *= -1;
		delta->x = -delta->x;
	}
	dot->x = first->x;
	dot->y = first->y - 1;
	dot->z = 2 * delta->x - delta->y;
	while (++dot->y < second->y)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)dot->x, (int)dot->y, 255255255);
		if (dot->z > 0)
		{
			dot->x = dot->x + i;
			dot->z = dot->z - 2 * delta->y;
		}
		dot->z = dot->z + 2 * delta->x;
	}
}

void	drawlow(t_fdf *fdf, t_coords *first, t_coords *second)
{
	t_coords	*delta;
	t_coords	*dot;
	int			i;	

	i = 1;
	delta = (t_coords *)malloc(sizeof(t_coords));
	dot = (t_coords *)malloc(sizeof(t_coords));
	delta->x = second->x - first->x;
	delta->y = second->y - first->y;
	delta->z = (second->z > first->z) ? (second->z - first->z) : (first->z - second->z);
	if (delta->y < 0)
	{
		i *= -1;
		delta->y = -delta->y;
	}
	dot->x = first->x - 1;
	dot->y = first->y;
	dot->z = 2 * delta->y - delta->x;
	while (++dot->x < second->x)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)dot->x, (int)dot->y, 255255255);
		if (dot->z > 0)
		{
			dot->y = dot->y + i;
			dot->z = dot->z - 2 * delta->x;
		}
		dot->z = dot->z + 2 * delta->y;
	}
}

void	drawline(t_fdf *fdf)
{
	if (ft_abs(fdf->second->y - fdf->first->y) > ft_abs(fdf->second->x - fdf->first->x))
	{
		if (fdf->first->x > fdf->second->x)
			drawlow(fdf, fdf->second, fdf->first);
		else
			drawlow(fdf, fdf->first, fdf->second);
	}
	else
		if (fdf->first->y > fdf->second->y)
			drawhigh(fdf, fdf->second, fdf->first);
		else
			drawhigh(fdf, fdf->first, fdf->second);
}
