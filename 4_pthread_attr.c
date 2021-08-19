#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<pthread.h>

void * func(void *arg)
{
	printf("this is thread\n");
}

int
main(int argc, char *argv[])
{
	pthread_attr_t attr;
	
	if(0 != pthread_attr_init(&attr))
	{
		perror("pthread_attr_init");
		return -1;
	}

	//设置线程创建的分离属性
	if(0 != pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED))
	{
		perror("pthread_attr_setdetachstate");
		return -1;
	}

	pthread_t tid;

	if(0 != pthread_create(&tid, &attr, func, NULL))
	{
		perror("pthread_create");
		return -1;
	}

	printf("hello world\n");

	sleep(3);
    return 0;
}
