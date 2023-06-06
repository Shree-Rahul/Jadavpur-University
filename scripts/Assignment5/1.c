#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>

int main()
{
    int shmid;
    int key=220;
    int status,max,min,sum;
    float avg;
    char *buffer;
    if((shmid=shmget(key, 420, IPC_CREAT | 0666))==-1)
    {
        printf("\nCannot create shared memory segment");
        exit(0);
    }
    buffer = shmat(shmid,NULL,0);
    int turn=0;
    sprintf(buffer,"%d",turn);
    if(fork()!=0)
    {
        while(turn!=0)
            sscanf(buffer, "%d", &turn);
        printf("\nGenerate 100 random numbers:\n");
        srand(time(0));
        for(int i=1;i<=100;i++)
        {
            int temp=rand()%1000;
            printf("%d ",temp);
            sprintf(buffer+(4*i),"%d",temp);
        }
        fflush(stdout);
        turn=1;
        sprintf(buffer,"%d",turn);
        while(turn!=0)
            sscanf(buffer,"%d",&turn);
        sscanf(buffer+4*(101),"%d",&max);
        sscanf(buffer+4*(102),"%d",&min);
        sscanf(buffer+4*(103),"%f",&avg);
        sleep(1);
        printf("\nMax = %d\nMin = %d\nAverage = %.2f\n",max,min,avg);
        printf("Parent terminates\n");
    }
    else
    {
        while(turn!=1)
            sscanf(buffer,"%d",&turn);
        int val;
        printf("\nChild Begins\n");
        sscanf(buffer+4,"%d",&val);
        max=min=sum=val;
        for(int i=2;i<=100;i++)
        {
            sscanf(buffer+(4*i),"%d",&val);
            if(val>max)
                max=val;
            if(val<min)
                min=val;
            sum+=val;
        }
        avg=(float)sum/100.0;
        sprintf(buffer+(4*101),"%d",max);
        sprintf(buffer+(4*102),"%d",min);
        sprintf(buffer+(4*103),"%.2f",avg);
        turn=0;
        sprintf(buffer,"%d",turn);
        printf("\nChild Terminates\n");
    }
    shmdt(buffer);
    return 0;
}