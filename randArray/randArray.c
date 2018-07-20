#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int readrand() {
  int reader = open("/dev/random", O_RDONLY);
  int *memory = malloc(4);
  if(reader+1){
    read(reader, memory, 4);
    int num = *memory;
    free(memory);
    close(reader);
    return num;
  }else{
    return -1;
  }
}

int writeArray(int* arr){
  int fd = open("testfile",O_RDWR | O_CREAT, 0644);
  if(fd+1){
    write(fd, arr, 40);
    return close(fd);
  }else{
    return -1;
  }
}

int readArray(int* arr){
  int fd = open("testfile",O_RDWR | O_CREAT, 0644);
  if(fd+1){
    read(fd, arr, 40);
    return close(fd);
  }else{
    return -1;
  }
}

int main() {
  int array[10];
  printf("Generating random numbers:\n");
  int count;
  for(count=0; count<10; count++){
    array[count] = readrand();
    printf("\trandom %d: %d\n", count, array[count]);
  }
  int newarray[10];
  printf("\nWriting numbers to file...\n\n");
  writeArray(array);
  printf("Reading numbers from file...\n\n");
  readArray(newarray);
  printf("Verification that written values were the same:\n");
  for(count=0; count<10; count++){
    printf("\trandom %d: %d\n", count, array[count]);
  }
  return 0;
}
