#include "cub3d.h"

int	count(char **s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

int	duplicate(list *listt)
{
	while (listt)
	{
		if ((listt)->value == 0 || (listt)->value > 1)
			return (1);
		(listt) = (listt)->next;
	}
	return (0);
}

int	parse_map(myvar *var)
{
	list	*listt;
	char	*line;
	char	*s;
	char	**ss;

	list_fill(&listt, &(var->list));
	s = ft_strdup("");
	mylist(s, &(var->list));
	while ((line = get_next_line(var->fd)))
		store_line(&line, var, &s);
	var->str = s;
	ss = ft_split(s, '\n');
	mylist(ss, &(var->list));
	add_to_listt(ss, &(var->list));
	if (check_s(ss, &listt, var) || duplicate(listt)
		|| var->count != 6)
		return (1);
	var->s = map_to_s(var->str, var->count, &(var->list));
	return (0);
}

int check_extension(char *str ,char *s)
{
	int i; 

	i = ft_strlen(str) - 4;


	if(!ft_strncmp(str+i,s,i))
		return 1;
	else
		return 0;
}


void	init(myvar *var , int argc , char **argv)
{
	var->s = NULL;
	var->list = NULL;
	var->str = NULL;
	var->count = 0;
	var->map.texture = malloc(sizeof(var->map) * 4);
	mylist(var->map.texture, &(var->list));
	var->fd = open("map.cub", O_RDWR);
	
	if(!(check_extension(argv[1], ".cub")) || argc !=2 )
		var->fd = -1;
}

int	main(int argc , char **argv)
{
	myvar	var;

	init(&var, argc , argv);
	if (!var.fd)
		return (-1);
	if (parse_map(&var) || find_direction(&var.player, var.s)
		|| check_map(var.s, var.player, &var.list))
	{
		printf("error ");
		return (garbage_collector(&var.list, free), 1);
	}
	
	return (garbage_collector(&var.list, free), 1);
	
}
