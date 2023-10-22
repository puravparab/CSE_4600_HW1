/*
  pthreads_message_demo.cpp
  A very simple example demonstrating the usage of pthreads.
  Compile: g++ -o pthreads_message _demo pthreads_demo.cpp -lpthread
  Execute: ./pthreads_message _demo
*/

#include<iostream>
#include<pthread.h>
#include <stdlib.h>
#include<cstring>
#include<string>

void *thread_func(void *arg) {
  char *message = (char *) arg;
  strcpy(message, "You are in thread function!\n");
  return NULL;
}

int main() {
  char *message = (char*)malloc(100);
  strcpy(message, "You are in the main function!\n");
  pthread_t tid1;
  pthread_create(&tid1, NULL, &thread_func, message);

  pthread_join(tid1, NULL);
  printf("%s", message);
  
  return 0;
}
