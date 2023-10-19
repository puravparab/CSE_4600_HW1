//pipe3.cpp
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	if (argc != 3) {
		std::cerr << "Missing inputs." << std::endl;
		return 1;
	}

	// Parse inputs
	int input_1 = stoi(argv[1]);
	int input_2 = stoi(argv[2]);
	int sum = input_1 + input_2;

	int nbytes;
	int fd[2]; //file descriptors for pipe
	char s[40];
	snprintf(s, sizeof(s), "%d", sum);

	char buffer[BUFSIZ+1];
	memset (buffer, 0, sizeof(buffer)); //clear buffer

	if (pipe(fd) == 0) { //create a pipe
		write(fd[1], s, strlen(s)); //send data to pipe
		cout << "Sent the numbers " << input_1 << " and " << input_2 << " to pipe for their summation." << endl;
		read (fd[0], buffer, BUFSIZ); //read data from pipe
		cout << "The sum of the two numbers is: " << buffer << endl;
		return 0;
	}
	
	return 1;
}
