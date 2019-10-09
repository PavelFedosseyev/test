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
