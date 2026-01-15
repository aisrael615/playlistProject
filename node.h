#ifndef NODE_H
#define NODE_H

#include"song.h"

typedef struct Node
{
    Song song;
    struct Node *next;
    struct Node *prev;
}Node;

Node *node_create(Song song);
void node_destroy(Node *node);

#endif