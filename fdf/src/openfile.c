#include "fdf.h"

char	*ft_strdup(char *str)
{
	char *new;
	int i = 0;
	int len = 0;
	
	len = strlen(str);
	new = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

t_list	*filllist(t_list *list, char *line)
{
	t_list	*tmp;
	t_list	*head;
	
	tmp = NULL;
	head = NULL;
	if (!list)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->line = ft_strdup(line);
		tmp->next = NULL;
		return (tmp);
	}
	head = list;
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->line = ft_strdup(line);
	tmp->next = NULL;
	while (head->next)
		head = head->next;
	head->next = tmp;
	return (list);
}

t_list	*openfile(int argc, char **argv)
{
	t_list	*list;
	FILE	*stream;
	char	*line = NULL;
	size_t linecap = 0;

	list = NULL;
	if (argc == 2)
	{
		stream = fopen(argv[1], "r+");
		if (stream == NULL)
		{
			write(1, "invalid file\n", 13); 
			exit (1);
		}
		while (getline(&line, &linecap, stream) > 0)
		{
			list = filllist(list, line);
			free (line);
			line = NULL;
        }
		fclose(stream);
	}
	else
	{
		write(1, "many args\n", 10); 
		exit (1);
	}
	return (list);
}
