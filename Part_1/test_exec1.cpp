//test_exec1.cpp
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
	cout << "List file in current directory in long format\n";
	execlp("/bin/ls", "ls", "-l", NULL);
	cout << "The program is exiting!\n";
	return 0;
}

