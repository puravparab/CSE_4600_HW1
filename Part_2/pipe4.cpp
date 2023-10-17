#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Missing input string. Please provide the input string when running the executable" << std::endl;
        return 1;
    }

    const char *toConcatenate = "! Welcome to CSE 4600 Operating Systems course";
    int fd[2];

    if (pipe(fd) == -1) {
        std::cerr << "Pipe failed" << std::endl;
        return 1;
    }

    pid_t p = fork();

    if (p < 0) {
        std::cerr << "fork failed" << std::endl;
        return 1;
    } else if (p == 0) { 
        close(fd[1]);  

        char buffer[1024];
        read(fd[0], buffer, sizeof(buffer));

        std::cout << buffer << toConcatenate << std::endl;

        close(fd[0]);  
    } else { 
        close(fd[0]);  

        write(fd[1], argv[1], strlen(argv[1]));

        close(fd[1]);  

        wait(NULL);  
    }
    return 0;
}
