#include "cub3d.h"

queue *add_node(int x,int y, int check)
{
    queue *queue  = malloc(sizeof(queue));
    queue->next=NULL;
    queue->x = x;
    queue->y= y;
    queue->visited = 1;
    return queue;
} 
 
void add_quee(queue **queu , int x, int y , int check)
{
    if(!(*queu))
    {
        *queu=add_node(x,y,check);
    }
    else
    {
        queue *head =*queu;
        while ((head)->next)
        {
            (head) = (head)->next;
        }
        (head)->next = add_node(x,y,check);
    }
    
}

void dequee(queue **queu )
{
    if(!(*queu))
        return ;
    if(!(*queu)->next)
    {
       *queu = NULL;
       
    }
    else
    {
        queue *front  = *queu;
        *queu = front->next;
        front=NULL;
    }

}