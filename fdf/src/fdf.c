#include "fdf.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	t_fdf	fdf;
	
	list = NULL;
	memset(&fdf, 0, sizeof(t_fdf));
	fillzero(&fdf);
	list = openfile(argc, argv);
	countsizes(list, &fdf);
	createintarr(&fdf);
	fillarr(list, &fdf);
	triplearr(&fdf);
	tripleiso(&fdf);
	openwindow(&fdf);
}
