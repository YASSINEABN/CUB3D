#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct player {
    int x;
    int y;
    int visited;
}player;

typedef struct queue {
    int x; 
    int y;
    int visited;
    struct queue *next;
} queue;

typedef struct my_map{
    char **texture;
    char **floor;
    char **map;
    int tab[5];
}my_map;

typedef struct list
{
    int value; 
    char *name;
    struct list *next;
}list;

typedef struct listt 
{
    void *node;
    struct listt *next;
}listt;

typedef struct myvar{

listt *list; 
 my_map map;
 char **s;
 int count;
 int i;
 int fd ;
 char *str;
 player player;
 
}myvar;

// typedef struct cub3d
// {
//     char **flor;
//     char **textures;
//     char **map;
// };

char *get_next_line(int fd);
void find_direction(player *player , char **map,listt **node);
queue *add_node(int x,int y, int check,listt **node);
void add_quee(queue **queu , int x, int y , int check,listt **node);
void dequee(queue **queu );
char ** map_to_s(char *s , int count ,listt **node);
void mylist(void *node, listt **nodee);
void	garbage_collector(listt **lst, void (*del)(void *));
// void	garbage_collector2(list **lst, void (*del)(void *));
void add_to_listt(char **ss,listt **node);


#endif
