/*A -> B -> C -> C -> A ->B->|
  <---------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>

int turn=0;
sem_t semA, semB, semC;
void* P1() {
    while (1) {
        sem_wait(&semA);
        printf("A");
        sem_post(&semB);
    }
}

void* P2() {
    while (1) {
        if(turn == 40){
            exit(0);
        }
        sem_wait(&semB);
        printf("B");
        turn++; // 1 4
        if(turn%2==0)
            sem_post(&semA);
        else
            sem_post(&semC);//tirgger
    }
}

void* P3() {
    while (1) {
        if(turn == 40){
            exit(0);
        }
        sem_wait(&semC);
        printf("C");
        turn++;//2 3 
        if(turn%2==0)
            sem_post(&semC);
        else
            sem_post(&semA);
    }
}

int main() {
    // Initialize the semaphores
    sem_init(&semA, 0, 1);
    sem_init(&semB, 0, 0);
    sem_init(&semC, 0, 0);



    pid_t pa,pb,pc;
    pa = fork();
    if(fork<0){
        
    }




    // pthread_t PA,PB,PC;

    // pthread_create(&PA,NULL,P1,NULL);
    // pthread_create(&PB,NULL,P2,NULL);
    // pthread_create(&PC,NULL,P3,NULL);


    // pthread_join(PA,NULL);
    // pthread_join(PB,NULL);
    // pthread_join(PB,NULL);

    // Destroy the semaphores
    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);

    return 0;
}