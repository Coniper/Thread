#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>

FILE * fd;

pthread_mutex_t mt;
void * 
write1(void * arg)
{
	int i = 0;
	char *buf = "hello world\n";
	int len = strlen(buf);

	while(1) {	
		printf("this is write1 \n");
#if 1
		pthread_mutex_lock(&mt);
		for(i = 0; i < len; i++)
		{
			fputc(*(buf+i), fd);
			fflush(fd);
			usleep(50000);
		}
		pthread_mutex_unlock(&mt);
#endif
		sleep(1);
	}
}
void * 
write2(void * arg)
{
	int i;
	char *buf = "nihao\n";
	int len = strlen(buf);

	while(1) {
		printf("this is write2 \n");
#if 1
		pthread_mutex_lock(&mt);
		for(i = 0; i < len; i++)
		{
			fputc(*(buf+i), fd);
			fflush(fd);
			usleep(50000);
		}
		pthread_mutex_unlock(&mt);
#endif
		sleep(1);
	}
}

int
main(int argc, char *argv[])
{
	pthread_t tid1, tid2;

	fd = fopen("./mutex.txt", "w");
	if(fd == NULL)
		return -1;

	pthread_mutex_init(&mt, NULL);

	if(0 != pthread_create(&tid1, NULL, write1, NULL)) {
		perror("pthread_create 1 ");
		return -1;
	}
//	pthread_detach(tid1);

	if(0 != pthread_create(&tid2, NULL, write2, NULL)) {
		perror("pthread_create 2 ");
		return -1;
	}
//	pthread_detach(tid2);

	while(1)
		sleep(1);

    return 0;
}
