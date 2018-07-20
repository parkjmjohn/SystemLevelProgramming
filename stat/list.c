#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  struct stat ret;
  char date[25];
  stat("stat.c", &ret);
  strftime(date, 25, "%a %b %d %T %Y", localtime(&(ret.st_ctime)));
  printf("File size - %li\n", ret.st_size);
  printf("Mode - %o\n", ret.st_mode);
  printf("Time of last access - %s\n", date);
  long data = ret.st_size;
  if(data<1000){
    printf("Bytes: %dB\n", data);
  }
  else if(data<1000000){
    printf("Bytes: %fKB\n", data/1000.0);
  }
  else if(data<1000000000){
    printf("Bytes: %fMB\n", data/1000000.0);
  }
  else{
    printf("Bytes: %fGB\n", data/1000000000.0);
  }
  printf("Permissions Linux: \n");
  if(S_IRUSR&ret.st_mode){
    printf("r");
  }
  else{
    printf("-");
  }
  if(S_IWUSR&ret.st_mode){
    printf("w");
  }
  else{
    printf("-");
  }
  if (S_IXUSR&ret.st_mode){
    printf("x");
  }
  else{
    printf("-");
  }
  if(S_IRGRP&ret.st_mode){
    printf("r");
  }
  else{
    printf("-");
  }
  if(S_IWGRP&ret.st_mode){
    printf("w");
  }
  else{
    printf("-");
  }
  if(ret.st_mode&S_IXGRP){
    printf("x");
  }
  else{
    printf("-");
  }
  if(S_IROTH&ret.st_mode){
    printf("r");
  }
  else{
    printf("-");
  }
  if(S_IWOTH&ret.st_mode){
    printf("w");
  }
  else{
    printf("-");
  }
  if(S_IXOTH&ret.st_mode){
    printf("x");
  }
  else{
    printf("-");
  }
  return 0;
}
