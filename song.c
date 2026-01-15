#include"song.h"
#include<string.h>

Song song_create(const char *title, const char *artist, int duration) {
    Song s;
    strncpy(s.title, title, sizeof(s.title));
    strncpy(s.artist, artist, sizeof(s.artist));
    s.title[sizeof(s.title)-1] = '\0';
    s.artist[sizeof(s.artist)-1] = '\0';
    s.duration = duration;
    return s;
}