// pipe4.cpp
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Missing input string. Please provide the input string when
		running the executable" << std::endl;
		return 1;
	}
	const char *toConcatenate = "! Welcome to CSE 4600 Operating Systems course";

	int fd[2];
	if (pipe(fd) == -1) {
		std::cerr << "Pipe failed" << std::endl;
		return 1;
	}
	// Create a child process to read from the pipe
	// YOUR CODE HERE

	// Here check for below
	// 1. if this is a child process then read the input string from the pipe created by parent process
	// 2. If this is a parent process, then write the input string to the pipe and wait for the child to finish

	// YOUR CODE HERE
	return 0;
}