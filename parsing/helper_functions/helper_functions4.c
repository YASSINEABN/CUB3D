#include "../cub3d.h"

int	simple_check(int i, int j, char **s, int check)
{
	if (i == 0 || check > 0)
	{
		if (check > 0)
			i = check;
		if (s[i][j] != '1' && s[i][j] != ' ')
			return (1);
	}
	else if (s[i][j] == '0')
	{
		if (!(s[i][j + 1]) || s[i][j + 1] == ' ')
			return (1);
		if (!(s[i][j - 1]) || s[i][j - 1] == ' ')
			return (1);
		if (!(s[i - 1][j]) || s[i - 1][j] == ' ')
			return (1);
		if (!(s[i + 1][j]) || s[i + 1][j] == ' ')
			return (1);
	}
	return (0);
}

void	store_line(char **line, myvar *var, char **s)
{
	mylist(*line, &(var->list));
	*s = ft_strjoin(*s, *line);
	mylist(*s, &(var->list));
}

void	add_node_list(char *name, list **listo, int *countt, listt **node)
{
	list	*head;

	head = *listo;
	while ((head))
	{
		if (!ft_strncmp((head)->name, name, ft_strlen(name)))
		{
			(head)->value++;
			(*countt)++;
			return ;
		}
		head = head->next;
	}
	printf("error");
	garbage_collector(node, free);
	exit(1);
}

int	check_map(char **s, player p, listt **node)
{
	queue	*queue;

	queue = NULL;
	while (s[p.x][p.y])
	{
		if (check_xy(p.x, p.y, s))
			return (1);
		do_something(p, s, &queue, node);
		dequee(&queue);
		s[p.x][p.y] = 'V';
		if (queue)
		{
			p.x = queue->x;
			p.y = queue->y;
		}
		else
			break ;
	}
	if (check_map2(s))
		return (1);
	return (0);
}

int	check_xy(int x, int y, char **s)
{
	if ((s[x - 1][y] == ' ') || (s[x][y - 1] == ' ') || (s[x + 1][y] == ' ')
		|| (s[x][y + 1] == ' '))
		return (1);
	return (0);
}
