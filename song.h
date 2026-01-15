#ifndef SONG_H
#define SONG_H

#define MAX_TITLE  100
#define MAX_ARTIST 100

typedef struct Song 
{
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int duration; // duration in seconds
}Song;

Song song_create(const char *title, const char *artist, int duration);


#endif