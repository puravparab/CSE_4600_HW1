#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 48
#define NUM_PROCESSES 4

int array[SIZE];
int fds[NUM_PROCESSES][2];

<<<<<<< HEAD
=======

>>>>>>> e0c1eeff3d9121ffb818b66797523d96462654b1
int partial_sum(int start, int end) {
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += array[i];
    }
    return sum;
}

int main() {
<<<<<<< HEAD
    // Fill the array with numbers from 1 to 160.
    for (int i = 0; i < SIZE; i++) {
        array[i] = i + 1;
    }

    int segment_size = SIZE / NUM_PROCESSES;

    // Create loop for the pipes
    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (pipe(fds[i]) == -1) { // Create pipes
            perror("Pipe failed");
            exit(1);
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) { // Children processes

            int partialResult = 0;
            int previous = 0;

            if (i > 0) { // Pipes other than the first pipe
                read(fds[i - 1][0], &previous, sizeof(previous)); // Read value from previous pipe
                close(fds[i - 1][0]); // Close read end of previous pipe
            }
            int start = i * segment_size;
            int end = start + segment_size;
            partialResult = partial_sum(start, end) + previous; 	

            if (i < NUM_PROCESSES - 1) {
            	printf("Partial sum is: %d\n", partialResult);
                close(fds[i][0]); // Close read endof pipe
                write(fds[i][1], &partialResult, sizeof(partialResult));
                close(fds[i][1]); // Close write end of pipe
            }
            else {
            	printf("Total sum is: %d\n", partialResult);
            }

            exit(0);
        }
    }

    // Parent process
    for (int i = 0; i < NUM_PROCESSES; i++) {
        close(fds[i][0]);
        close(fds[i][1]);
    }

    // Wait for children
    for (int i = 0; i < NUM_PROCESSES; i++) {
        wait(NULL);
    }

    return 0;
=======
	// Fill the array with numbers from 1 to 160.
	for (int i = 0; i < SIZE; i++) {
		array[i] = i + 1;
	}
	int segment_size = SIZE / NUM_PROCESSES;
	int total_sum = 0;
	
	for (int i = 0; i < NUM_PROCESSES; i++) {
		if (pipe(fds[i]) == -1) {  // create pipe
			perror("Pipe failed");
			return 1;
			}
		pid_t pid = fork();
		if (pid < 0) {
			perror("Fork failed");
			return 1;
		} else if (pid == 0) { // Child process
			close(fds[i][0]);   // close read end of pipe
			int start = i * segment_size;
			int end = start + segment_size;
			int partialResult = partial_sum(start, end);
			printf("Partial sum is: %d\n", partialResult);
			write(fds[i][1], &partialResult, sizeof(partialResult));    // write sum to pipe
			close(fds[i][1]);   //close write end of pipe
			return 0;
		}
	}

	// Parent waits for all children and collects results.
	int partialResult = 0;
	
	for (int i = 0; i < NUM_PROCESSES; i++) {
		int status;
		pid_t pid = wait(&status);
		if (WIFEXITED(status)) {
			read(fds[i][0], &partialResult, sizeof(partialResult)); //read from pipe
			total_sum += partialResult;				//add partial result to sum
			close(fds[i][0]);					//close pipe
		}
	}

	printf("Total sum: %d\n", total_sum);
	
	return 0;
>>>>>>> e0c1eeff3d9121ffb818b66797523d96462654b1
}
