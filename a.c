#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

struct Song {
    char title[100];
    char artist[100];
};

struct Playlist {
    struct Song songs[MAX_SONGS];
    int count;
    int currentSongIndex;
};

void addSong(struct Playlist *playlist, const char *title, const char *artist) {
    if (playlist->count < MAX_SONGS) {
        strcpy(playlist->songs[playlist->count].title, title);
        strcpy(playlist->songs[playlist->count].artist, artist);
        playlist->count++;
    } else {
        printf("Playlist is full, cannot add more songs.\n");
    }
}

void playSong(struct Playlist *playlist) {
    if (playlist->count > 0) {
        printf("Playing: %s by %s\n", playlist->songs[playlist->currentSongIndex].title, playlist->songs[playlist->currentSongIndex].artist);
    } else {
        printf("No songs in the playlist to play.\n");
    }
}

void skipSong(struct Playlist *playlist) {
    if (playlist->count > 0) {
        playlist->currentSongIndex = (playlist->currentSongIndex + 1) % playlist->count;
        printf("Skipping to next song...\n");
        playSong(playlist);
    } else {
        printf("No songs in the playlist to skip.\n");
    }
}

int main() {
    struct Playlist playlist = { .count = 0, .currentSongIndex = 0 };

    addSong(&playlist, "Song 1", "Artist 1");
    addSong(&playlist, "Song 2", "Artist 2");
    addSong(&playlist, "Song 3", "Artist 3");

    playSong(&playlist);

    skipSong(&playlist);
    skipSong(&playlist);

    return 0;
}
