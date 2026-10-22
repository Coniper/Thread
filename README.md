# pthread 练习

九个 C 文件，练的是 POSIX 线程的基本操作：创建线程、传参、线程属性、`join`、`detach`，以及互斥锁、信号量。

我没有把它们拼成一个大项目。线程的问题往往要靠运行结果和执行顺序去理解，独立的小程序反而比较容易观察。

在 Linux 上可以先拿第一个例子试试：

```bash
gcc 1_pthread_create.c -o pthread_demo -pthread
./pthread_demo
```

这是给自己留的实验代码。并发行为会受环境影响，不能因为运行几次正常就认为线程安全。
