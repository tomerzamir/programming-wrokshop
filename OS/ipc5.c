#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMOFSEM 3

union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };

void main()
{
        int semid,value,i;
        union semun semarg,semarg1;

        semid=semget ( IPC_PRIVATE , NUMOFSEM , 0600 );
        semarg.array=( short * ) malloc ( NUMOFSEM*sizeof ( short ) );
        semarg1.array=( short * ) malloc ( NUMOFSEM*sizeof ( short ) );
        for ( i=0 ; i<NUMOFSEM ; i++ )
              semarg.array[i]=1;
        semctl ( semid , 0 , SETALL , semarg );
        semctl ( semid , 0 , GETALL , semarg1 );
        for ( i=0 ; i<NUMOFSEM ; i++ )
              printf ( "semaphore %d: %d\n" , i , semarg1.array[i]);
        semarg.val=0;
        semctl ( semid , 0 , SETVAL , semarg );
        value=semctl ( semid , 0 , GETVAL , semarg );
        printf ( "\nsemaphore 0: %d\n" , value );
}
