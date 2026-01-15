#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"playlist.h"
#include"node.h"
#include"utils.h"

#define MAX_BUCKETS 100


void playlist_init(Playlist *p){
    p->cur = NULL;
    p->head = NULL;
    p->map = hashmap_create(MAX_BUCKETS);
}

void playlist_add_song(Playlist *playlist, const char *title, const char *artist, int duration){

    if (strlen(title) > 100 || strlen(artist) > 100){
        printf("\nError: input exceeds 100 characters\n");
        return;
    }
    

    Song newSong = song_create(title, artist, duration);
    Node *newNode = node_create(newSong);
    Node *cur;

    if (playlist->head == NULL){
        playlist->head = newNode;
        playlist->cur = newNode;
        newNode->prev = NULL;
    }
    else {
        for(cur = playlist->head; cur->next != NULL; cur=cur->next);
        cur->next = newNode;
        newNode->prev = cur;
    }
    hashmap_put(playlist->map, title, newNode);
    return;
}



void playlist_delete_song(Playlist *playlist, const char *title){
    Node *node_to_delete = (Node *)hashmap_get(playlist->map, title);
    if (!node_to_delete){
        printf("%s not in playlist\n", title);
    }
    else{
        Node *prev = node_to_delete->prev;
        Node *next = node_to_delete->next;
        if(prev){
            prev->next = next;
        }
        if (next){
            next->prev = prev;
        }
        if(node_to_delete == playlist->head){
            playlist->head = node_to_delete->next;
        }
        if(node_to_delete == playlist->cur){
            playlist->cur = playlist->head;
        }
        hashmap_remove(playlist->map, title);
        node_destroy(node_to_delete);
    }
    return;
}

void playlist_display(Playlist playlist){
    Node *head = playlist.head;
    Node *cur;
    if (head == NULL){
        printf("Playlist is empty!");
        return;
    }
    for (cur=head;cur != NULL; cur=cur->next){
        printf("title:%s\nartist:%s\nduration:%d\n\n\n",cur->song.title, cur->song.artist, cur->song.duration);
    }
}

void playlist_delete(Playlist *playlist){
    Node *cur, *next;
    cur = playlist->head;
    while (cur){
        next = cur -> next;
        node_destroy(cur);
        cur = next;
    }
    playlist->head = NULL;
    playlist->cur = NULL;
}

int playlist_get_len(Playlist playlist){
    Node *cur;
    int len;
    for(cur = playlist.head, len = 0; cur != NULL; len++, cur = cur ->next);
    return len;
}