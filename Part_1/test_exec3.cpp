//test_exec3.cpp
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
	cout << "Displays the content of test_exec.cpp file\n";
	execlp("/bin/cat", "cat", "test_exec.cpp", NULL);
	cout << "The program is exiting!\n";
	return 0;
}
