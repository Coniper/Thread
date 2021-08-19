#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<pthread.h>

struct test {
	int i;
};

void * thread_func1(void * arg)
{
	//int i = (int)arg;
	//struct test t1 = *(struct test *)arg;
	//printf("t1.i = %d\n", t1.i);

	while(1)
	{
		printf("play game\n");
		sleep(1);
	}
}

void * thread_func2(void * arg)
{
	while(1)
	{
		printf("study\n");
		sleep(1);
	}
}

int
main(int argc, char *argv[])
{
	struct test t1;
	t1.i = 666;
	int i = 999;

	pthread_t tid1, tid2;

	//if(0 != pthread_create(&tid1, NULL, pthread_func1, (void *)&t1 ))
	if(0 != pthread_create(&tid1, NULL, thread_func1, NULL ))
	{
		perror("thread1 create failed");
		return -1;
	}

	if(0 != pthread_create(&tid2, NULL, thread_func2, NULL))
	{
		perror("thread1 create failed");
		return -1;
	}

	while(1);//主线程不能先与子线程退出
	return 0;
}
