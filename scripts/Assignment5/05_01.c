#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10
#define NUM_ITEMS 100

int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer

sem_t mutex;   // Semaphore for mutual exclusion
sem_t full;    // Semaphore to track the number of full slots in the buffer
sem_t empty;   // Semaphore to track the number of empty slots in the buffer

void* producer(void* arg) {
    int item = 1; // Item to be produced

    for (int i = 0; i < NUM_ITEMS; i++) {
        // Wait if the buffer is full
        sem_wait(&empty);

        // Acquire the mutex to access the buffer
        sem_wait(&mutex);

        // Produce an item and add it to the buffer
        buffer[count++] = item++;
        printf("Produced item: %d\n", item-1);

        // Release the mutex
        sem_post(&mutex);

        // Signal that a new item is available in the buffer
        sem_post(&full);
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        // Wait if the buffer is empty
        sem_wait(&full);

        // Acquire the mutex to access the buffer
        sem_wait(&mutex);

        // Consume an item from the buffer
        int item = buffer[--count];
        printf("Consumed item: %d\n", item);

        // Release the mutex
        sem_post(&mutex);

        // Signal that an empty slot is available in the buffer
        sem_post(&empty);
    }

    pthread_exit(NULL);
}

int main() {
    // Initialize the semaphores
    sem_init(&mutex, 0, 1);   // Mutex is initialized to 1 for mutual exclusion
    sem_init(&full, 0, 0);    // Full is initialized to 0, as there are no items initially
    sem_init(&empty, 0, BUFFER_SIZE); // Empty is initialized to the buffer size

    // Create producer and consumer threads
    pthread_t producerThread, consumerThread;
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy the semaphores
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}