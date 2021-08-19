#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<unistd.h>
#include<pthread.h>

void * func1(void * arg)
{
	printf("this is thread1\n");
	//sleep(1);

	//pthread_exit("thread 1 quit");
}

void * func2(void * arg)
{
	printf("this is thread2 \n");
	//sleep(1);

	//pthread_exit("thread 2 quit");
}

int
main(int argc, char *argv[])
{
	pthread_t tid1, tid2;

	if(0 != pthread_create(&tid1, NULL, func1, NULL))
	{
		perror("pthread_create");
		return -1;
	}

	//回收线程
#if 0
	char * ret;
	if(0 != pthread_join(tid1, (void **)&ret))
	{
		perror("pthread_join");
		return -1;
	}
	printf("ret = %s\n", ret);
#endif
	if(0 != pthread_create(&tid2, NULL, func2, NULL))
	{
		perror("pthread_create");
		return -1;
	}
#if 0
	//回收线程
	if(0 != pthread_join(tid2, (void **)&ret))
	{
		perror("pthread_join");
		return -1;
	}
	printf("ret = %s\n", ret);
#endif
	sleep(5);
    return 0;
}
