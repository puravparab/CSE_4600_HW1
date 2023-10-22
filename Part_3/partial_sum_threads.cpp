//partial_sum_threads.cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 48
#define NUM_THREADS 4

int array[SIZE];
int segment_size = SIZE / NUM_THREADS;
int totalSum = 0;
pthread_mutex_t totalSumMutex; 


void* partial_sum(void* arg) {
    int threadnum = *((int*)arg);
    int start = threadnum * segment_size;
    int end = start + segment_size;
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += array[i];
    }
    printf("Partial sum: %d\n", sum);
    // Lock mutex to update totalSum
    pthread_mutex_lock(&totalSumMutex);
    totalSum += sum;
    // Unlock mutex after updating
    pthread_mutex_unlock(&totalSumMutex);
    pthread_exit(0);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadNumbers[NUM_THREADS];
    
    // Fill the array with numbers from 1 to 160.
    for (int i = 0; i < SIZE; i++) {
        array[i] = i + 1;
    }

    // Create loop for the threads
    for (int i = 0; i < NUM_THREADS; i++) {
    	threadNumbers[i] = i; // Store the thread number
        pthread_create(&threads[i], NULL, partial_sum, (void*)&threadNumbers[i]);
    }

    // Wait for threads to exit
    for (int i = 0; i < NUM_THREADS; i++) {
    	pthread_join (threads[i], NULL);
    }

    printf("Total sum: %d\n", totalSum);
    
    return 0;
}
