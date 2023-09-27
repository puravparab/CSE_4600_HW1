#include <stdio.h>
#include <unistd.h>

int main(){
	int value = fork();              //parent creates child process
	if (value == 0){                 // checks if process is child
		fork();                  // child creates child process
		if (getpid() % 2 == 0){  // checks if PID is even
			fork();          // creates child process 
		}
	} else {
		fork();                 //parent creates child process
	}

	printf("Hello from PID: %d, PPID: %d\n", getpid(), getppid());
	sleep(2);
	return 0;
}
