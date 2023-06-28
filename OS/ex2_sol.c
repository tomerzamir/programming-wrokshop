#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define bool int
#define true 1
#define false 0

union semun
{
	int val;
	struct semid_ds* buf;
	unsigned short* array;
	struct seminfo* __buf;
};

int semid;
union semun arg;

int allocate_sems()
{
	if ((semid = semget(IPC_PRIVATE, 6, 0666 | IPC_CREAT)) == -1)
	{
		perror("semget");
		exit(1);
	}
}

int deallocate_sem()
{
	if (semctl(semid, 0, IPC_RMID, arg) == -1)
	{
		perror("semctl");
		exit(-1);
	}
}

int init_sems()
{
	for (int i = 1; i < 6; i++)
	{
		arg.val = 5 - i;
		if (semctl(semid, i, SETVAL, arg) == -1)
		{
			perror("semctlX");
			exit(1);
		}
	}
}

void change_sem(int semnum, int val)
{
	struct sembuf sops;
	sops.sem_num = semnum;
	sops.sem_op = val;
	sops.sem_flg = 0;
	semop(semid, &sops, 1);
}

int next_step(int semnum)
{
	for (int i = 1; i < 6; ++i)
		if (i != semnum)
			change_sem(i, 1);
}

int process(int semnum)
{
	int j = semnum;
	while (j <= 100)
	{
		change_sem(semnum, -4);
		printf("%d\n", j);
		next_step(semnum);
		j += 5;
	}
	//if (semnum == 5)
	//	deallocate_sem();
	//exit(1);
}

int main(int argc, char* argv[])
{
	allocate_sems();
	init_sems();
	for (int i = 1; i <= 4; i++)
	{
		if (!(fork()))
		{
			process(i);
			exit(1);
		}
	}
	process(5);
	deallocate_sem();
}