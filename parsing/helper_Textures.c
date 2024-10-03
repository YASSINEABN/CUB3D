#include "cub3d.h"

int	check_texture(char *s, list **list, int *countt, listt **nodee)
{
	char	**ss;

	ss = ft_split(s, ' ');
	add_to_listt(ss, nodee);
	mylist(ss, nodee);
	if (count(ss) == 2)
	{
		if (open(ss[1], O_RDONLY) == -1)
			return (1);
		add_node_list(ss[0], list, countt, nodee);
	}
	return (0);
}

int	check_s(char **s, list **list, int *count, listt **nodee)
{
	int		i;
	int		j;
	char	**k;

	i = -1;
	j = 0;
	while (s[++i] && (k = ft_split(s[i], ' ')))
	{
		add_to_listt(k, nodee);
		mylist(k, nodee);
		if (k)
		{
			if (!k[0])
				continue ;
			check_texture_floor(k[0], s[i], nodee, count, list);
		}
		if (*count == 6)
			break ;
	}
	return (0);
}

void	check_texture_floor(char *c, char *s, listt **nodee, int *count,
		list **list)
{
	if ((!ft_strncmp(c, "NO", 2)) || (!ft_strncmp(c, "SO", 2)) || !ft_strncmp(c,
			"WE", 2) || !ft_strncmp(c, "EA", 2))
		check_texture(s, list, count, nodee);
	else
		check_floor(s, list, count, nodee);
}

int	check_floor(char *s, list **listo, int *countt, listt **node)
{
	char	*sss;
	int		i;
	char	**ss;

	if (process_s(&s, &sss, node))
		return (1);
	i = -1;
	ss = ft_split(s, ',');
	add_to_listt(ss, node);
	mylist(ss, node);
	if (count(ss) != 3 || s[ft_strlen(s) - 1] == ',')
		return (1);
	while (ss[++i])
		if (check_ss(ss[i], node) || ft_atoi(ss[i]) < 0 || ft_atoi(ss[i]) > 255)
			return (1);
	add_node_list(sss, listo, countt, node);
	return (0);
}

int	process_s(char **s, char **ss, listt **node)
{
	*s = ft_strtrim(*s, " ");
	mylist(*s, node);
	*ss = *s;
	if (!((**s == 'C' || **s == 'F') && s[0][1] == ' '))
		return (1);
	(*s)++;
	*s = ft_strtrim(*s, " ");
	mylist(*s, node);
	(*ss)[1] = 0;
	return (0);
}
