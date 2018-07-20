/* John Park and Matthew So */
/* Period 4 */
/* Project 0: Tunez */
/* October 21, 2016 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List.h"

song_node * insert_front(char nname[256], char nartist[256], song_node *SN) {
  song_node * add = (song_node * )calloc(1,sizeof(song_node));
  strncpy(add->name, nname, 256);
  strncpy(add->artist, nartist, 256);
  add->next = SN;
  return add;
}

 void print_list( song_node * SN ) {
   printf("[ "); 
   while(SN) {
     printf("\t[%s] by %s,\n", (*SN).name, (*SN).artist) ; 
     SN = SN->next; 
  } 
   printf("]\n"); 
 }

 void print_single( song_node * SN ) {
   printf("[ ");
   if(SN){
     printf("\t[%s] by %s,\n", (*SN).name, (*SN).artist) ;}
   printf("]\n"); 
 } 


size_t length(song_node * SN) {
    int ret = 0;
    for (; SN != 0; SN = SN->next){
      ret+=1;
    }
    return ret;
}

song_node * find_artist(char nartist[256], song_node * SN) {
  for (; SN != 0; SN = SN->next) {
    if (strncmp(nartist, SN->artist, 256) == 0) {
    return SN;
    }
  }
  return 0;
}

song_node * find_name(char nname[256], song_node * SN) {
  for (; SN != 0; SN = SN->next) {
    if (strncmp(nname, SN->name, 256) == 0) {
    return SN;
    }
  }
  return 0;
}

song_node *random_node(song_node *SN) {
    int i  = rand()%length(SN);
    for (; i > 0; SN = SN->next) {
      i += -1;
    }
    return SN;
}

song_node * remove_song(song_node * SN, int i) {
  song_node * temp = SN;
  int len = length(SN);
  if (i != 0){
    int ctr = 0;
    for (;ctr < i; ctr++){
      temp = temp->next;
    }
    song_node * passNext = temp->next;
    passNext = passNext->next;
    free(temp->next);
    temp->next=passNext;
  }
  else{
    temp = temp->next;
    free(temp);
  }
  return temp;
}

void free_list( song_node * SN ) {
  song_node *f = SN;
  while ( SN ) {
    SN = SN->next;
    printf("freeing node: %d\n", f->name );
    free(f);
    f = SN;    
  }
}


song_node * insert_ordered(char nname[256], char nartist[256], song_node *SN) {
  int nartist_ordered = strncmp(SN->artist, nartist, 256);
  song_node* one = SN;
  song_node* two = SN->next;
  if (nartist_ordered == 0) {
    return strncmp(SN->name, nname, 256);
  }
  else if (nartist_ordered > 0) {
      return insert_front(nname, nartist, SN);
  } else {
    while(69) {
      if(two==0) {
	song_node* end = (song_node*)calloc(1,sizeof(song_node));
        strncpy(end->name, nname, 256);
        strncpy(end->artist, nartist, 256);
        end->next = 0;
        one->next = end;
        break;	
  }
      if(strncmp(two->artist, nartist,256) > 0) {
        one->next = insert_front(nname, nartist, two);
        break;
  }
	one = two;
        two = two->next;
  }
  return SN;
}
} 
