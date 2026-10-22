# Thread

这几个文件专门用来练 `pthread`。

从创建线程、传参、属性、`join`、`detach`，一直写到互斥锁和信号量。每个例子单独一个 `.c` 文件，方便编译和比较输出。

比如第一个：

```sh
gcc 1_pthread_create.c -pthread -o thread-demo
./thread-demo
```

并发程序跑通一次不代表没问题；这里保留的是当时的实验版本。
