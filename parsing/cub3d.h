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

// typedef struct cub3d
// {
//     char **flor;
//     char **textures;
//     char **map;
// };

char *get_next_line(int fd);
char **map_to_s(int fd);
void find_direction(player *player , char **map);
queue *add_node(int x,int y, int check);
void add_quee(queue **queu , int x, int y , int check);
void dequee(queue **queu );

#endif
