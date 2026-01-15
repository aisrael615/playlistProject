#include<stdio.h>
#include"interactive_helpers.h"
#include"playback.h"
#include"sort.h"

void interactive_add_song(Playlist *p){
    char song_name[100];
    char artist_name[100];
    char buffer[16];
    int duration;
    char ch;
    printf("Please enter the name of the song (up to 98 chars):\n");
    fgets(song_name, sizeof(song_name), stdin);
        if (strchr(song_name, '\n') == NULL){
            printf("Input is too long!\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
            return;
        }
    printf("Please enter the name of the artist (up to 98 chars):\n");
    fgets(artist_name, sizeof(artist_name), stdin); 
        if (strchr(artist_name, '\n') == NULL){
            printf("Input is too long\n!");
            while ((ch = getchar()) != '\n' && ch != EOF);

            return;
        }
    printf("Please enter the duration of the song as an int:\n");

    fgets(buffer, sizeof(buffer), stdin);  
    duration = atoi(buffer);
    
    playlist_add_song(p, song_name, artist_name, duration);
    printf("Song added!\n");
}

void interactive_delete_song(Playlist *p){
    char song_name[100];
    printf("Please enter the name of the song to delete(up to 100 chars):\n");
    fgets(song_name, sizeof(song_name), stdin);  
    playlist_delete_song(p, song_name);
}

void interactive_sort_playlist(Playlist *p){
        char buffer[16];
        int choice;

        printf("1. Sort by song title\n");
        printf("2. Sort by artist name\n");
        printf("3. Sort by song duration\n");
        
        printf("Enter choice: \n");
        fgets(buffer, sizeof(buffer), stdin);  
        choice = atoi(buffer);

        switch (choice)
        {
        case 1:
            playback_sort_playlist(p, cmp_by_title);
            break;
        case 2:
            playback_sort_playlist(p, cmp_by_artist);
            break;
        case 3:
            playback_sort_playlist(p, cmp_by_duration);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
}