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

void do_something(int x , int y , char **s,queue **queue , listt **node)
{
     if(s[x][y] && s[x][y] == '0')
        add_quee(queue,x,y,1,node);
    if(s[x-1][y] && s[x-1][y] == '0')
        add_quee(queue,x-1,y,0,node);
      if(s[x][y+1] && s[x][y+1] == '0')
        add_quee(queue,x,y+1,0,node);
    if(s[x+1][y] && s[x+1][y] == '0')
        add_quee(queue,x+1,y,0,node);
     if(s[x][y+1] && s[x][y-1] == '0')
        add_quee(queue,x,y-1,0,node);
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

void add_nodee(char *name , list **listo , listt **liste)
{
  if(!(*listo))
  {
        list *test = malloc(sizeof(list));
        mylist(test,liste);
    test->name = name;
    test->next=NULL;
    test->value =0;
    (*listo)=test;
  }
  else 
    {
        list *head = *listo;
        while (head->next)
        {
            head = head->next;
        }
        list *test = malloc(sizeof(list));
         mylist(test,liste);
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

void check_map(char **s,player p ,listt **node)
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
       
       do_something(x , y ,s,&queue,node);
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

void check_texture(char *s,my_map *map , list **list , int *countt,listt **nodee)
{
    char **ss = ft_split(s,' ');
    add_to_listt(ss,nodee);
      mylist(ss,nodee);

    if(count(ss) == 2)
    {
        if(open(ss[1],O_RDONLY) == -1)
        {
            printf(" tq glna lik khrg T9wd \n");
                exit(1);
        }
        add_node_list(ss[0],list, countt);
    }
   
}

int check_ss(char *line , listt **node)
{
    line = ft_strtrim(line , " ");
    mylist(line,node);
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

void check_floor(char *s , my_map *map , list **listo , int *countt , listt **node)
{

 
    s = ft_strtrim(s," ");
    mylist(s,node);
    char *sss = s;
     

  
    if(!((s[0] == 'C' || s[0] == 'F') && s[1] == ' '))
    {
        printf("wa sahbi ");
        exit(1);
    }
    s++;
    s = ft_strtrim(s," ");
    mylist(s,node);
    char **ss = ft_split(s,',');
    add_to_listt(ss,node);
    mylist(ss,node);
    if(count(ss) != 3  || s[ft_strlen(s)-1] == ',')
     {
        printf("walhmar  ");
        exit(1);
    }
    int i = 0;
    
    
    while (ss[i])
    {
        if(check_ss(ss[i],node))
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
      
       add_node_list(arr,listo, countt); 

}



void check_s(char **s, my_map *map, list **list,  int *count , listt **nodee)
{
   
    int i = -1;
    int j = 0;
    char **k = NULL;

 
    while (s[++i])
    {
        
        k = ft_split(s[i],' ');
        add_to_listt(k,nodee);
         mylist(k,nodee);

            if(k)
            {
                if(!k[0])
                    continue;              
                    if((!ft_strncmp(k[0],"NO",2)) || (!ft_strncmp(k[0],"SO",2)) 
                        || !ft_strncmp(k[0],"WE",2) || !ft_strncmp(k[0],"EA",2))
                             check_texture(s[i],map ,list , count,nodee);
                    else 
                    check_floor(s[i],map,list , count,nodee);

            }
            
            if(*count == 6)
                break;
    } 

    
}

void fill_listt(list **listo , listt **liste)
{
    (*listo) = NULL;
    add_nodee("SO",listo,liste);
    add_nodee("WE",listo,liste);
    add_nodee("EA",listo,liste);
    add_nodee("NO",listo,liste);
    add_nodee("F",listo,liste);
    add_nodee("C",listo,liste);
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



void parse_map(int fd , my_map *map ,int *count , char **str , listt **node)
{
   
    list *listt = malloc(sizeof(list));
    mylist(listt,node);
    fill_listt(&listt ,node);

     char *s = ft_strdup("");
    mylist(s,node);

     char *line;
  

    while ((line = get_next_line(fd)) )
    {
        mylist(line, node);
         s = ft_strjoin(s,line);
         mylist(s,node);
    }

        *str =s;
    char **ss = ft_split(s,'\n');
     mylist(ss,node);
     add_to_listt(ss,node);
    
    check_s(ss,map,&listt , count,node);

    if(duplicate(listt) || *count != 6)
    {
        printf("honaka mochkil");
        exit(1);
    } 
}


int main()
{
 listt *list=NULL;

  my_map map;
  map.texture = malloc(sizeof(map) *4);
  mylist(map.texture,&list);

   
    char **s = NULL;
    char *str = NULL;
    player player;
    int count = 0;
   
    int i = 0;
    
    int fd = open("map.cub",O_RDWR);
    if(!fd)
        return -1;

    parse_map(fd , &map , &count , &str , &list);
 
      s = map_to_s(str, count,&list);
      find_direction(&player,s,&list);
       check_map(s,player,&list);
       garbage_collector(&list,free);
     return 0;
}

