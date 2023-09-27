//test_exec.cpp
#include <unistd.h>
#include <iostream>
using namespace std;
int main(){
	cout << "Running ps with execlp\n";
	execlp ("ps", "ps", "-ax", 0);
	cout << "The program is exiting!\n";

	return 0;
}