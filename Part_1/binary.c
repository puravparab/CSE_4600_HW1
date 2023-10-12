#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	pid_t child_pid, parent_pid;
	
	printf("\nCreate a binary tree of the processes:\n");
	for (int i = 0; i < 2; i++){
		if (fork() == 0) {
			child_pid = getpid();
			parent_pid = getppid();
			printf("1. Child Process (ID): %d, parent process (ID): %d\n", child_pid, parent_pid);

			if (i == 0) {
				fork();
				child_pid = getpid();
				parent_pid = getppid();
				printf("2. Child Process (ID): %d, parent process (ID): %d\n", child_pid, parent_pid);
			}
			exit(0);
		}
		wait(NULL);
	}
	}
	

