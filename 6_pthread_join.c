#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<pthread.h>

void * func1(void * arg)
{
	printf("this is thread1\n");
}

void * func2(void * arg)
{
	printf("this is thread2 \n");
}

void * func3(void * arg)
{
	printf("this is thread3 \n");
}

int
main(int argc, char *argv[])
{
	pthread_t tid1, tid2, tid3;

	if(0 != pthread_create(&tid1, NULL, func1, NULL))
	{
		perror("pthread_create thread 1");
		return -1;
	}
	pthread_join(tid1, NULL);
	

	if(0 != pthread_create(&tid2, NULL, func2, NULL))
	{
		perror("pthread_create thread 2");
		return -1;
	}
	pthread_join(tid2, NULL);

	if(0 != pthread_create(&tid3, NULL, func3, NULL))
	{
		perror("pthread_create thread 3");
		return -1;
	}
	pthread_join(tid3, NULL);

	

	sleep(2);
    return 0;
}
