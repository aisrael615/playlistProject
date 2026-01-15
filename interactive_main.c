#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"interactive_helpers.h"
#include"playback.h"
#include"playlist.h"

int main(void) {
    Playlist p;
    playlist_init(&p);
    char buffer[16];
    int choice;
    srand((unsigned int)time(NULL));

    while(1){
        printf("Please select an option from the menu:\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Play Next\n");
        printf("5. Play Previous\n");
        printf("6. Show Current\n");       
        printf("7. Shuffle Playlist\n");
        printf("8. Restart Playlist\n");
        printf("9. Sort Playlist\n");
        
        printf("Enter choice: \n");
        fgets(buffer, sizeof(buffer), stdin);  
        choice = atoi(buffer);
        
        switch (choice)
        {
        case 1:
            interactive_add_song(&p);
            break;
        case 2:
            interactive_delete_song(&p);
            break;
        case 3:
            playlist_display(p);
            break;
        case 4:
            playback_next(&p);
            break;
        case 5:
            playback_previous(&p);
            break;
        case 6:
            playback_current_song(p);
            break;
        case 7:
            p = *(playback_shuffle_playlist(&p));
            break;
        case 8:
            playback_restart_playlist(&p);
            break;
        case 9:
            interactive_sort_playlist(&p);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }

    }
    return 0;
}

