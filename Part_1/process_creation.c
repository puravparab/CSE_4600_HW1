#include <stdio.h>
#include <unistd.h>

int main(){
	int value = fork();
	if (value == 0){
		fork();
		if (getpid() % 2 == 0){
			fork();
		}
	} else {
		fork();
	}

	printf("Hello from PID: %d, PPID: %d\n", getpid(), getppid());
	sleep(2);
	return 0;
}
