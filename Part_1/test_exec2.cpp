//test_exec2.cpp
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
	cout << "Prints message to console\n";
	execlp("/bin/echo", "echo", "Hello from CSUSB CSE 4600 Section 03 Fall 2023",  NULL);
	cout << "The program is exiting!\n";
	return 0;
}
