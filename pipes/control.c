#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>



int main(int argc, char *argv[]){
	if (argc == 1) return 0;
	if(!strncmp(argv[1], "-c", strlen(argv[1]))){
		union semun uni;
		int sem = semget(ftok("makefile", 122016), 1, IPC_CREAT | 0644 );
		int mem = shmget( ftok("makefile", 2016), 4, IPC_CREAT | 0644);
		uni.val = 1;
		semctl(sem, 0, SETVAL, uni);
		int file = open("telephone.txt", O_CREAT | O_TRUNC, 0644);
		close(file);
	} else if (!strncmp(argv[1], "-r", strlen(argv[1]))){
		int sem = semget(ftok("makefile", 122016), 1, IPC_CREAT | 0644 );
		int mem = shmget( ftok("makefile", 2016), 4, IPC_CREAT | 0644);
		int file = open("telephone.txt", O_RDONLY, 0664);
		struct stat *words = (struct stat*)malloc(sizeof(struct stat));
		stat("telephone.txt", words);
		if(words->st_size){
			char call[words->st_size];
			read(file, call, words->st_size);
			printf("call transcript:\n%s\n", call);
		}
		close(file);
		semctl(sem, 0, IPC_RMID);
		shmctl(mem, IPC_RMID, 0);
		free(words);
	} else if (!strncmp(argv[1], "-v", strlen(argv[1]))){
		int sem = semget(ftok("makefile", 122016), 1, IPC_CREAT | 0644 );
		int val = semctl(sem, 0, GETVAL);
		int file = open("telephone.txt", O_RDONLY, 0664);
		struct stat *info = (struct stat*)malloc(sizeof(struct stat));
		stat("telephone.txt", info);
		if(info->st_size){
			char message[info->st_size];
			read(file, message, info->st_size);
			printf("message: %s\n", message);
		}
		close(file);
		free(info);
	}
	return 0;
}
