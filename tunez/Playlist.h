#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"
#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef song_node table[26];

void add_song(table * , char *, char *);

song_node *search_name(table *, char *);

void print_letter(table *, char c);

void print_artist(table *, char *);

void print_library(table *);

void shuffle(table *);

void delete_song(table *, char *, char *);

void delete(table *);

#endif
