#include<stdlib.h>

#include"node.h"
#include"playlist.h"
#include"utils.h"
#include"sort.h"

void playback_next(Playlist *p){
    Node *cur = p->cur;

    if (!cur){
        printf("Playlist is empty!\n");
    }
    else if (!(cur->next)){
        printf("Already at End of Playlist!\n");
    }
    else{
        printf("Next Song!\n");
        p->cur = cur->next;

    }
}

void playback_previous(Playlist *p){
    Node *cur = p->cur;

    if (!cur){
        printf("Playlist is empty!\n");
    }
    else if (!(cur->prev)){
        printf("Already at Start of Playlist!\n");
    }
    else{
        printf("Prev Song!\n");
        p->cur = cur->prev;
    }
}

void playback_restart_playlist(Playlist *p){
    printf("Restarting playlist\n");
    p->cur = p->head;
}

void playback_current_song(Playlist p){
    if (p.cur){
        printf("Currently playing: %s\n",p.cur->song.title);
    }
    else{
        printf("No current song!\n");
    }
}



Playlist *playback_shuffle_playlist(Playlist *playlist){
    int playlistLen = playlist_get_len(*playlist);
    Node **playlistArray = (Node **)malloc(sizeof(Node *) * playlistLen);
    Node *cur;
    int i;
    // Make array of list 
    for(i = 0, cur = playlist->head; cur != NULL; i++, cur = cur ->next){
        playlistArray[i] = cur;
    }
    
    shuffle_array((void **)playlistArray, playlistLen);
    
    // Turn array into list
    for (i = 0; i < playlistLen; i++){
        cur = playlistArray[i];
        if (i > 0){
            cur -> prev = playlistArray[i-1];
        }
        else {
            cur->prev = NULL;
        }
        if (i < playlistLen - 1){
            cur -> next = playlistArray[i+1];
        }
        else{
            cur ->next = NULL;
        }
    }

    // Set head and cur to start
    playlist->head = playlistArray[0];
    playlist->cur = playlistArray[0];
    return playlist;

}

void playback_sort_playlist(Playlist *playlist, int (*cmp)(const Song*, const Song*)){
    playlist->head = merge_sort_recur(playlist->head, cmp);
    playlist->cur = playlist->head;
}