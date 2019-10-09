#ifndef FDF_H
# define FDF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

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
	double			deltax;
	double			deltay;
	double			deltaz;
	double			dotx;
	double			doty;
	double			dotz;
}					t_fdf;

int					main(int argc, char **argv);
void				fillzero(t_fdf *fdf);
t_line				*openfile(int fd);
void				countsizes(t_line *line, t_fdf *fdf);
void				createintarr(t_fdf *fdf);
void				fillarr(t_line *line, t_fdf *fdf);
void				intarr(t_line *list, t_fdf *fdf);
//void				triplearr(t_fdf *fdf);
void				tripleiso(t_fdf *fdf);
int					closewindow(void *param);
int					esc(int key);
void				drawline(t_fdf *fdf);
void				firstandsecond(t_fdf *fdf);




#endif
