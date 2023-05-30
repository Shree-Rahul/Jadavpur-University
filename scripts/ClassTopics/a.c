#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphoreA, semaphoreB, semaphoreC;

void *P1(void *arg) {
    while (1) {
        sem_wait(&semaphoreA); // Wait for semaphoreA to be available
        printf("A");
        sem_post(&semaphoreB); // Signal semaphoreB to allow P2 to execute
    }
}

void *P2(void *arg) {
    while (1) {
        sem_wait(&semaphoreB); // Wait for semaphoreB to be available
        printf("B");
        sem_post(&semaphoreC); // Signal semaphoreC to allow P3 to execute
    }
}

void *P3(void *arg) {
    while (1) {
        sem_wait(&semaphoreC); // Wait for semaphoreC to be available
        printf("C\n");
        sem_post(&semaphoreA); // Signal semaphoreA to allow P1 to execute
    }
}

int main() {
    pthread_t p1Thread, p2Thread, p3Thread;

    sem_init(&semaphoreA, 0, 1); // Initialize semaphoreA with initial value 1
    sem_init(&semaphoreB, 0, 0); // Initialize semaphoreB with initial value 0
    sem_init(&semaphoreC, 0, 0); // Initialize semaphoreC with initial value 0

    pthread_create(&p1Thread, NULL, P1, NULL);
    pthread_create(&p2Thread, NULL, P2, NULL);
    pthread_create(&p3Thread, NULL, P3, NULL);

    pthread_join(p1Thread, NULL);
    pthread_join(p2Thread, NULL);
    pthread_join(p3Thread, NULL);

    sem_destroy(&semaphoreA); // Destroy semaphoreA
    sem_destroy(&semaphoreB); // Destroy semaphoreB
    sem_destroy(&semaphoreC); // Destroy semaphoreC

    return 0;
}
