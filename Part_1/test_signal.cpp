//test_signal.cpp
#include <signal.h>
#include <unistd.h>
#include <iostream>
using namespace std;
void func (int sig){
	cout << "Received a signal from your program " << sig << endl;
}
int main(){
	(void) signal (SIGINT, func);//catch terminal interrupts
	
	for (int i = 0; i < 20; ++i) {
		cout << "CSUSB CSE 4600 Operating Systems Fall 2023" << endl;
		sleep (1);
	}

	return 0;
}