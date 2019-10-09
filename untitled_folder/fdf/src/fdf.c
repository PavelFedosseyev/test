#include "fdf.h"

t_line	*filllist(t_line *list, char *line)
{
	t_line	*tmp;
	t_line	*head;

	tmp = NULL;
	head = NULL;
	if (!list)
	{
		tmp = (t_line *)malloc(sizeof(t_line));
		tmp->line = ft_strdup(line);
		tmp->next = NULL;
		return (tmp);
	}
	head = list;
	tmp = (t_line *)malloc(sizeof(t_line));
	tmp->line = ft_strdup(line);
	tmp->next = NULL;
	while (head->next)
		head = head->next;
	head->next = tmp;
	return (list);
}

t_line	*openfile(int fd)
{
	t_line	*list;
	char	*line;

	list = NULL;
	if (fd == -1)
		write(1, "Invalid file\n", 1);
	while (get_next_line(fd, &line) == 1)
	{
		list = filllist(list, line);
		free (line);
	}
	return (list);
}

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

int		main(int argc, char **argv)
{
	t_line	*list;
	t_fdf	fdf;

	if (argc == 2)
	{
		list = NULL;
		ft_memset(&fdf, 0, sizeof(t_fdf));
		fillzero(&fdf);
		list = openfile(open(argv[1], O_RDWR));
		intarr(list, &fdf);
		fillarr(list, &fdf);
		tripleiso(&fdf);
		fdf.mlx_ptr = mlx_init();
		fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1024, 1024, "FDF");
		firstandsecond(&fdf);
		mlx_hook(fdf.win_ptr, 17, 0, closewindow, (void *)0);
		mlx_hook(fdf.win_ptr, 2, 0, esc, (void *)0);
		mlx_loop(fdf.mlx_ptr);
	}
}
