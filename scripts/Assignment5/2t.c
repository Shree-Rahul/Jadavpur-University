#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

sem_t semA,semB,semC;
void *printA(void *arr)
{
    int *ar =(int *)arr;
    while(true)
    {
        if(ar[1]==20)
        {
            exit(0);
        }
        sem_wait(&semA);
        printf("A");
        ar[1]++;
        sem_post(&semB);
    }
}
void *printB(void *arr)
{
    int *ar =(int *)arr;
    while(true)
    {
        sem_wait(&semB);
        printf("B");
        if(ar[0]%2==1)
        {
            ar[0]=0;
            printf("\n");
            sem_post(&semA);
        }
        else
        {
            sem_post(&semC);
        }
    }
}
void *printC(void *arr)
{
    int *ar =(int *)arr;
    while(true)
    {
        sem_wait(&semC);
        printf("C");
        if((ar[0]%2)==0)
        {
            (ar[0])++;
            sem_post(&semC);
        }
        else if((ar[0]%2)==1)
            sem_post(&semA);
    }
}
int main()
{
    pthread_t TA,TB,TC;
    int arr[2];
    arr[0]=0;
    arr[1]=0;
    sem_init(&semA,0,1);
    sem_init(&semB,0,0);
    sem_init(&semC,0,0);
    pthread_create(&TA,NULL,printA,(void*)arr);
    pthread_create(&TC,NULL,printB,(void*)arr);
    pthread_create(&TC,NULL,printC,(void*)arr);
    pthread_join(TA,NULL);
    pthread_join(TB,NULL);
    pthread_join(TC,NULL);
    return 0;
}