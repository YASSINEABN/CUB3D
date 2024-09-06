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
            if(s[i][j] != '1')
            {
                printf("%d , %d  ====> %c \n",i , j , s[i][j]);
                return 1;
            }
        }

       
        if(s[i][j -1] && s[i][j]==' ' && s[i][j-1] == '0')
            return 1;
         if (s[i][j+1] && s[i][j+1] == '0'  && s[i][j]==' ' )
            return 1;
        return 0;
    }

int check_map2(char **s)
{
int i = 0 , j = 0;
int check =0;

    
    while (s[i])
    {
        s[i] = ft_strtrim(s[i]," ");
        //   if(s[i][j] && (s[i][j] != '1'))
        //         return 1;
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


void check_map(char **s,player p)
{
   
    int x = p.x;
    int y = p.y;
    int i,j = 0;
    queue *queue = NULL;
    // int count = 0;
    
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
            // count++;
        }
        else
            break;
    } 
    //    i = 0, j = 0;

	// 	while (s[i])
	// 	{
            
    //         while (s[i][j])
    //         {
    //             if(i == p.x && j == p.y)
    //             {
    //                 printf("k");
    //             }
    //             else
    //                 printf("%c",s[i][j]);
    //             j++;
    //         }
    //         printf("\n");
    //             j = 0;
    //         i++;
	// 	}
    if(check_map2(s))
    {
            printf("mrid fkrk ollh");
            exit(1);
    }

    }

int main()
{

    char **s;
    player player;
   
    int i = 0;
    
    int fd = open("map.cub",O_RDWR);
    if(!fd)
        return -1;
    
     s = map_to_s(fd);
     find_direction(&player,s);
     check_map(s,player);
    //  printf("%c",s[player.x][player.y]);
    //  while (*s)

    //  {
    //     printf("%c",*s);
    //     s++;
    //  }

     return 0;
}