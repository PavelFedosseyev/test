#ifndef FDF_H
# define FDF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct		s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

typedef struct		s_coords
{
	double			x;
	double			y;
	double			z;
}					t_coords;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_coords		*first;
	t_coords		*second;
	int				col;
	int				row;
	int				**intarr;
	t_coords		***triplearr;
	t_coords		***tripleiso;
}					t_fdf;

int					main(int argc, char **argv);
void				fillzero(t_fdf *fdf);
t_list				*openfile(int agrc, char **argv);
void				countsizes(t_list *list, t_fdf *fdf);
void				createintarr(t_fdf *fdf);
void				fillarr(t_list *list, t_fdf *fdf);
void				triplearr(t_fdf *fdf);
void				tripleiso(t_fdf *fdf);
void				openwindow(t_fdf *fdf);
void				drawline(t_fdf *fdf);
void				firstandsecond(t_fdf *fdf);




#endif
