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

// typedef struct cub3d
// {
//     char **flor;
//     char **textures;
//     char **map;
// };

char *get_next_line(int fd);
void map_to_s(char *s , int count );
void find_direction(player *player , char **map);
queue *add_node(int x,int y, int check);
void add_quee(queue **queu , int x, int y , int check);
void dequee(queue **queu );

#endif
