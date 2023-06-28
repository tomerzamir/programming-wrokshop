#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };

int semid;
union semun semarg;

void main()
{
       int i;
       struct sembuf sops[1];

       semid=semget ( IPC_PRIVATE , 1 , 0600 );
       semarg.val=1;
       semctl ( semid , 0 , SETVAL , semarg );
       sops->sem_num = 0;
       sops->sem_flg = 0;
       if ( fork()==0 ) {
             sops->sem_op = -1;
             semop ( semid , sops , 1 );
             printf ("now you are locked\n");
             sleep( 5 );
             sops->sem_op = 1;
             semop ( semid , sops , 1 );
             printf("son finished\n");
       }
       else {
             sleep( 1 );
             printf("waiting for son to release semaphore\n");
             sops->sem_op = -1;
             semop ( semid , sops , 1 );
             printf("father finished\n");
             semctl ( semid , 0 , IPC_RMID , semarg );
       }
}
