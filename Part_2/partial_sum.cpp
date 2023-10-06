// partial_sum.cpp
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 20
#define NUM_PROCESSES 4

int array[SIZE];
int partial_sum(int start, int end) {
	int sum = 0;
	for (int i = start; i < end; i++) {
		sum += array[i];
	}
	return sum;
}

int main() {
	// Fill the array with numbers from 1 to 160.
	for (int i = 0; i < SIZE; i++) {
		array[i] = i + 1;
	}

	int segment_size = SIZE / NUM_PROCESSES;
	int total_sum = 0;

	for (int i = 0; i < NUM_PROCESSES; i++) {
		pid_t pid = fork();
		if (pid < 0) {
			perror("Fork failed");
			return 1;
		} else if (pid == 0) { // Child process
			int start = i * segment_size;
			int end = start + segment_size;
			int partialResult = partial_sum(start, end);
			printf("Partial sum is: %d", partialResult);
			return partialResult; // Return the result or 255 if it exceeds the range.
		}
	}

	// Parent waits for all children and collects results.
	for (int i = 0; i < NUM_PROCESSES; i++) {
		int status;
		pid_t pid = wait(&status);
		if (WIFEXITED(status)) {
			total_sum += WEXITSTATUS(status);
		}
	}

	printf("Total sum: %d\n", total_sum);
	
	return 0;
}