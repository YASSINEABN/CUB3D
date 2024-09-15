#include "cub3d.h"
int check =0;

int check_xy(int x , int y , char **s)
{
    if (( s[x-1][y] == ' ') || (s[x][y-1] == ' ') || 
        (s[x+1][y] == ' ') || (  s[x][y+1] == ' ' ))
        return 1;
    return 0;
}

void print_queue(queue **q)
{
    while (*q)
    {
        printf("%d, %d\n", (*q)->x, (*q)->y);
        (*q) = (*q)->next;
    }
}

void do_something(int x , int y , char **s,queue **queue)
{
     if(s[x][y] && s[x][y] == '0')
        add_quee(queue,x,y,1);
    if(s[x-1][y] && s[x-1][y] == '0')
        add_quee(queue,x-1,y,0);
      if(s[x][y+1] && s[x][y+1] == '0')
        add_quee(queue,x,y+1,0);
    if(s[x+1][y] && s[x+1][y] == '0')
        add_quee(queue,x+1,y,0);
     if(s[x][y+1] && s[x][y-1] == '0')
        add_quee(queue,x,y-1,0);
}
    int simple_check(int i , int j , char **s , int check)
    {
        if( i==0 || check > 0)
        {
            if(check > 0)
                i=check;
            if(s[i][j] != '1' && s[i][j] != ' ' )
                 return 1; 
        }
        else if(s[i][j] == '0')
        {
            if(!(s[i][j+1]) || s[i][j+1] == ' ')
                 return 1;
            if(!(s[i][j-1]) || s[i][j-1] == ' ')
                return 1;
            if(!(s[i-1][j]) || s[i-1][j]== ' ' )
                return 1;
             if(!(s[i+1][j]) || s[i+1][j]== ' ' )
                  return 1;
        }
        return 0;
    }

int check_map2(char **s)
{
int i = 0 , j = 0;
int check =0;
    
    while (s[i])
    {
        if(!(s[i+1]))
            check=i;
    
        while (s[i][j])
        {
                if(simple_check(i,j,s,check))
                    return 1;
                j++;
        }

      j = 0;
      i++;  
    }
    return 0;
}

void add_nodee(char *name , list **listt)
{
  if(!(*listt))
  {
        list *test = malloc(sizeof(list));
    test->name = name;
    test->next=NULL;
    test->value =0;
    (*listt)=test;
  }
  else 
    {
        list *head = *listt;
        while (head->next)
        {
            head = head->next;
        }
        list *test = malloc(sizeof(list));
    test->name = name;
    test->next=NULL;
    test->value =0;
    head->next=test;
    }
}
void add_node_list(char *name  , list **listt, int *countt)
{
    list *head = *listt;

    while ((head))
    {
        if(!ft_strncmp((head)->name,name,ft_strlen(name)))
        {
            (head)->value++;
            (*countt)++;
            return ;
        }
        head = head->next;
    }
    printf("error");
    exit(1);
 
}

void check_map(char **s,player p)
{
    int x = p.x;
    int y = p.y;
    int i,j = 0;
    queue *queue = NULL;
    
    
    while (s[x][y])
    {
       
       if(check_xy(x,y,s))
       {
            printf("space is detected a wld l9hba \n");
            exit(1);
       }
       
       do_something(x , y ,s,&queue);
       dequee(&queue);
        
       s[x][y] = 'V';

        if(queue)
        {
            x = queue->x;
            y = queue->y;
        }
        else
            break;
    } 
    
    if(check_map2(s))
    {
            printf("mrid fkrk ollh\n");
            exit(1);
    }
    }
    
    int count(char **s)
    {
        int i=0;
        while (*s)
        {
            s++;
            i++;
        }
        return i;
        
    }

void check_texture(char *s,my_map *map , list **listt , int *countt)
{
    char **ss = ft_split(s,' ');

    if(count(ss) == 2)
    {
        if(open(ss[1],O_RDONLY) == -1)
        {
            printf(" tq glna lik khrg T9wd \n");
                exit(1);
        }
        add_node_list(ss[0],listt, countt);
    }
}

