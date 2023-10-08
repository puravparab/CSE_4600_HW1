//test_signal.cpp
#include <signal.h>
#include <unistd.h>
#include <iostream>
using namespace std;
void func (int sig){
	cout << "Received a signal from your program " << sig << endl;
	if(sig == SIGQUIT){
	exit(0);
	}
}
int main(){
	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = func;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	
	cout << "Press Ctrl+C for SIGINT. Press ^\\ (Ctrl+\\) to quit." << endl;
	
	while(1) {
	cout << "CSUSB CSE 4600 Operating Systems Fall 2023" << endl;
	sleep(1);
	}

	return 0;
}
