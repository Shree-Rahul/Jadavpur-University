#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

#define SEMKEY 150
#define PERM 0666

union semun{
int val;
struct semid_ds *buf;
ushort *array;
};

int semGet(key_t semkey, int mem_no){
    int semid;

    if((semid=semget(semkey, mem_no, IPC_CREAT|PERM))==-1)
    {
        //printf("\ncan't get semaphore (key = %d)",SEMKEY);
        //fflush(stdout);
    }
    else
    {
        //printf("\ngot semaphore successfully (id = %d)",semid);
        //fflush(stdout);
    }
    return(semid);
}


int removeSem(int semid){
    int retval;

    if((retval=semctl(semid, 0, IPC_RMID, 0))==-1)
    {
        //printf("\ncan't remove semaphore");
        //fflush(stdout);
    }
    else
    {
        //printf("\nsemaphore (id = %d) removed successfully",semid);
        //fflush(stdout);
    }
    return(retval);
}


int setVal(int semid, int semnum, int semval){
    int retval;
    union semun arg;

    arg.val=semval;
    if((retval=semctl(semid, semnum, SETVAL, arg))==-1)
    {
        /*
        printf("\ncan't set %dth memeber of semaphore set (id = %d) 
                           to %d",semnum, semid, semval);
        fflush(stdout);
        */
    }
    else
    {
        /*
        printf("\nset %dth memeber of semaphore set (id = %d) to %d",
                                     semnum, semid, semval);
        fflush(stdout);
        */
    }
    return(retval);
}



int getVal(int semid, int semnum)
{
    int retval;
    union semun arg;
    if((retval=semctl(semid, semnum, GETVAL, 0))==-1)
    {
        /*
        printf("\ncan't get value of %dth member of semaphore set 
                                          (id = %d)", semnum, semid);
        fflush(stdout);
        */
    }
    else
    {
        /*
        printf("\nvalue of %dth member of semaphore set (
                             id = %d) = %d", semnum, semid, retval);
        fflush(stdout);
        */
    }
    return(retval);
}



void Wait(int semid, int semnum)
{
    struct sembuf semoparray[1];

    semoparray[0].sem_num=semnum;
    semoparray[0].sem_op=-1;
    semoparray[0].sem_flg=0;

    semop(semid, semoparray, 1);
}



void Signal(int semid, int semnum)
{
    struct sembuf semoparray[1];

    semoparray[0].sem_num=semnum;
    semoparray[0].sem_op=1;
    semoparray[0].sem_flg=0;

    semop(semid, semoparray, 1);
}