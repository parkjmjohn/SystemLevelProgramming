#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"
#include "Playlist.h"

int main(){ 
/* Introduction */ 
  printf("Production of Matthew So and John Park\n"); 
  printf("Period 4\n"); 
  printf("Project 0: Tunez\n"); 
  printf("October 21, 2016\n"); 
/* Initialization */ 
  song_node* test = insert_front( "blank space", "taylor swift",0);
  test = insert_front( "never", "taylor swift",test);
  test = insert_front( "work", "rhianna",test);
  test = insert_front("singleladies", "beyonce",test); 
/* Testing find */
  printf("Testing find:\n"); 
  printf("t artists: "); 
  print_list(test);
  printf("\nlooking for *work - rhianna*"); 
  print_single(find_name("work",test));
  printf("\nlooking for *halo - beyonce*"); 
  print_single(find_name("halo",test));
/* Testing find_artist2: */ 
  printf("\nTesting find_artist2::\n"); 
  printf("looking for *taylor swift*");
  print_single(find_artist("taylor swift",test));
  printf("\nlooking for *rhianna*");
  print_single(find_artist("rhianna",test));
  printf("\nlooking for *rebecca black*");
  print_single(find_artist( "rebecca black",test));
/* Testing print_letter*/ 
  printf("\nplist\n");
  print_single(test);
/* Testing print_letter*/ 
  printf("\nplist\n");
  print_single(test);
/* Test random choosing*/
  printf("\nrandom choosing:\n");
  print_single(random_node(test));
  printf("\nrandom selection:\n");
  print_single(random_node(test));
  printf("\nrandom selection:\n");
  print_single(random_node(test));
/* Testing remove_song*/ 
  test = remove_song(test, 2);
  printf("\nremoving second song in playlist:\n");
  print_list(test);
  printf("\n");
  free_list(test);
  return 0; 
}
