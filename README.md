# POSIX 线程练习（pthread）

学习 Linux/POSIX 多线程编程时整理的九个小例子，包括：

- 线程创建与参数传递；
- 线程属性、`join` 与 `detach`；
- 互斥锁与信号量。

每个 `.c` 文件分别展示一个主题。Linux 下编译 pthread 示例通常需要 `-pthread` 选项，例如：

```bash
gcc 1_pthread_create.c -o pthread_demo -pthread
```

以上命令是参考用法，未在当前环境重新构建和测试所有示例。
