#include "cub3d.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	buffer_readed;
	static int 	buffer_pos;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_readed <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int find_direction(player *player,char **mini_map,listt **node)
{
	int i;
	int j;
	int flag;
	
	flag = 0;
	i = -1;
	while (mini_map[++i])
	{
		j = -1;
		while (mini_map[i][++j])
		{
			
			if(mini_map[i][j] == 'N' || mini_map[i][j] == 'E' || mini_map[i][j] == 'S' )
			{
				(player->x) = i;
				(player->y) = j;
				 flag++;
			}
		}
		if(flag>1)
				return 1;
	}
	return 0;
}

void parse_s(char **s , int count,listt **node)
{
	int check = 0;
	int countt = 0;
	
	while (**s)
	{
		if((**s != '\n' && **s != ' ') && check == 0)
			check = 1;
		else if(**s == '\n' && check == 1)
		{
			check = 0;
			countt++;
		}
		if (countt == count)
			break;
		(*s)++;
	}
	  *s = ft_strtrim(*s , "\n");
		  mylist(*s,node);

		 while (**s == '\n' || **s == ' ')
			(*s)++;
}

void check_s2(char c ,int *check , listt **node)
{
	if(c == '\n' && *check == 0)
			*check =1 ;

			else if( ((c == '\n') && *check == 1))
				{
					printf("error");
					garbage_collector(node,free);
					exit(1);
				}
			else if(c == ' ')
				return ;
			else 
				*check = 0;
}

char ** map_to_s(char *s , int count , listt **node )
{
    char *line;
	int check;
	int i;
	char **str;

check = 0;
i = -1;
parse_s(&s,count,node);
	while (s[++i])
		check_s2(s[i],&check,node);
	str = ft_split(s,'\n');
	add_to_listt(str,node);
	mylist(str,node);
	return str;
}

void mylist(void *node, listt **nodee)
{
	listt *nod = malloc(sizeof(listt));
	
	nod->node =node;
	nod->next = NULL;
	
	if(!*nodee)
		*nodee = nod;
	else 
	{
		listt *head = *nodee;
		while (head->next)
			head = head->next;
			
		head->next = nod;
	}
}

void	garbage_collector(listt **lst, void (*del)(void *))
{
	listt	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->node);
        free(*lst);
		*lst = temp;
	}
}


void add_to_listt(char **ss,listt **node)
{
    int i = -1;

    while (ss[++i])
    {
       mylist(ss[i],node);
    }
    
}