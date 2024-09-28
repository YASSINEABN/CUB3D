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

int check_map(char **s,player p ,listt **node)
{
    int x = p.x;
    int y = p.y;
    int i,j = 0;
    queue *queue = NULL;
  
    while (s[x][y])
    {
       if(check_xy(x,y,s))
            return 1;
       
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
            return 1;
    return 0;
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

int check_texture(char *s , list **list , int *countt,listt **nodee)
{
    char **ss = ft_split(s,' ');
    add_to_listt(ss,nodee);
      mylist(ss,nodee);

    if(count(ss) == 2)
    {
        if(open(ss[1],O_RDONLY) == -1)
               return 1;
        add_node_list(ss[0],list, countt);
    }
    return 0;
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

int check_floor(char *s  , list **listo , int *countt , listt **node)
{
    s = ft_strtrim(s," ");
    mylist(s,node);
    char *sss = s;
     
    if(!((s[0] == 'C' || s[0] == 'F') && s[1] == ' '))
        return 1;
    s++;
    s = ft_strtrim(s," ");
    mylist(s,node);
    char **ss = ft_split(s,',');
    add_to_listt(ss,node);
    mylist(ss,node);
    if(count(ss) != 3  || s[ft_strlen(s)-1] == ',')
        return 1;
    int i = 0;
    
    
    while (ss[i])
    {
        if(check_ss(ss[i],node))
           return 1;
        if(ft_atoi(ss[i]) < 0 || ft_atoi(ss[i]) > 255)
            return 1;
        i++;
    }

    char arr[1];
    arr[0] = sss[0];
    arr[1] = 0;
      
       add_node_list(arr,listo, countt); 
}

int check_texture_floor(char *c , char *s , listt **nodee , int *count ,  list **list)
{
    if((!ft_strncmp(c,"NO",2)) || (!ft_strncmp(c,"SO",2)) 
                        || !ft_strncmp(c,"WE",2) || !ft_strncmp(c,"EA",2))
                            check_texture(s ,list , count,nodee);
                    else 
                    check_floor(s,list , count,nodee);
}

int check_s(char **s, list **list,  int *count , listt **nodee)
{
   
    int i = -1;
    int j = 0;
    char **k = NULL;

 
    while (s[++i] && (k = ft_split(s[i],' ')))
    {
        
        add_to_listt(k,nodee);
         mylist(k,nodee);

            if(k)
            {
                if(!k[0])
                    continue;
                check_texture_floor(k[0],s[i],nodee,count,list);              
                    
            }
            
            if(*count == 6)
                break;
    } 
    return 0;
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

void list_fill(list **list , listt **node)
{
    *list = malloc(sizeof(list));
     mylist(*list,node);
     fill_listt(list ,node);
}

int parse_map(myvar *var)
{
   list *listt;

   list_fill(&listt,&(var->list));
   

     char *s = ft_strdup("");
    mylist(s,&(var->list));
     char *line;
  
    while ((line = get_next_line(var->fd)) )
    {
        mylist(line, &(var->list));
         s = ft_strjoin(s,line);
         mylist(s,&(var->list));
    }

        var->str =s;
    char **ss = ft_split(s,'\n');
     mylist(ss,&(var->list));
     add_to_listt(ss,&(var->list));
    

    if(check_s(ss,&listt , &(var->count),&(var->list)) || duplicate(listt) || var->count != 6)
        return 1;
     var->s = map_to_s(var->str, var->count,&(var->list));
    return 0;
}

 int init(myvar *var)
 {
    var->s = NULL;
    var->list = NULL;
    var->str = NULL;
    var->count = 0;
    var->map.texture = malloc(sizeof(var->map) *4);
    mylist(var->map.texture,&(var->list));
      var->fd = open("map.cub",O_RDWR);
  
 }

int main()
{
     myvar var;

    init(&var);
    
      if(!var.fd)
        return -1;

    if(parse_map(&var) || find_direction(&var.player,var.s,&var.list)
                 || check_map(var.s,var.player,&var.list))
    {
        printf("error");
        return (garbage_collector(&var.list,free),1);
    }
     return (garbage_collector(&var.list,free),1);
}

