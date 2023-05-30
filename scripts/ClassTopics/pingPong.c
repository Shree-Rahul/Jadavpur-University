#include <stdio.h>
#include <pthread.h>

int turn = 0; // Shared variable to keep track of the turn
pthread_mutex_t lock; // Mutex lock for synchronization

void *Ping(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock); // Acquire the lock

        if (turn == 0) {
            printf("ping\n");
            turn = 1; // Update the turn
        }

        pthread_mutex_unlock(&lock); // Release the lock
    }
}

void *Pong(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock); // Acquire the lock

        if (turn == 1) {
            printf("pong\n");
            turn = 0; // Update the turn
        }

        pthread_mutex_unlock(&lock); // Release the lock
    }
}

int main() {
    pthread_t pingThread, pongThread;

    pthread_mutex_init(&lock, NULL); // Initialize the mutex lock

    pthread_create(&pingThread, NULL, Ping, NULL);
    pthread_create(&pongThread, NULL, Pong, NULL);

    pthread_join(pingThread, NULL);
    pthread_join(pongThread, NULL);

    pthread_mutex_destroy(&lock); // Destroy the mutex lock

    return 0;
}
