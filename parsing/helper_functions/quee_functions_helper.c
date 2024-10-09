#include "../cub3d.h"

queue	*add_node(int x, int y)
{
	queue	*queue;

	queue = malloc(sizeof(queue));
	queue->x = x;
	queue->y = y;
	queue->visited = 1;
	queue->next = NULL;
	return (queue);
}

void	add_quee(queue **queu, int x, int y, listt **node)
{
	queue	*queuee;
	queue	*head;

	queuee = malloc(sizeof(queue));
	queuee->x = x;
	queuee->y = y;
	queuee->visited = 1;
	queuee->next = NULL;
	mylist(queuee, node);
	if (!(*queu))
		*queu = queuee;
	else
	{
		head = *queu;
		while ((head)->next)
			(head) = (head)->next;
		head->next = queuee;
	}
}

void	dequee(queue **queu)
{
	queue	*front;

	if (!(*queu))
		return ;
	if (!(*queu)->next)
	{
		*queu = NULL;
	}
	else
	{
		front = *queu;
		*queu = front->next;
		front = NULL;
	}
}

// void	print_queue(queue **q)
// {
// 	while (*q)
// 	{
// 		printf("%d, %d\n", (*q)->x, (*q)->y);
// 		(*q) = (*q)->next;
// 	}
// }