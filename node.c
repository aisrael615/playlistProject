#include <stdlib.h>

#include"node.h"


Node *node_create(Song song){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->song = song;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}


void node_destroy(Node *node){
    free(node);
}