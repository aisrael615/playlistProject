#ifndef PLAYBACK_H
#define PLAYBACK_H

#include"node.h"
#include"playlist.h"



void playback_next(Playlist *p);
void playback_previous(Playlist *p);
void playback_restart_playlist(Playlist *p);
void playback_current_song(Playlist p);
Playlist *playback_shuffle_playlist(Playlist *p);
void playback_sort_playlist(Playlist *playlist, int (*cmp)(const Song*, const Song*));

#endif