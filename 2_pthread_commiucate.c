#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<pthread.h>

int i = 0;

int flag = 0;

void * func1(void * arg)
{
	printf("this is thread1\n");
	while(1)
	{
		if(flag == 0)
		{
			i++;
			flag = 1;
		}
	}

}

void * func2(void * arg)
{
	printf("this is thread2 \n");
	while(1)
	{
		if(flag == 1)
		{
			printf("i = %d\n", i);
			flag = 0;
		}
	}
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