int check_ss(char *line)
{
    line = ft_strtrim(line , " ");
    int check = 0;
    int i = 0;
    while (*line)
    {
       if(*line == ' ')
        check = 1 ;
        if(check == 1 && *line != ' ' || !ft_isdigit(*line))
            return 1;
        line++;
    }
    return 0;
}

void check_floor(char *s , my_map *map , list **listt , int *countt)
{

    s = ft_strtrim(s," ");
    char *sss = s;
  
    if(!((s[0] == 'C' || s[0] == 'F') && s[1] == ' '))
    {
        printf("wa sahbi ");
        exit(1);
    }
    s++;
    s = ft_strtrim(s," ");
    char **ss = ft_split(s,',');
    if(count(ss) != 3  || s[ft_strlen(s)-1] == ',')
     {
        printf("walhmar  ");
        exit(1);
    }
    int i = 0;
    
    while (ss[i])
    {
        if(check_ss(ss[i]))
        {
            printf("cc cava ");
            exit(1);
        }
        if(ft_atoi(ss[i]) < 0 || ft_atoi(ss[i]) > 255)
        {
            printf("cc cava ");
            exit(1);
        }
        i++;
    }
    char arr[1];
    arr[0] = sss[0];
    arr[1] = 0;
       add_node_list(arr,listt, countt); 

}



char **check_s(char **s, my_map *map, list **listt,  int *count )
{
    int i = 0;
    char **k;
    
    while (s[i])
    {
        
            if(k = ft_split(s[i],' '))
            {
            
                    if((!ft_strncmp(k[0],"NO",2)) || (!ft_strncmp(k[0],"SO",2)) 
                        || !ft_strncmp(k[0],"WE",2) || !ft_strncmp(k[0],"EA",2))
                             check_texture(s[i],map ,listt , count);
                    else 
                    check_floor(s[i],map,listt , count);
            }
           
            i++;

            if(*count == 6)
                break;
    } 
    printf("%d",i);
    exit(1);
    return s+i;
}

void fill_listt(list **listt)
{
    (*listt) =NULL;
    add_nodee("SO",listt);
    add_nodee("WE",listt);
    add_nodee("EA",listt);
    add_nodee("NO",listt);
    add_nodee("F",listt);
    add_nodee("C",listt);
}

int duplicate(list *listt)
{
    while (listt)
    {
        if((listt)->value == 0 || (listt)->value > 1)
            return 1;
      
        (listt) = (listt)->next;
    }
    return 0;
}

int ft_listsize(list *lst)
{
    int i = 0;
    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return i;

}

char ** parse_map(int fd , my_map *map)
{
    int count = 0;
    list *listt = malloc(sizeof(list));
    fill_listt(&listt);
     char *s = ft_strdup("");
     char *line;
  

    while ((line = get_next_line(fd)))
         s = ft_strjoin(s,line);
    
   char **ss =  check_s(ft_split(s,'\n'),map,&listt , &count);

// printf("%d",count);
// exit(1);
      
    if(duplicate(listt) || count != 6)
    {
        printf("honaka mochkil");
        exit(1);
    } 
    return ss;
    
}

int main()
{

  my_map map;
  map.texture = malloc(sizeof(map) *4);
    char **s;
    player player;
   
    int i = 0;
    
    int fd = open("map.cub",O_RDWR);
    if(!fd)
        return -1;

   s  = parse_map(fd , &map);
    

    // while (map.texture[i])
    // {
    //     printf("%s\n",map.texture[i]);
    //     i++;
    // }
    
    // exit(1);
    
    //    map_to_s(fd);

    //  while (*s)
    //  {
    //     printf("%s \n",*s);
    //     s++;
    //  }
     
     find_direction(&player,s);
      check_map(s,player);
     return 0;
}