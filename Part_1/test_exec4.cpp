//test_exec4.cpp
#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
	cout << "Removes test.txt file\n";
	execlp("/bin/rm", "rm", "test.txt", NULL);
	cout << "The program is exiting!\n";
	return 0;
}
