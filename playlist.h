#ifndef PLAYLIST_H
#define PLAYLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"node.h"
#include"hash.h"

typedef struct Playlist{
    Node *head;
    Node *cur;
    HashMap *map;
} Playlist;

void playlist_init(Playlist *p);
void playlist_add_song(Playlist *playlist, const char *title, const char *artist, int duration);
void playlist_delete_song(Playlist *playlist, const char *title);
void playlist_display(Playlist playlist);
void playlist_delete(Playlist *playlist);
int playlist_get_len(Playlist playlist);

#endif
