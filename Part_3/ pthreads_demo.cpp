/*
	pthreads_demo.cpp
	A very simple example demonstrating the usage of pthreads.
	Compile: g++ -o pthreads_demo pthreads_demo.cpp -lpthread
	Execute: ./pthreads_demo
*/

#include <iostream>
#include <pthread.h>

int N = 10;

// First thread to compute the sum of the first N natural numbers
void* numbers_sum(void* arg) {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += i;
	}
	std::cout << "Sum of the numbers from 1 to " << N << ": " << sum << std::endl;
	pthread_exit (0);
	return NULL;
}

// Second thread to compute the product of the the first N natural numbers
void* numbers_product(void* arg) {
	int product = 1;
	for (int i = 1; i <= N; i++) {
		product *= i;
	}
	std::cout << "Product of the numbers from 1 to " << N << ": " << product << std::endl;
	pthread_exit (0);
	return NULL;
}

int main() {
	pthread_t id1, id2; //thread identifiers
	pthread_attr_t attr1, attr2; //set of thread attributes
	const char *tnames[2] = { "Sum Thread", "Product Thread" }; //names of threads

	//get the default attributes
	pthread_attr_init (&attr1);
	pthread_attr_init (&attr2);

	//create the threads
	pthread_create (&id1, &attr1, numbers_sum, (void *)tnames[0]);
	pthread_create (&id2, &attr2, numbers_product, (void *)tnames[1]);

	//wait for the threads to exit
	pthread_join (id1, NULL);
	pthread_join (id2, NULL);
	return 0;
}
