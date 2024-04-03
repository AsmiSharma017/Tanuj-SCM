#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 100

struct Song {
    char title[MAX_TITLE_LENGTH];
};

struct Playlist {
    struct Song songs[MAX_SONGS];
    int numSongs;
};

void addSong(struct Playlist *playlist, const char *title) {
    if (playlist->numSongs < MAX_SONGS) {
        strcpy(playlist->songs[playlist->numSongs].title, title);
        playlist->numSongs++;
        printf("Song \"%s\" added to playlist.\n", title);
    } else {
        printf("Playlist is full. Cannot add song.\n");
    }
}

void listSongs(const struct Playlist *playlist) {
    printf("Playlist Songs:\n");
    for (int i = 0; i < playlist->numSongs; i++) {
        printf("%d. %s\n", i + 1, playlist->songs[i].title);
    }
}

void removeSong(struct Playlist *playlist, int index) {
    if (index >= 1 && index <= playlist->numSongs) {
        printf("Removed song \"%s\" from playlist.\n", playlist->songs[index - 1].title);
        for (int i = index - 1; i < playlist->numSongs - 1; i++) {
            strcpy(playlist->songs[i].title, playlist->songs[i + 1].title);
        }
        playlist->numSongs--;
    } else {
        printf("Invalid song index.\n");
    }
}

int main() {
    struct Playlist myPlaylist;
    myPlaylist.numSongs = 0;

    addSong(&myPlaylist, "Song 1");
    addSong(&myPlaylist, "Song 2");
    addSong(&myPlaylist, "Song 3");

    listSongs(&myPlaylist);

    removeSong(&myPlaylist, 2);

    listSongs(&myPlaylist);

    return 0;
}
