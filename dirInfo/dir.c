#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int add(DIR* count, unsigned char input) {
  int ret = 0;
  struct stat data;
  struct dirent* det;
  while(det=readdir(count)){
    if(det->d_type==input){
      printf("\t %s\n", det->d_name);
      if(det->d_type==DT_REG){
	stat(det->d_name, &data);
	ret+=data.st_size;
      }
    }
  }
  /* if(errno){ */
  /*   printf("Error #%d, %s\n", errno, strerror(errno)); */
  /* } */
  return ret;
}

int main(){
  DIR *dir = opendir(".");
  printf("Statistics for directory: .\n");
  printf("Directory:\n");
  add(dir, DT_DIR);
  rewinddir(dir);
  printf("Regular files:\n");
  int i = 0;
  printf("Total Directory Size: %d Bytes\n", i+=add(dir, DT_REG));
  closedir(dir);
  /* if(errno){ */
  /*   printf("Error #%d, %s\n", errno, strerror(errno)); */
  /* } */
  return 0;
}
