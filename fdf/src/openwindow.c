#include "fdf.h"

int closewindow(void *param)
{
	(void)param;
	exit (0);
	return (0);
}

int	esc(int key)
{
	if (key == 53)
		exit (0);
	return (0);
}

void	openwindow(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1024, 1024, "FDF");
	firstandsecond(fdf);
	mlx_hook(fdf->win_ptr, 17, 0, closewindow, (void *)0);
	mlx_hook(fdf->win_ptr, 2, 0, esc, (void *)0);
	mlx_loop(fdf->mlx_ptr);	
}
