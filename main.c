#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song.h"
#include "node.h"
#include "playlist.h"
#include "playback.h"
#include "sort.h"


int main(void) {
    Playlist p;
    playlist_init(&p);
    playlist_add_song(&p,"Shape of You", "Ed Sheeran", 240);
    playlist_add_song(&p,"Bohemian Rhapsody", "Queen", 355);
    playlist_add_song(&p,"Blinding Lights", "The Weeknd", 200);
    playback_sort_playlist(&p, cmp_by_duration);
    playlist_display(p);

    
    
    // playlist_display(p);
    // playlist_get_len(p);
    // playlist_delete_song(&p, "Shape of You");
    // playlist_display(p);
    // playlist_get_len(p);
    // playlist_delete(&p);
    // playlist_display(p);
    // playlist_get_len(p);
    // playback_current_song(p);
    // playback_previous(&p);
    // playback_current_song(p);
    // playback_next(&p);
    // playback_current_song(p);
    // playback_next(&p);
    // playback_current_song(p);
    // playback_next(&p);
    // playback_current_song(p);
    // playback_restart_playlist(&p);
    // playback_current_song(p);
    // srand((unsigned int)time(NULL));
    // int i;
    // for(i=0; i<3; i++){
    //     playback_shuffle_playlist(&p);
    //     playlist_display(p);
    // }


    return 0;
}