#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int readrand() {
  int reader = open("/dev/random", O_RDONLY);
  int *memory = malloc(4);
  read(reader, memory, 4);
  int num = *memory;
  free(memory);
  close(reader);
  return num;
}

int main() {
  int array[10];
  printf("Generating random numbers:\n");
  int count;
  for(count=0; count<10; count++){
    array[count] = readrand();
    printf("\trandom %d: %d\n", count, array[count]);
  }
  printf("\nWriting numbers to file...\n\n");
  printf("Reading numbers from file...\n\n");
  printf("Verification that written values were the same:\n");
  return 0;
}
