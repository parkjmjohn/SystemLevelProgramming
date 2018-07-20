#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {int i; struct node *next;};

void print_list(struct node *list) {
  if(list) {
      printf("%d ", list->i);
      print_list(list->next);
    }
  else {
    printf("\n");
      }
} 

struct node* insert_front(struct node *list, int data) {
  struct node *newFront = (struct node*)malloc(sizeof(struct node));
  newFront->i = data;
  newFront->next = list;
  return newFront;
}

struct node* free_list(struct node* list){
  free(list);
  if (list->next != 0) {
    free_list(list->next);
  }
}

int main() {
  struct node *new = (struct node*) malloc( sizeof (struct node));
  new->i = 5;
  new->next = 0;
  printf("Initiatizlied\n");
  struct node *s1;
  new = insert_front(new, 0);
  new = insert_front(new, 1);
  print_list(new);
  free_list(new);
  printf("Should be : 1 0 5\n");
  return 0;
}
