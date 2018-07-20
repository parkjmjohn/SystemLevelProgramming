#include <stdio.h>
#include <stdlib.h>
#ifndef LINK_LIST_H
#define LINK_LIST_H


typedef struct song_node{
  char artist[256];
  char name[256];
  struct song_node* next;
} song_node;

song_node * insert_front(char* ,char*,song_node*);

song_node * insert_inOrder(song_node*,char*,char*);

void print_list(song_node *);
void print_single(song_node *);

size_t length(song_node * );

song_node *find_artist(char *, song_node *);

song_node* find_name(char *, song_node *);

song_node* random_node( song_node *);

song_node* remove_song( song_node *,int);

void free_list( song_node*);

#endif
