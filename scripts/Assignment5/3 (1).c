#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "sema.h"
#define BUFFER_SIZE 10

int main() {
  // Create a semaphore set with two semaphores: one for the producer and one for the consumer.
  int mutex,empty,full,shmid;
  char *buffer;
  mutex=semGet(256,1);

    shmid=shmget(2022,28,IPC_CREAT|0666);
    buffer=shmat(shmid,NULL,0);
    mutex=semGet(256,1);
    empty=semGet(257,1);
    full=semGet(258,1);
    setVal(mutex,0,1);
    setVal(empty,0,BUFFER_SIZE);
    setVal(full,0,0);
  // Initialize the producer semaphore to 0 and the consumer semaphore to BUFFER_SIZE.
  

  // Create a producer thread and a consumer thread.
  pid_t producer_pid = fork();
  if (producer_pid == 0) {
    // Producer thread
    while (1) {
      // Wait for the consumer semaphore to be greater than 0.
      int item = rand() % 100;
      Wait(empty,0);
      Wait(mutex,0);
      // Produce an item.
      sprintf(buffer+4+full*4,"%d",item);
      printf("Producer produced item %d\n", item);

      // Increment the producer semaphore.
      Signal(mutex,0);
      Signal(full,0);
    }
  } else {
    // Consumer thread
    while (1) {
      // Wait for the producer semaphore to be greater than 0.
      Wait(full,0);
      Wait(mutex,0);
      int item;
      // Consume an item.
      sscanf(buffer+4+full*4,"%d",&item);
  	
      printf("Consumer consumed item %d\n", item);

      // Decrement the consumer semaphore.
      Signal(mutex,0);
      Signal(empty,0);
    }
  }
  removeSem(mutex);
  removeSem(empty);
  removeSem(full);
  return 0;
}
