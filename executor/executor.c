#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
  printf("What would you like to do? ");
  int mem = 1000; 
  char ret[mem];
  char *sret = ret;
  char *line [mem];
  char *boolin;
  gets(ret);
  int i = 0;
  while(boolin!=0){
    boolin = strsep(&sret," ");
    line[i] = boolin;
    i++;
  }
  execvp(line[0], line);
  return 0;
}
