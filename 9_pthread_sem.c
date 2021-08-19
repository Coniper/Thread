#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<pthread.h>

#include <semaphore.h>

int i = 0;

sem_t sem;
sem_t sem1;

void * func1(void * arg)
{
	int n = 100;
	printf("this is thread1\n");
	while(n--)
	{
		sem_wait(&sem1);	
		i++;
		sem_post(&sem);
	}

}

void * func2(void * arg)
{
	int n = 100;

	printf("this is thread2 \n");
	while(n--)
	{
		sem_wait(&sem);
		printf("i = %d\n", i);
		sem_post(&sem1);
	}
}

int
main(int argc, char *argv[])
{
	//初始化信号量
	sem_init(&sem, 0, 0);
	sem_init(&sem1, 0, 1);

	pthread_t tid1, tid2, tid3;

	if(0 != pthread_create(&tid1, NULL, func1, NULL))
	{
		perror("pthread_create thread 1");
		return -1;
	}
	if(0 != pthread_detach(tid1))
	{
		perror("pthread detach thread 1");
		return -1;
	}
	
	if(0 != pthread_create(&tid2, NULL, func2, NULL))
	{
		perror("pthread_create thread 2");
		return -1;
	}

	if(0 != pthread_detach(tid2))
	{
		perror("pthread_detach thread 2");
		return -1;
	}

	while(1);

    return 0;
}
