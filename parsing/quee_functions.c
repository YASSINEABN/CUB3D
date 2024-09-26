#include "cub3d.h"

queue *add_node(int x,int y, int check , listt **node)
{
    queue *queue  = malloc(sizeof(queue));
     queue->x = x;
    queue->y= y;
    queue->visited = 1;
    queue->next=NULL;

    return queue;
} 
 
void add_quee(queue **queu , int x, int y , int check , listt **node)
{
        queue *queuee  = malloc(sizeof(queue));
        queuee->x = x;
        queuee->y= y;
        queuee->visited = 1;
        queuee->next = NULL;
        mylist(queuee,node);

    if(!(*queu))
        *queu = queuee;
        // *queu = add_node(x,y,check,node);
    else
    {
        queue *head =*queu;
        while ((head)->next)
            (head) = (head)->next;
        
        head->next = queuee;
        // (head)->next = add_node(x,y,check,node);
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